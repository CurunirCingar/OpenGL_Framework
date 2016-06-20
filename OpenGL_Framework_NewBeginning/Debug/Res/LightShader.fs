#version 330 core
struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 
uniform Material material;

in vec2 TexCoords;
uniform vec4 ambient;

out vec4 color;

void main()
{
	color = texture(material.texture_diffuse1, TexCoords) * ambient;
}