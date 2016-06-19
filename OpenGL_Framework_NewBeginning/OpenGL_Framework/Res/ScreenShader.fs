#version 330 core

in vec2 TexCoords;
uniform sampler2D screenTexture;

uniform int useKernel;
uniform float offset;
uniform float kernel[9];
uniform int simpleEffectType;

out vec4 color;

void main()
{
	if(useKernel == 1)
	{
		vec2 offsets[9] = vec2[](
			vec2(-offset, offset),  // top-left
			vec2(0.0f,    offset),  // top-center
			vec2(offset,  offset),  // top-right
			vec2(-offset, 0.0f),    // center-left
			vec2(0.0f,    0.0f),    // center-center
			vec2(offset,  0.0f),    // center-right
			vec2(-offset, -offset), // bottom-left
			vec2(0.0f,    -offset), // bottom-center
			vec2(offset,  -offset)  // bottom-right    
		);
		
		vec3 sampleTex[9];
		for(int i = 0; i < 9; i++)
		{
			sampleTex[i] = vec3(texture(screenTexture, TexCoords.st + offsets[i]));
		}
		vec3 col = vec3(0.0);
		for(int i = 0; i < 9; i++)
			col += sampleTex[i] * kernel[i];
		
		color = vec4(col, 1.0);
	}
	else
	{
		vec4 texColor = texture(screenTexture, TexCoords);
		
		switch(simpleEffectType)
		{
			// Grayscale
			case 0:
				float average = 0.2126 * texColor.r + 0.7152 * texColor.g + 0.0722 * texColor.b;
				color = vec4(average, average, average, 1.0);
				break;
				
			// VCR
			case 1:
				color = vec4(1-texColor.r, texColor.g, 1-texColor.b, 1);
				break;
			
			// Invert
			case 2:
				color = vec4(1-texColor.r, 1-texColor.g, 1-texColor.b, 1);
				break;
			
			// None
			case 3:
				color = vec4(texColor.r, texColor.g, texColor.b, 1);
				break;
		}
	}
}