#version 330

in vec2 textureCoordFragmentShader;

out vec4 outColor;

uniform sampler2D groundTexture;

void main() {
    outColor = texture(groundTexture, textureCoordFragmentShader);
}
