//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "model.h"

extern uint GRASS_INSTANCES;
extern uint screenWidth;
extern uint screenHeight;

extern GL::Camera camera;

extern GLuint grassPointsCount;
extern GLuint grassShader;
extern GLuint grassVAO;
extern GLuint grassVariance;
extern GLuint grassTexture;

extern GLuint groundTexture;
extern GLuint groundShader;
extern GLuint groundVAO;

extern float fWind;

extern GLuint nanoShader;

extern Model *nanoModel;
extern Model *treeModel;
extern Model *stoneModel;

extern std::map<std::string, ObjectLocation> objectsLocations;
