#include <iostream>
#include <vector>
#include <SOIL.h>
#include <GL/Texture.h>

#include "Utility.h"
#include "Graphics.h"
#include "Globals.h"


// Завершение программы
void FinishProgram() {
    glutDestroyWindow(glutGetWindow());
}

// Это для захвата мышки. Вам это не потребуется (это не значит, что нужно удалять эту строку)
bool captureMouse = true;

// Обработка события нажатия клавиши (специальные клавиши обрабатываются в функции SpecialButtons)
void KeyboardEvents(unsigned char key, int x, int y) {
    if (key == 27) {
        FinishProgram();
    } else if (key == 'w') {
        camera.goForward();
    } else if (key == 's') {
        camera.goBack();
    } else if (key == 'm') {
        captureMouse = !captureMouse;
        if (captureMouse) {
            glutWarpPointer(screenWidth / 2, screenHeight / 2);
            glutSetCursor(GLUT_CURSOR_NONE);
        } else {
            glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
        }
    } else if (key == '+') {
        fWind += 0.3;
    }
}

// Обработка события нажатия специальных клавиш
void SpecialButtons(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        camera.rotateY(0.02);
    } else if (key == GLUT_KEY_LEFT) {
        camera.rotateY(-0.02);
    } else if (key == GLUT_KEY_UP) {
        camera.rotateTop(-0.02);
    } else if (key == GLUT_KEY_DOWN) {
        camera.rotateTop(0.02);
    }
}

void IdleFunc() {
    glutPostRedisplay();
}

// Обработка события движения мыши
void MouseMove(int x, int y) {
    if (captureMouse) {
        int centerX = screenWidth / 2,
            centerY = screenHeight / 2;
        if (x != centerX || y != centerY) {
            camera.rotateY((x - centerX) / 1000.0f);
            camera.rotateTop((y - centerY) / 1000.0f);
            glutWarpPointer(centerX, centerY);
        }
    }
}

// Обработка нажатия кнопки мыши
void MouseClick(int button, int state, int x, int y) {
}

// Событие изменение размера окна
void windowReshapeFunc(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    screenWidth = newWidth;
    screenHeight = newHeight;

    camera.screenRatio = static_cast<float>(screenWidth) / screenHeight;
}

// Создаём камеру (Если шаблонная камера вам не нравится, то можете переделать, но я бы не стал)
void CreateCamera() {
    camera.angle = 60.0f / 180.0f * M_PI;
    camera.direction = VM::vec3(0, 0.3, -1);
    camera.position = VM::vec3(0.5, 0.2, 0);
    camera.screenRatio = static_cast<float>(screenWidth) / screenHeight;
    camera.up = VM::vec3(0, 1, 0);
    camera.zfar = 50.0f;
    camera.znear = 0.05f;
}

// Инициализация окна
void InitializeGLUT(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitContextVersion(3, 0);
    glutInitWindowPosition(200, 50);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Computer Graphics 3");
    glutWarpPointer(400, 300);
    glutSetCursor(GLUT_CURSOR_NONE);

    glutDisplayFunc(RenderLayouts);
    glutKeyboardFunc(KeyboardEvents);
    glutSpecialFunc(SpecialButtons);
    glutIdleFunc(IdleFunc);
    glutPassiveMotionFunc(MouseMove);
    glutMouseFunc(MouseClick);
    glutReshapeFunc(windowReshapeFunc);
}

int main(int argc, char **argv)
{
    try {
        std::cout << "Start" << std::endl;
        InitializeGLUT(argc, argv);
        std::cout << "GLUT inited" << std::endl;
        glewInit();
        std::cout << "glew inited" << std::endl;
        CreateCamera();
        std::cout << "Camera created" << std::endl;

        CreateObject("../objects/nanosuit/nanosuit.obj", &nanoModel);
        objectsLocations["nano"] = ObjectLocation{0.25, 0.7, 0.1625, 0.3, 0};
        std::cout << "Nano created" << std::endl;

        CreateObject("../objects/tree/tree.obj", &treeModel);
        objectsLocations["tree"] = ObjectLocation{0.1, 0.9, 0, 5, 0.1};
        std::cout << "Tree created" << std::endl;

        CreateObject("../objects/stone/stone.obj", &stoneModel);
        objectsLocations["stone1"] = ObjectLocation{0.17, 0.73, 0.0295, 0.1, 0.2};
        objectsLocations["stone2"] = ObjectLocation{0.3, 0.92, 0.016, 0.2, 0.1};
        std::cout << "Stones created" << std::endl;

        CreateObject("../objects/box/Crate1.obj", &boxModel);
        objectsLocations["box"] = ObjectLocation{0.9, 0.9, 0.105, 0.1, 0.15};
        std::cout << "Box created" << std::endl;

        CreateObject("../objects/eagle/EAGLE_2.OBJ", &eagleModel);
        objectsLocations["eagle"] = ObjectLocation{0.5, 0.5, 0.7, 0.02, 0};
        std::cout << "Eagle created" << std::endl;

        CreateObject("../objects/wolf/WOLF.OBJ", &wolfModel);
        objectsLocations["wolf"] = ObjectLocation{0.9, 0.9, 0.2, 0.08, 0};
        std::cout << "Wolf created" << std::endl;

        CreateLake(0.5, 0.5, 0.6, 0.6);
        objectsLocations["lake"] = ObjectLocation{0.5, 0.5, 0, 0.08, 0.1};
        std::cout << "Lake created" << std::endl;

        CreateGrass();
        std::cout << "Grass created" << std::endl;
        CreateGround();
        std::cout << "Ground created" << std::endl;

        glutMainLoop();
    } catch (std::string s) {
        std::cout << s << std::endl;
    }
}
