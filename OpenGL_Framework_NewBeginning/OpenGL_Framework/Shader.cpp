#include "Shader.h"

Shader::Shader(const std::string& filename)
{
	m_shaders[0] = CreateShader("./Res/" + filename + ".vs", GL_VERTEX_SHADER); //Creates shader ID
	m_shaders[1] = CreateShader("./Res/" + filename + ".fs", GL_FRAGMENT_SHADER);

	m_program = glCreateProgram();
	glAttachShader(m_program, m_shaders[0]);
	glAttachShader(m_program, m_shaders[1]);

	glLinkProgram(m_program);
	CheckShaderError(m_program, true, GL_LINK_STATUS, "Error: Program linking failed.");

	glValidateProgram(m_program);
	CheckShaderError(m_program, true, GL_VALIDATE_STATUS, "Error: Program validation failed.");

	glUseProgram(m_program);
}

Shader::~Shader()
{
	for (GLuint i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}

void Shader::Update()
{
	glUseProgram(m_program);
	ShaderUpdate();
}

GLuint Shader::CreateShader(const std::string& filename, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (!shader) {
		std::cout << "Error: Shader creation failed." << std::endl;
		return -1;
	}

	LoadShader(shader, filename);

	glCompileShader(shader); //Compiling the shader
	CheckShaderError(shader, false, GL_COMPILE_STATUS, "Error: Vertex shader compilation failed.");

	return shader;
}

void Shader::LoadShader(GLuint shaderID, const std::string& filename)
{
	std::ifstream file;
	file.open(filename.c_str());

	std::string output, line;

	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cout << "Unable to load shader from file " << filename << "." << std::endl;
	}

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringsLength[1];

	shaderSourceStrings[0] = output.c_str();
	shaderSourceStringsLength[0] = output.length();

	glShaderSource(shaderID, 1, shaderSourceStrings, shaderSourceStringsLength); //Sets the source code
}

void Shader::CheckShaderError(GLuint shader, bool isProgram, GLuint flag, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success); //Check if whole shader m_program compilation was successful
	else
		glGetShaderiv(shader, flag, &success); //Check if some shader compilation was successful

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error); //Returns the error message
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		std::cout << errorMessage << ": '" << error << "'." << std::endl;
	}
}
