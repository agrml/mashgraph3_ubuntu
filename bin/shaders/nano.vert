#version 330

layout (location = 0) in vec3 position;  // as our `point`
// layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 camera;
uniform mat4 positionMatrix;

void main()
{
    mat4 scaleMatrix = mat4(1.0);
    scaleMatrix[0][0] = 0.001;
    scaleMatrix[1][1] = 0.001;
    scaleMatrix[2][2] = 0.001;
    scaleMatrix[3][3] = 1; // w -- scale factor

//    gl_Position = camera * rojection * view * model * vec4(position, 1.0f);

	gl_Position = camera * (positionMatrix * scaleMatrix * vec4(position, 1.0f));

    TexCoords = texCoords;
}