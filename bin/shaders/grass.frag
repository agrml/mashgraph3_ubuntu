#version 330

in vec2 textureCoordFragmentShader;

out vec4 outColor;

uniform sampler2D grassTexture;

void main() {
    outColor = texture(grassTexture, textureCoordFragmentShader);
}
