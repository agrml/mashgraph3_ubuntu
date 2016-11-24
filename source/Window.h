//
// Created by mikhail on 24.11.16.
//

#pragma once

#include "Utility.h"
#include "Externs.h"


void FinishProgram();
void KeyboardEvents(unsigned char key, int x, int y);
void SpecialButtons(int key, int x, int y);
void IdleFunc();
void MouseMove(int x, int y);
void MouseClick(int button, int state, int x, int y);
void windowReshapeFunc(GLint newWidth, GLint newHeight);
void CreateCamera();