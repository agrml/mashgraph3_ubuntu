//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "model.h"

void DrawGround();
void DrawGrass();
void CreateGrass();
void CreateGround();
void RenderLayouts();

void CreateObject(const std::string &path,
                  Model **model);
void DrowObject(Model *model, ObjectLocation location);

void CreateLake(float x, float y, float xx, float yy);
void DrawLake();
