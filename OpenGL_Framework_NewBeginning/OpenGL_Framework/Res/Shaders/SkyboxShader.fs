#version 330 core

in vec3 TexCoords;
out vec4 color;

struct Material {
    samplerCube texture_diffuse1;
}; 
uniform Material material;

void main()
{    
    color = texture(material.texture_diffuse1, TexCoords);
}