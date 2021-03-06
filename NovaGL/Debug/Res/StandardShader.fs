#version 330 core
struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    float shininess;
}; 
uniform Material material;

struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  

struct PointLight {    
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;  

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define NR_POINT_LIGHTS 1

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir, vec3 diffColor, vec3 specColor);  
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffColor, vec3 specColor);
vec3 CalcSpotLight(SpotLight spotLight, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffColor, vec3 specColor);

uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;  

uniform vec3 viewPos;

out vec4 color;

void main()
{
    vec4 diffColor = texture(material.texture_diffuse1, TexCoords);
    if(diffColor.a < 0.1)
        discard;
	
	// Properties
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
	vec3 specColor = vec3(texture(material.texture_specular1, TexCoords));
	
    // Phase 1: Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir, vec3(diffColor), specColor);
    // Phase 2: Point lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
     result += CalcPointLight(pointLights[i], norm, FragPos, viewDir, vec3(diffColor), specColor);    
    // Phase 3: Spot light
    result  += CalcSpotLight(spotLight, norm, FragPos, viewDir, vec3(diffColor), specColor);      
    
    color = vec4(result, diffColor.a);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir, vec3 diffColor, vec3 specColor)
{
    vec3 lightDir = normalize(-light.direction);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Combine results
    vec3 ambient  = light.ambient  * diffColor;
    vec3 diffuse  = light.diffuse  * diff * diffColor;
    vec3 specular = light.specular * spec * specColor;
    return (ambient + diffuse + specular);
}  

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffColor, vec3 specColor)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + 
  			     light.quadratic * (distance * distance));    
    // Combine results
    vec3 ambient  = light.ambient  * diffColor;
    vec3 diffuse  = light.diffuse  * diff * diffColor;
    vec3 specular = light.specular * spec * specColor;
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
} 

// Calculates the color when using a spot light.
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 diffColor, vec3 specColor)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    // Spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // Combine results
    vec3 ambient = light.ambient * diffColor;
    vec3 diffuse = light.diffuse * diff * diffColor;
    vec3 specular = light.specular * spec * specColor;
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}
