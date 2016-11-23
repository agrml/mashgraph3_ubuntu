#include <iostream>
#include <vector>
#include <SOIL.h>
#include <GL/Texture.h>

#include "Utility.h"

using namespace std;

const uint GRASS_INSTANCES = 10; // Количество травинок

GL::Camera camera;
// Мы предоставляем Вам реализацию камеры. В OpenGL камера - это просто 2 матрицы.
// Модельно-видовая матрица и матрица проекции.
// ###
// Задача этого класса только в том чтобы обработать ввод с клавиатуры и правильно сформировать эти матрицы.
// Вы можете просто пользоваться этим классом для расчёта указанных матриц.


GLuint grassPointsCount; // Количество вершин у модели травинки
GLuint grassShader;      // Шейдер, рисующий траву
GLuint grassVAO;         // VAO для травы (что такое VAO почитайте в доках)
GLuint grassVariance;    // Буфер для смещения координат травинок
GLuint groundTexture;

vector<VM::vec4> grassVarianceData(GRASS_INSTANCES); // Вектор со смещениями для координат травинок

GLuint groundShader; // Шейдер для земли
GLuint groundVAO; // VAO для земли

// Размеры экрана
uint screenWidth = 800;
uint screenHeight = 600;

// Это для захвата мышки. Вам это не потребуется (это не значит, что нужно удалять эту строку)
bool captureMouse = true;

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

// Обновление смещения травинок
void UpdateGrassVariance() {
    // Генерация случайных смещений
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
        grassVarianceData[i].x = static_cast<float>(rand()) / RAND_MAX / 100;
        grassVarianceData[i].z = static_cast<float>(rand()) / RAND_MAX / 100;
    }

    // Привязываем буфер, содержащий смещения
    glBindBuffer(GL_ARRAY_BUFFER, grassVariance);
    CHECK_GL_ERRORS
    // Загружаем данные в видеопамять
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec4) * GRASS_INSTANCES, grassVarianceData.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS
    // Отвязываем буфер
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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

// Завершение программы
void FinishProgram() {
    glutDestroyWindow(glutGetWindow());
}

// Обработка события нажатия клавиши (специальные клавиши обрабатываются в функции SpecialButtons)
void KeyboardEvents(unsigned char key, int x, int y) {
    if (key == 27) {
        FinishProgram();
    } else if (key == 'w') {
        camera.goForward();
    } else if (key == 's') {
        camera.goBack();
    } else if (key == 'm') {
        captureMouse = !captureMouse;
        if (captureMouse) {
            glutWarpPointer(screenWidth / 2, screenHeight / 2);
            glutSetCursor(GLUT_CURSOR_NONE);
        } else {
            glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
        }
    }
}

// Обработка события нажатия специальных клавиш
void SpecialButtons(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        camera.rotateY(0.02);
    } else if (key == GLUT_KEY_LEFT) {
        camera.rotateY(-0.02);
    } else if (key == GLUT_KEY_UP) {
        camera.rotateTop(-0.02);
    } else if (key == GLUT_KEY_DOWN) {
        camera.rotateTop(0.02);
    }
}

void IdleFunc() {
    glutPostRedisplay();
}

// Обработка события движения мыши
void MouseMove(int x, int y) {
    if (captureMouse) {
        int centerX = screenWidth / 2,
            centerY = screenHeight / 2;
        if (x != centerX || y != centerY) {
            camera.rotateY((x - centerX) / 1000.0f);
            camera.rotateTop((y - centerY) / 1000.0f);
            glutWarpPointer(centerX, centerY);
        }
    }
}

// Обработка нажатия кнопки мыши
void MouseClick(int button, int state, int x, int y) {
}

// Событие изменение размера окна
void windowReshapeFunc(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    screenWidth = newWidth;
    screenHeight = newHeight;

    camera.screenRatio = static_cast<float>(screenWidth) / screenHeight;
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

// Генерация позиций травинок (эту функцию вам придётся переписать)
vector<VM::vec2> GenerateGrassPositions() {
    vector<VM::vec2> grassPositions(GRASS_INSTANCES);
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
//        grassPositions[i] = VM::vec2((i % 4) / 4.0, (i / 4) / 4.0) + VM::vec2(1, 1) / 8;
        grassPositions[i] = VM::vec2(static_cast<float>(rand()) / RAND_MAX,
                                     static_cast<float>(rand()) / RAND_MAX) /*+ VM::vec2(1, 1) / 8*/;
    }
    return grassPositions;
}

