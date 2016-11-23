#!/usr/bin/env bash

#apt (1)
#apt (2)
#cd ./
#cmake CMakeLists.txt

make
export MESA_GL_VERSION_OVERRIDE="3.3COMPAT"
cd bin && ./cmake_project && cd ..
