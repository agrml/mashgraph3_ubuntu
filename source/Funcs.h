//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "Utility.h"

void createGrassPoints();
void createGrassPositions();
void createGrassVariences();
void createGrassTexture();

std::vector<VM::vec4> GenMesh(uint n);
std::vector<VM::vec4> GenerateGrassPositions();
void UpdateGrassVariance();

void createGroundPoints();
void createGroundTexture();

GLint TextureFromFile(const char* path, std::string directory, bool gamma = false);
