//
// Created by mikhail on 24.11.16.
//

#include <iostream>
#include <vector>
#include <SOIL.h>
#include <GL/Texture.h>

#include "Utility.h"
#include "Funcs.h"
#include "Graphics.h"
#include "Globals.h"
//#include "Mesh_.h"

#include "model.h"
#include "mesh.h"
#include "shader.h"

//Mesh_ *mesh;

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


    GL::bindTexture(groundShader, "groundTexture", groundTexture);
    CHECK_GL_ERRORS

        // Рисуем землю: 2 треугольника (6 вершин)
    // note: befor this moment we haven't instruct OpenGL how to interpeate vertexes.
    glDrawArrays(GL_TRIANGLES, 0, 6);
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

    // Обновляем смещения для травы
    UpdateGrassVariance();

    GL::bindTexture(grassShader, "grassTexture", grassTexture);
    CHECK_GL_ERRORS

        // Отрисовка травинок в количестве GRASS_INSTANCES
    glDrawArraysInstanced(GL_TRIANGLES, 0, grassPointsCount, GRASS_INSTANCES);
    CHECK_GL_ERRORS

    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glUseProgram(0);
    CHECK_GL_ERRORS
}

void DrawLake() {
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
    glBindVertexArray(lakeVAO);
    CHECK_GL_ERRORS

    GL::bindTexture(groundShader, "groundTexture", lakeTexture);
    CHECK_GL_ERRORS

    glDrawArrays(GL_TRIANGLES, 0, 6);
    CHECK_GL_ERRORS

    // Отсоединяем VAO
    glBindVertexArray(0);
    CHECK_GL_ERRORS
    // Отключаем шейдер
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

    // Создание VAO
    // Генерация VAO
    glGenVertexArrays(1, &grassVAO);
    CHECK_GL_ERRORS
    // Привязка VAO
    glBindVertexArray(grassVAO);
    CHECK_GL_ERRORS

    createGrassPoints();
    createGrassPositions();
    createGrassVariences();
    createTexture(&grassTexture, "../Texture/grass.jpg");

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
    createTexture(&groundTexture, "../Texture/ground.jpg");


    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}

void CreateLake(float x, float y, float xx, float yy) {
    groundShader = GL::CompileShaderProgram("ground");

    glGenVertexArrays(1, &lakeVAO);
    CHECK_GL_ERRORS
    glBindVertexArray(lakeVAO);
    CHECK_GL_ERRORS

    std::vector<VM::vec4> lakeMeshPoints = {
        VM::vec4(x, 0.001, y, 1),
        VM::vec4(xx, 0.001, y, 1),
        VM::vec4(x, 0.001, yy, 1),
        VM::vec4(xx, 0.001, y, 1),
        VM::vec4(x, 0.001, yy, 1),
        VM::vec4(xx, 0.001, yy, 1)
    };

    GLuint pointsBuffer;
    glGenBuffers(1, &pointsBuffer);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
    CHECK_GL_ERRORS
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec4) * lakeMeshPoints.size(), lakeMeshPoints.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS
    GLuint index = glGetAttribLocation(groundShader, "point");
    CHECK_GL_ERRORS
    glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, 0, 0);
    CHECK_GL_ERRORS
    glEnableVertexAttribArray(index);
    CHECK_GL_ERRORS


    createTexture(&lakeTexture, "../Texture/lake.jpg");

    glBindVertexArray(0);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    CHECK_GL_ERRORS
}



void CreateObject(const std::string &path,
                  Model **model)
{
    if (!nanoShader) {
        nanoShader = GL::CompileShaderProgram("nano");;
    }
    CHECK_GL_ERRORS
    *model = new Model(path.c_str());
    CHECK_GL_ERRORS
}

void DrowObject(Model *model, ObjectLocation location)
{
    glUseProgram(nanoShader);
    CHECK_GL_ERRORS

    // set uniforms
    GLint cameraLocation = glGetUniformLocation(nanoShader, "camera");
    CHECK_GL_ERRORS
    glUniformMatrix4fv(cameraLocation, 1, GL_TRUE, camera.getMatrix().data().data());
    CHECK_GL_ERRORS

    GLint positionsLocation = glGetUniformLocation(nanoShader, "positions");
    CHECK_GL_ERRORS
    glUniform4f(positionsLocation, location.x, location.y, location.z, location.w);
    CHECK_GL_ERRORS

    model->Draw(nanoShader);

    glUseProgram(0);
    CHECK_GL_ERRORS
}

// Эта функция вызывается для обновления экрана
void RenderLayouts() {
    // Включение буфера глубины
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.52734375, 0.8046875, 0.9765625, 0);
    // Очистка буфера глубины и цветового буфера
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Рисуем меши
    DrawGround();
    DrawGrass();
    DrawLake();

    DrowObject(nanoModel, objectsLocations["nano"]);
    DrowObject(treeModel, objectsLocations["tree"]);
    DrowObject(stoneModel, objectsLocations["stone1"]);
    DrowObject(stoneModel, objectsLocations["stone2"]);
    DrowObject(boxModel, objectsLocations["box"]);
    DrowObject(eagleModel, objectsLocations["eagle"]);
    DrowObject(wolfModel, objectsLocations["wolf"]);

    glutSwapBuffers();
}
