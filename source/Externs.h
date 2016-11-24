//
// Created by mikhail on 24.11.16.
//

#pragma once

extern const uint GRASS_INSTANCES; // Количество травинок

// Размеры экрана
extern uint screenWidth;
extern uint screenHeight;

// Мы предоставляем Вам реализацию камеры. В OpenGL камера - это просто 2 матрицы.
// Модельно-видовая матрица и матрица проекции.
// ###
// Задача этого класса только в том чтобы обработать ввод с клавиатуры и правильно сформировать эти матрицы.
// Вы можете просто пользоваться этим классом для расчёта указанных матриц.
extern GL::Camera camera;

extern GLuint grassPointsCount; // Количество вершин у модели травинки
extern GLuint grassShader;      // Шейдер, рисующий траву
extern GLuint grassVAO;         // VAO для травы (что такое VAO почитайте в доках)
extern GLuint grassVariance;    // Буфер для смещения координат травинок

extern GLuint groundTexture;
extern GLuint groundShader; // Шейдер для земли
extern GLuint groundVAO; // VAO для земли