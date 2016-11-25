#version 330

in vec4 point;
in vec2 textureCoordVertexShader;

out vec2 textureCoordFragmentShader;

uniform mat4 camera;

void main() {
    mat4 scaleMatrix = mat4(1.0);
    scaleMatrix[0][0] = 0.001;
    scaleMatrix[1][1] = 0.01;
    scaleMatrix[2][2] = 0.001;
    scaleMatrix[3][3] = 0.1; // w -- scale factor

    gl_Position = camera * point;
    textureCoordFragmentShader = textureCoordVertexShader;
}
