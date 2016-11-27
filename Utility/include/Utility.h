#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "uvec3.h"
#include "vec2.h"
#include "Camera.h"
#include "ShaderProgram.h"

struct ObjectLocation
{
    float x, y, z, w, r;
    ObjectLocation(float xx=0, float yy=0, float zz=0, float ww=0, float rr=0) :
            x (xx), y(yy), z(zz), w(ww), r(rr) {}
};

#endif // UTILITY_H_INCLUDED
