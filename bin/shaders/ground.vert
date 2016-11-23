#version 330

in vec4 point;
in vec2 textureCoordVertexShader;

out vec2 textureCoordFragmentShader;

uniform mat4 camera;

void main() {
    gl_Position = camera * point;
    textureCoordFragmentShader = textureCoordVertexShader;
}
