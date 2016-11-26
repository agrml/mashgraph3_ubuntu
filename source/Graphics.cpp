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

    // Рисуем землю: 2 треугольника (6 вершин)
    // note: befor this moment we haven't instruct OpenGL how to interpeate vertexes.
    glDrawArrays(GL_TRIANGLES, 0, 6);
    CHECK_GL_ERRORS

    GL::bindTexture(groundShader, "groundTexture", groundTexture);
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

    GL::bindTexture(grassShader, "grassTexture", grassTexture);
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


Model *nanoModel = nullptr;  // FIXME

void CreateNano()
{
    nanoShader = GL::CompileShaderProgram("nano");
    CHECK_GL_ERRORS
    nanoModel = new Model("../nanosuit/nanosuit.obj");
    CHECK_GL_ERRORS
}

void DrawNano() {
    glUseProgram(nanoShader);
    CHECK_GL_ERRORS

    // set uniforms
    GLint cameraLocation = glGetUniformLocation(nanoShader, "camera");
    CHECK_GL_ERRORS
    glUniformMatrix4fv(cameraLocation, 1, GL_TRUE, camera.getMatrix().data().data());
    CHECK_GL_ERRORS

    constexpr float x = 0.3;
    constexpr float y = 0.7;
    constexpr float scale = 0.3;
    GLint positionsLocation = glGetUniformLocation(nanoShader, "positions");
    CHECK_GL_ERRORS
    glUniform3f(positionsLocation, x, y, scale);
    CHECK_GL_ERRORS

    nanoModel->Draw(nanoShader);

    glUseProgram(0);
    CHECK_GL_ERRORS
}

Model *treeModel = nullptr;  // FIXME

void CreateTree()
{
    treeShader = GL::CompileShaderProgram("nano");
    CHECK_GL_ERRORS
    treeModel = new Model("../tree/tree.obj");
    CHECK_GL_ERRORS
}

void DrawTree() {
    glUseProgram(nanoShader);
    CHECK_GL_ERRORS

    // set uniforms
    GLint cameraLocation = glGetUniformLocation(nanoShader, "camera");
    CHECK_GL_ERRORS
    glUniformMatrix4fv(cameraLocation, 1, GL_TRUE, camera.getMatrix().data().data());
    CHECK_GL_ERRORS

    constexpr float x = 0.1;
    constexpr float y = 0.9;
    constexpr float scale = 5;
    GLint positionsLocation = glGetUniformLocation(nanoShader, "positions");
    CHECK_GL_ERRORS
    glUniform3f(positionsLocation, x, y, scale);
    CHECK_GL_ERRORS

    treeModel->Draw(nanoShader);

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
    DrawNano();
    DrawTree();

    glutSwapBuffers();
}
