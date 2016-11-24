//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "Utility.h"
#include "Externs.h"

void createGrassPoints();
void createGrassPositions();
void createGrassVariences();
void createGrassRotations();

void createGroundPoints();
void createGroundTexture();

std::vector<VM::vec4> GenMesh(uint n);
std::vector<VM::vec2> GenerateGrassPositions();
void UpdateGrassVariance();
