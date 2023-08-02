#version 330 core

out vec4 FragColor;

uniform sampler2D tex;

in vec2 TexCoord;

void main()
{
	FragColor = texture(tex, TexCoord);
}