#version 330

in vec2 textureCoordFragmentShader;
in float randColor;

out vec4 outColor;

uniform sampler2D grassTexture;

void main() {
    outColor = texture(grassTexture, textureCoordFragmentShader) + vec4(randColor / 15, randColor / 5, randColor / 15, 0);
}
