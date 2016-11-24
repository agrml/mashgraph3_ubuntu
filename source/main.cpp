#include <iostream>
#include <vector>
#include <SOIL.h>
#include <GL/Texture.h>

#include "Utility.h"
#include "Funcs.h"
#include "Window.h"


const uint GRASS_INSTANCES = 10; // Количество травинок

// Размеры экрана
uint screenWidth = 800;
uint screenHeight = 600;

// Мы предоставляем Вам реализацию камеры. В OpenGL камера - это просто 2 матрицы.
// Модельно-видовая матрица и матрица проекции.
// ###
// Задача этого класса только в том чтобы обработать ввод с клавиатуры и правильно сформировать эти матрицы.
// Вы можете просто пользоваться этим классом для расчёта указанных матриц.
GL::Camera camera;

GLuint grassPointsCount; // Количество вершин у модели травинки
GLuint grassShader;      // Шейдер, рисующий траву
GLuint grassVAO;         // VAO для травы (что такое VAO почитайте в доках)
GLuint grassVariance;    // Буфер для смещения координат травинок

GLuint groundTexture;
GLuint groundShader; // Шейдер для земли
GLuint groundVAO; // VAO для земли


// Функция, рисующая замлю
void DrawGround() {
    // Используем шейдер для земли
    glUseProgram(groundShader);
    CHECK_GL_ERRORS

    // Устанавливаем юниформ для шейдера. В данном случае передадим перспективную матрицу камеры
    // Находим локацию юниформа 'camera' в шейдере
    GLint cameraLocation = glGetUniformLocation(groundShader, "camera");
    CHECK_GL_ERRORS
    // Устанавливаем юниформ (загружаем на GPU матрицу проекции?)
    glUniformMatrix4fv(cameraLocation, 1, GL_TRUE, camera.getMatrix().data().data());
    CHECK_GL_ERRORS

    // Подключаем VAO, который содержит буферы, необходимые для отрисовки земли
    glBindVertexArray(groundVAO);
    CHECK_GL_ERRORS

    // Рисуем землю: 2 треугольника (6 вершин)
    // note: befor this moment we haven't instruct OpenGL how to interpeate vertexes.
    glDrawArrays(GL_TRIANGLES, 0, 6);
    CHECK_GL_ERRORS

    GL::bindTexture(groundShader, "textureCoordFragmentShader", groundTexture);
    CHECK_GL_ERRORS

    // Отсоединяем VAO
    glBindVertexArray(0);
    CHECK_GL_ERRORS
    // Отключаем шейдер
    glUseProgram(0);
    CHECK_GL_ERRORS
}

// Рисование травы
void DrawGrass() {
    // Тут то же самое, что и в рисовании земли
    glUseProgram(grassShader);
    CHECK_GL_ERRORS
    GLint cameraLocation = glGetUniformLocation(grassShader, "camera");
    CHECK_GL_ERRORS
    glUniformMatrix4fv(cameraLocation, 1, GL_TRUE, camera.getMatrix().data().data());
    CHECK_GL_ERRORS
    glBindVertexArray(grassVAO);
    CHECK_GL_ERRORS

//    GLint vertexColorLocation = glGetUniformLocation(grassShader, "grassColor");
//    glUniform3f(vertexColorLocation,
//                static_cast<float>(rand()) / RAND_MAX,
//                static_cast<float>(rand()) / RAND_MAX,
//                static_cast<float>(rand()) / RAND_MAX);

    // Обновляем смещения для травы
    UpdateGrassVariance();
    // Отрисовка травинок в количестве GRASS_INSTANCES
    glDrawArraysInstanced(GL_TRIANGLES, 0, grassPointsCount, GRASS_INSTANCES);
    CHECK_GL_ERRORS
    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glUseProgram(0);
    CHECK_GL_ERRORS
}


// Создание травы
void CreateGrass() {
    /* Компилируем шейдеры
    Эта функция принимает на вход название шейдера 'shaderName',
    читает файлы shaders/{shaderName}.vert - вершинный шейдер
    и shaders/{shaderName}.frag - фрагментный шейдер,
    компилирует их и линкует.
    */
    grassShader = GL::CompileShaderProgram("grass");

    createGrassPoints();
    createGrassPositions();
    createGrassVariences();
    createGrassRotations();


    // Отвязываем VAO
    glBindVertexArray(0);
    CHECK_GL_ERRORS
    // Отвязываем буфер
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}

// Создаём замлю
void CreateGround() {
    groundShader = GL::CompileShaderProgram("ground");

    glGenVertexArrays(1, &groundVAO);
    CHECK_GL_ERRORS
    glBindVertexArray(groundVAO);
    CHECK_GL_ERRORS

    createGroundPoints();
    createGroundTexture();

    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}

// Эта функция вызывается для обновления экрана
void RenderLayouts() {
    // Включение буфера глубины
    glEnable(GL_DEPTH_TEST);
    // Очистка буфера глубины и цветового буфера
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Рисуем меши
    DrawGround();
    DrawGrass();
    glutSwapBuffers();
}

// Инициализация окна
void InitializeGLUT(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitContextVersion(3, 0);
    glutInitWindowPosition(200, 50);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Computer Graphics 3");
    glutWarpPointer(400, 300);
    glutSetCursor(GLUT_CURSOR_NONE);

    glutDisplayFunc(RenderLayouts);
    glutKeyboardFunc(KeyboardEvents);
    glutSpecialFunc(SpecialButtons);
    glutIdleFunc(IdleFunc);
    glutPassiveMotionFunc(MouseMove);
    glutMouseFunc(MouseClick);
    glutReshapeFunc(windowReshapeFunc);
}

int main(int argc, char **argv)
{
    try {
        std::cout << "Start" << std::endl;
        InitializeGLUT(argc, argv);
        std::cout << "GLUT inited" << std::endl;
        glewInit();
        std::cout << "glew inited" << std::endl;
        CreateCamera();
        std::cout << "Camera created" << std::endl;
        CreateGrass();
        std::cout << "Grass created" << std::endl;
        CreateGround();
        std::cout << "Ground created" << std::endl;
        glutMainLoop();
    } catch (std::string s) {
        std::cout << s << std::endl;
    }
}
