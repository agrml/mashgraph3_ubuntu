//
// Created by mikhail on 25.11.16.
//

#include "Utility.h"

uint GRASS_INSTANCES = 10000; // Количество травинок

// Размеры экрана
uint screenWidth = 1920;
uint screenHeight = 1080;

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
GLuint grassTexture;

GLuint groundTexture;
GLuint groundShader; // Шейдер для земли
GLuint groundVAO; // VAO для земли