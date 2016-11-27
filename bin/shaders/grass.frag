#version 330

in vec2 textureCoordFragmentShader;
in float randColor;
in float higth;

out vec4 outColor;

uniform sampler2D grassTexture;

void main() {
    vec4 random = vec4(randColor / 15, randColor / 5, randColor / 15, 0);
    vec4 texture_ = texture(grassTexture, textureCoordFragmentShader);
    vec4 yellowing = vec4(0.3, 0.3, 0, 0) * higth * higth * higth * higth;
    outColor = texture_ + yellowing + random;
}
