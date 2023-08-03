#include "Material.h"

Material::Material()
{
	
}

void Material::SetColor(glm::vec3 _color)
{
	color = _color;
}

void Material::SetTexture(Texture* _tex)
{
	tex = _tex;
}

void Material::SetShader(Shader* _shader)
{
	shader = _shader;
}