
Травинки отличаются:
 - размером,
 - углом поворота,
 - оттенком цвета,
 - (позицией).

Сила ветра регулируется пользователем: нажатие на клавишу `+` сообщает травинкам некоторое ускорение, в результате чего колебания усиливаются (или замедляются -- в зависимости от фазы колебания в момент создания порыва ветра). При запуске программы происходит умеренный порыв ветра.


Выполненные дополнительные задания:
● Анти-алиасинг (До +5)
    ○ Должен включаться и отключаться по кнопке “A”.
    ○ MSAA (+2) (http://www.learnopengl.com/#!Advanced-OpenGL/Anti-aliasing)
    ○ Super Sampling (+3) - рендеринг в текстуру с бОльшим разрешением (чем
    разрешение экрана) и даунсэмплинг
    ○ Super Sampling + MSAA (+5)
● Базовое освещение (до + 5 баллов).
    ○ ++++++++++++++++++++++++Текстура на травинках (+1).+++++++++++++++++++++++++++++
    ○ Освещение по ламберту и/или фонгу с одним источником света (+1).
    ○ Два разных источника света (например направленный и точечный) (+1).
    ○ Затемнение травы ближе к земле для имитации эффекта Ambient Occlusion (+1).
    ○ Имитация грязи и/или пожелтения (+1)
    ○ Специализированные модели освещения травы или волос (+2)
● Тени (до + 6 баллов).
    ○ Тени на плоскость (+1)
    ○ Простой Shadow Map (+3)
    ○ Простой Shadow Map + PCF (+4)
    ○ Более сложные и реалистичные методы теней (до +6)

Надеюсь, Вы найдете уменя еще случайно выполненные допы :)
 

# Mash3_Template
Template for 3rd task on computer graphics

__Place your source files in "source" directory and headers in "include"__

## Usage:

1) Install appropriate libraries:

> sudo apt-get install freeglut3-dev libglew-dev libglu1-mesa-dev

3) Clone this repository with:

> git clone https://github.com/BorisLestsov/Mash3_Template.git

4) To compile everything run in the project directory:

> make

__To run the project, go to bin and run:__

> ./mash3 

## Possible errors:

If you get error:
```
Shader: 0:1(10): error: GLSL 3.30 is not supported. Supported versions are: 1.10, 1.20, 1.30, 1.00 ES, and 3.00 ES

COMPILATION ERROR | Line: 22 File: shaders/grass.vert
```
Then you sould add this line to the end of ".bashrc" file in your home directory:
```
export MESA_GL_VERSION_OVERRIDE="3.3COMPAT"
```

If you your system does not support GLSL 3.10 - replace "shaders" directory and "main.cpp" with the ones from downgrade.
