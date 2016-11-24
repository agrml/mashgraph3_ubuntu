cmake_minimum_required(VERSION 2.8)
project(cmake_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Utility/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Utility/include/GL)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Utility/include/VM)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH bin)

add_library(SOIL STATIC ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/image_DXT.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/image_helper.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/SOIL.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/stb_image_aug.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/image_DXT.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/stbi_DDS_aug_c.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/stb_image_aug.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/image_helper.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/SOIL.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/stbi_DDS_aug.h
#        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/original/stb_image-1.09.c
#        ${CMAKE_CURRENT_SOURCE_DIR}/SOIL/src/original/stb_image-1.16.c
        )

add_executable(cmake_project
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/Camera.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/GL.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/Overall.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/ShaderProgram.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/Texture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/mat4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/uvec3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/vec2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/vec3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Utility/src/vec4.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/Funcs.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/Window.cpp)

add_custom_target(make COMMAND $(MAKE) -C ${cmake_project_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})

set_target_properties(cmake_project PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_CURRENT_SOURCE_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

target_link_libraries(
        cmake_project
        ${GLUT_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
        SOIL)