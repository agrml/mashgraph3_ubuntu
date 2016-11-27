//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "Utility.h"

void createGrassPoints();
void createGrassPositions();
void createGrassVariences();
std::vector<VM::vec4> GenMesh(uint n);
std::vector<VM::vec4> GenerateGrassPositions();
void UpdateGrassVariance();

void createGroundPoints();

void createTexture(GLuint *texture, const std::string &path);