// Здесь вам нужно будет генерировать меш
vector<VM::vec4> GenMesh(uint n) {
    return {
            VM::vec4(0, 0, 0, 1),
            VM::vec4(1, 0, 0, 1),
            VM::vec4(0.5, 1, 0, 1),
    };
}

// Создание травы
void CreateGrass() {
    uint LOD = 1;
    // Создаём меш
    vector<VM::vec4> grassPoints = GenMesh(LOD);
    // Сохраняем количество вершин в меше травы
    grassPointsCount = grassPoints.size();
    // Создаём позиции для травинок
    vector<VM::vec2> grassPositions = GenerateGrassPositions();
    // Инициализация смещений для травинок
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
        grassVarianceData[i] = VM::vec4(0, 0, 0, 0);
    }

    /* Компилируем шейдеры
    Эта функция принимает на вход название шейдера 'shaderName',
    читает файлы shaders/{shaderName}.vert - вершинный шейдер
    и shaders/{shaderName}.frag - фрагментный шейдер,
    компилирует их и линкует.
    */
    grassShader = GL::CompileShaderProgram("grass");

//////////////////////////////////////////////////////////////
    // Здесь создаём буфер (VBO)
    GLuint pointsBuffer;
    // Это генерация одного буфера (в pointsBuffer хранится идентификатор буфера)
    glGenBuffers(1, &pointsBuffer);
    CHECK_GL_ERRORS
    // Привязываем сгенерированный буфер
    glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
    CHECK_GL_ERRORS
    // Заполняем буфер данными из вектора
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(VM::vec4) * grassPoints.size(),
                 grassPoints.data(),
                 GL_STATIC_DRAW);
    CHECK_GL_ERRORS

    // Создание VAO
    // Генерация VAO
    glGenVertexArrays(1, &grassVAO);
    CHECK_GL_ERRORS
    // Привязка VAO
    glBindVertexArray(grassVAO);
    CHECK_GL_ERRORS

    // Получение локации параметра 'point' в шейдере
    GLuint pointsLocation = glGetAttribLocation(grassShader, "point");
    CHECK_GL_ERRORS
    // Устанавливаем параметры для получения данных из массива атрибутов (по 4 значение типа float на одну вершину)
    // how do C binary data must be interpret in shader.
    // Here we describe layout in one portion to be sent [GPU RAM -> shader program] to the shader's one call. But we can send [RAM -> GPU RAM] an array of portions per one sending.
    glVertexAttribPointer(pointsLocation, // offset to start of corresponding GLSL's variable in `in` section
                          4, // quantity of attributes per vertex
                          GL_FLOAT, // how to interpret bytes
                          GL_FALSE, // do not normalize
                          0, // size of one portion; 0 -- auto
                          0); // offset of data
    CHECK_GL_ERRORS
    // Подключаем массив атрибутов к данной локации
    glEnableVertexAttribArray(pointsLocation);
    CHECK_GL_ERRORS
///////////////////////////////////////////////////////////////

    // Создаём буфер для позиций травинок
    GLuint positionBuffer;
    glGenBuffers(1, &positionBuffer);
    CHECK_GL_ERRORS
    // Здесь мы привязываем новый буфер, так что дальше вся работа будет с ним до следующего вызова glBindBuffer
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    CHECK_GL_ERRORS
    // binary send data to current buffer [RAM -> RAM]
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec2) * grassPositions.size(), grassPositions.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS

    GLuint positionLocation = glGetAttribLocation(grassShader, "position");
    CHECK_GL_ERRORS
    glEnableVertexAttribArray(positionLocation);
    CHECK_GL_ERRORS
    glVertexAttribPointer(positionLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
    CHECK_GL_ERRORS
    // Здесь мы указываем, что нужно брать новое значение из этого буфера для каждого инстанса (для каждой травинки)
    glVertexAttribDivisor(positionLocation, 1);
    CHECK_GL_ERRORS

    // Создаём буфер для смещения травинок
    glGenBuffers(1, &grassVariance);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, grassVariance);
    CHECK_GL_ERRORS
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec4) * GRASS_INSTANCES, grassVarianceData.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS

    GLuint varianceLocation = glGetAttribLocation(grassShader, "variance");
    CHECK_GL_ERRORS
    glEnableVertexAttribArray(varianceLocation);
    CHECK_GL_ERRORS
    glVertexAttribPointer(varianceLocation, 4, GL_FLOAT, GL_FALSE, 0, 0);
    CHECK_GL_ERRORS
    glVertexAttribDivisor(varianceLocation, 1);
    CHECK_GL_ERRORS

    // Отвязываем VAO
    glBindVertexArray(0);
    CHECK_GL_ERRORS
    // Отвязываем буфер
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}

