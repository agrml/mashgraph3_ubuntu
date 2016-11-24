#version 330

// order of `in`'s may vary if we use `glGetAttribLocation` in C++.
in vec4 point;
in vec2 position;
// смещение
in vec4 variance;
//in float fi;

uniform mat4 camera;

void main() {
    mat4 scaleMatrix = mat4(1.0);
    scaleMatrix[0][0] = 0.01;
    scaleMatrix[1][1] = 0.01;
    scaleMatrix[2][2] = 0.01;
    scaleMatrix[3][3] = 1; // w -- scale factor

    mat4 positionMatrix = mat4(1.0);
    positionMatrix[3][0] = position.x;
    positionMatrix[3][2] = position.y;

//    mat4 rotationMatrix = mat4(0);
//    rotationMatrix[0][0] = cos(fi);
//    rotationMatrix[0][1] = sin(fi);
//    rotationMatrix[1][1] = 1;
//    rotationMatrix[2][0] = -sin(fi);
//    rotationMatrix[2][2] = cos(fi);
//    rotationMatrix[3][3] = 1;

	gl_Position = camera * (positionMatrix * scaleMatrix * point      + variance - variance);
	// + variance * point.y

	// object in -1..1 -> scale and rotate cube [cos cos sin -sin -- rotation matrix] -> locate cube in map
	// point -- point in cube; positionMatrix -- locates cube in the map
	// variance * point.y -- animation  // TODO: rewrite
}
