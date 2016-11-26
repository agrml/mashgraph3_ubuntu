#version 330

layout (location = 0) in vec3 position;  // as our `point`
// layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 camera;
uniform vec3 positions;

void main()
{
    mat4 scaleMatrix = mat4(1.0);
    scaleMatrix[0][0] = 0.01;
    scaleMatrix[1][1] = 0.01;
    scaleMatrix[2][2] = 0.01;
    scaleMatrix[3][3] = positions.z; // w -- scale factor

    mat4 positionMatrix = mat4(1.0);
    positionMatrix[3][0] = positions.x;
    positionMatrix[3][2] = positions.y;

    mat4 rotationMatrix = mat4(0);
    float fi = 4;
    rotationMatrix[0][0] = cos(fi);
    rotationMatrix[0][2] = sin(fi);
    rotationMatrix[1][1] = 1;
    rotationMatrix[2][0] = -sin(fi);
    rotationMatrix[2][2] = cos(fi);
    rotationMatrix[3][3] = 1;

//    gl_Position = camera * rojection * view * model * vec4(position, 1.0f);

	gl_Position = camera * (positionMatrix * scaleMatrix * rotationMatrix * vec4(position, 1.0f));

    TexCoords = texCoords;
}