// Создаём камеру (Если шаблонная камера вам не нравится, то можете переделать, но я бы не стал)
void CreateCamera() {
    camera.angle = 60.0f / 180.0f * M_PI;
    camera.direction = VM::vec3(0, 0.3, -1);
    camera.position = VM::vec3(0.5, 0.2, 0);
    camera.screenRatio = static_cast<float>(screenWidth) / screenHeight;
    camera.up = VM::vec3(0, 1, 0);
    camera.zfar = 50.0f;
    camera.znear = 0.05f;
}

// Создаём замлю
void CreateGround() {
    // Земля состоит из двух треугольников
    vector<VM::vec4> meshPoints = {
        VM::vec4(0, 0, 0, 1),
        VM::vec4(1, 0, 0, 1),
        VM::vec4(1, 0, 1, 1),
        VM::vec4(0, 0, 0, 1),
        VM::vec4(1, 0, 1, 1),
        VM::vec4(0, 0, 1, 1),
    };

    // Подробнее о том, как это работает читайте в функции CreateGrass

    groundShader = GL::CompileShaderProgram("ground");

    GLuint pointsBuffer;
    glGenBuffers(1, &pointsBuffer);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
    CHECK_GL_ERRORS
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec4) * meshPoints.size(), meshPoints.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS

    glGenVertexArrays(1, &groundVAO);
    CHECK_GL_ERRORS
    glBindVertexArray(groundVAO);
    CHECK_GL_ERRORS

    GLuint index = glGetAttribLocation(groundShader, "point");
    CHECK_GL_ERRORS
    glEnableVertexAttribArray(index);
    CHECK_GL_ERRORS
    glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, 0, 0);
    CHECK_GL_ERRORS

/////////////////////////////////////////////////////////////
    glGenTextures(1, &groundTexture);
    glBindTexture(GL_TEXTURE_2D, groundTexture);
    // Set the groundTexture wrapping/filtering options (on the currently bound groundTexture object) ...

    // Load and generate the groundTexture
    int width, height;
    unsigned char *image = SOIL_load_image("../Texture/ground.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Здесь создаём буфер (VBO)
    GLuint textureBuffer;
    // Это генерация одного буфера (в pointsBuffer хранится идентификатор буфера)
    glGenBuffers(1, &textureBuffer);
    CHECK_GL_ERRORS
    // Привязываем сгенерированный буфер
    glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
    CHECK_GL_ERRORS
    vector<VM::vec2> texturePoints = {
        VM::vec2(0, 0),
        VM::vec2(1, 0),
        VM::vec2(1, 1),
        VM::vec2(0, 0),
        VM::vec2(1, 1),
        VM::vec2(0, 1)
    };
    // Заполняем буфер данными из вектора
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(VM::vec2) * texturePoints.size(),
                 texturePoints.data(),
                 GL_STATIC_DRAW);
    CHECK_GL_ERRORS

    // Получение локации параметра 'point' в шейдере
    GLuint textureCoordsLocation = glGetAttribLocation(groundShader, "textureCoordVertexShader");
    CHECK_GL_ERRORS
    // Устанавливаем параметры для получения данных из массива атрибутов (по 4 значение типа float на одну вершину)
    // how do C binary data must be interpret in shader.
    // Here we describe layout in one portion to be sent [GPU RAM -> shader program] to the shader's one call. But we can send [RAM -> GPU RAM] an array of portions per one sending.
    glVertexAttribPointer(textureCoordsLocation, // offset to start of corresponding GLSL's variable in `in` section
                          2, // quantity of attributes per vertex
                          GL_FLOAT, // how to interpret bytes
                          GL_FALSE, // do not normalize
                          0, // size of one portion; 0 -- auto
                          0); // offset of data
    CHECK_GL_ERRORS
    // Подключаем массив атрибутов к данной локации
    glEnableVertexAttribArray(textureCoordsLocation);
    CHECK_GL_ERRORS
////////////////////////////////////////////////////////////////////

    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}

int main(int argc, char **argv)
{
    try {
        cout << "Start" << endl;
        InitializeGLUT(argc, argv);
        cout << "GLUT inited" << endl;
        glewInit();
        cout << "glew inited" << endl;
        CreateCamera();
        cout << "Camera created" << endl;
        CreateGrass();
        cout << "Grass created" << endl;
        CreateGround();
        cout << "Ground created" << endl;
        glutMainLoop();
    } catch (string s) {
        cout << s << endl;
    }
}
