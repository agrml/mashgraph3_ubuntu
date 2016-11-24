//
// Created by mikhail on 24.11.16.
//
#include <iostream>
#include <vector>
#include <SOIL.h>
#include <GL/Texture.h>

#include "Funcs.h"

std::vector<VM::vec4> grassVarianceData(GRASS_INSTANCES); // Вектор со смещениями для координат травинок

void createGrassPoints()
{
    constexpr uint LOD = 50;
    // Создаём меш
    std::vector<VM::vec4> grassPoints = GenMesh(LOD);
    // Сохраняем количество вершин в меше травы
    grassPointsCount = grassPoints.size();
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
}


void createGrassPositions()
{

    // Создаём позиции для травинок
    std::vector<VM::vec2> grassPositions = GenerateGrassPositions();
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
}

void createGrassVariences()
{
    // Инициализация смещений для травинок
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
        grassVarianceData[i] = VM::vec4(0, 0, 0, 0);
    }
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
}

void createGrassRotations() {};
//    // rotate
//    GLfloat fi = static_cast<double>(rand()) / RAND_MAX * M_PI;
//    GLuint rotationBuffer;
//    glGenBuffers(1, &rotationBuffer);
//    CHECK_GL_ERRORS
//    // Привязываем сгенерированный буфер
//    glBindBuffer(GL_ARRAY_BUFFER, rotationBuffer);
//    CHECK_GL_ERRORS
//    // Заполняем буфер данными из вектора
//    glBufferData(GL_ARRAY_BUFFER,
//                 sizeof(GLfloat),
//                 &fi,
//                 GL_STATIC_DRAW);
//    CHECK_GL_ERRORS
//
//    // Получение локации параметра 'point' в шейдере
//    GLuint fiLocation = glGetAttribLocation(grassShader, "fi");
//    CHECK_GL_ERRORS
//    // Устанавливаем параметры для получения данных из массива атрибутов (по 4 значение типа float на одну вершину)
//    // how C binary data must be interpret in shader.
//    // Here we describe layout in one portion to be sent [GPU RAM -> shader program] to the shader's one call. But we can send [RAM -> GPU RAM] an array of portions per one sending.
//    glVertexAttribPointer(fiLocation, // offset to start of corresponding GLSL's variable in `in` section
//                          1, // quantity of attributes per vertex
//                          GL_FLOAT, // how to interpret bytes
//                          GL_FALSE, // do not normalize
//                          0, // size of one portion; 0 -- auto
//                          0); // offset of data
//    CHECK_GL_ERRORS
//    // Подключаем массив атрибутов к данной локации
//    glEnableVertexAttribArray(fiLocation);
//    CHECK_GL_ERRORS

// Обновление смещения травинок
void UpdateGrassVariance() {
    // Генерация случайных смещений
    auto t = glutGet(GLUT_ELAPSED_TIME);
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
        grassVarianceData[i].x = sin(static_cast<float>(t) / 600) / 100;
        grassVarianceData[i].z = sin(static_cast<float>(t) / 600) / 100;
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

// Генерация позиций травинок (эту функцию вам придётся переписать)
std::vector<VM::vec2> GenerateGrassPositions() {
    std::vector<VM::vec2> grassPositions(GRASS_INSTANCES);
    for (uint i = 0; i < GRASS_INSTANCES; ++i) {
        grassPositions[i] = VM::vec2(static_cast<float>(rand()) / RAND_MAX,
                                     static_cast<float>(rand()) / RAND_MAX);
    }
    return grassPositions;
}

/**
 *
 * @param n Quontity of rectangels. Must be >= 3 and n % 2 == 1.
 * @return
 */
std::vector<VM::vec4> GenMesh(uint n)
{
    std::vector<VM::vec4> ans{};
    uint nRectangles = (n - 1) / 2;
    double yStep = 1.0 / (nRectangles + 1);
    double h = 0;
    for (; h < yStep * nRectangles; h += yStep) {
        ans.emplace_back(VM::vec4(0, h, 0, 1));
        ans.emplace_back(VM::vec4(1, h, 0, 1));
        ans.emplace_back(VM::vec4(0, h + yStep, 0, 1));
        ans.emplace_back(VM::vec4(1, h, 0, 1));
        ans.emplace_back(VM::vec4(0, h + yStep, 0, 1));
        ans.emplace_back(VM::vec4(1, h + yStep, 0, 1));
    }
    ans.emplace_back(VM::vec4(0, h, 0, 1));
    ans.emplace_back(VM::vec4(1, h, 0, 1));
    ans.emplace_back(VM::vec4(0.5, 1, 0, 1));
    return ans;
}

void createGroundPoints()
{
// Земля состоит из двух треугольников
    std::vector<VM::vec4> meshPoints = {
        VM::vec4(0, 0, 0, 1),
        VM::vec4(1, 0, 0, 1),
        VM::vec4(1, 0, 1, 1),
        VM::vec4(0, 0, 0, 1),
        VM::vec4(1, 0, 1, 1),
        VM::vec4(0, 0, 1, 1),
    };

    GLuint pointsBuffer;
    glGenBuffers(1, &pointsBuffer);
    CHECK_GL_ERRORS
    glBindBuffer(GL_ARRAY_BUFFER, pointsBuffer);
    CHECK_GL_ERRORS
    glBufferData(GL_ARRAY_BUFFER, sizeof(VM::vec4) * meshPoints.size(), meshPoints.data(), GL_STATIC_DRAW);
    CHECK_GL_ERRORS
    GLuint index = glGetAttribLocation(groundShader, "point");
    CHECK_GL_ERRORS
    glEnableVertexAttribArray(index);
    CHECK_GL_ERRORS
    glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, 0, 0);
    CHECK_GL_ERRORS
}

void createGroundTexture()
{
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
    std::vector<VM::vec2> texturePoints = {
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
}

