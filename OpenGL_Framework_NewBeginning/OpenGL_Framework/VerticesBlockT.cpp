#include "VerticesBlockT.h"

VerticesBlockT::VerticesBlockT(const std::string& filename)
{
	std::ifstream file;
	std::string block, line;
	std::string verticesFolder = "[vertices]", 
				indicesFolder = "[indices]", 
				texFileFolder = "[textures]", 
				endOfFolder = "[end]";

	GLuint stage = START;
	GLuint linesAmount = 0;

	file.open(("./Res/" + filename + ".vert").c_str());

	if (!file.is_open())
		stage = ERROR;

	while (file.good())
	{
		std::getline(file, line);

		switch (stage)
		{
		case START:
			stage = (line == verticesFolder) ? VERTICES : ERROR;
			break;

		case VERTICES:
			if (line != indicesFolder){
				block.append(line + "\n");
				linesAmount++;
			}
			else{
				SetVertices(block, linesAmount);
				block.clear();
				//std::cout << filename << linesAmount;
				linesAmount = 0;
				stage = INDICES;
			}
			break;

		case INDICES:
			if (line != texFileFolder){
				block.append(line + "\n");
				linesAmount++;
			}
			else{
				SetIndices(block, linesAmount);
				block.clear();
				
				linesAmount = 0;
				stage = TEXTURES;
			}
			break;

		case TEXTURES:
			if (line != endOfFolder){
				block.append(line + "\n");
				linesAmount++;
			}
			else{
				SetTextures(block, linesAmount);
				block.clear();
				linesAmount = 0;
				stage = END;
			}
			break;

		case END:
			return;
			break;
		case ERROR:
			std::cout << "Unable to read mesh data from file " << filename << ". Maybe you change it's format?" << std::endl;
			return;
			break;
		}
	}
}

VerticesBlockT::~VerticesBlockT()
{
	delete[] m_vertices;
	delete[] m_indices;
}

void VerticesBlockT::SetVertices(std::string textBlock, GLuint linesAmount)
{
	std::string value;
	float triadValue[4][3];
	GLuint j_Triad = 0, i_Triad = 0, lineCounter = 0, lineElementsCount = 0;
	bool isSigned = false;
	
	m_vertices = new VertexT[linesAmount];
	m_verticesSize = linesAmount;
	//std::cout << m_verticesSize << std::endl;

	for (std::string::iterator it = textBlock.begin(); it != textBlock.end(); it++)
	{
		switch (*it)
		{
			case ',':
				triadValue[i_Triad][j_Triad] = atof(value.c_str());
				if (isSigned)
				{
					triadValue[i_Triad][j_Triad] = -triadValue[i_Triad][j_Triad];
					isSigned = false;
				}
				
				value.clear();
				j_Triad++;
				lineElementsCount++;
				if(j_Triad == 3)
				{
					i_Triad++;
					j_Triad = 0;
				}
			break;

			case '-':
				isSigned = true;
			break;

			case '\n':
				triadValue[i_Triad][j_Triad] = atof(value.c_str());
				if (isSigned)
				{
					triadValue[i_Triad][j_Triad] = -triadValue[i_Triad][j_Triad];
					isSigned = false;
				}
				value.clear();
				m_vertices[lineCounter].pos.x = triadValue[0][0];
				m_vertices[lineCounter].pos.y = triadValue[0][1];
				m_vertices[lineCounter].pos.z = triadValue[0][2];

				m_vertices[lineCounter].norm.x = triadValue[1][0];
				m_vertices[lineCounter].norm.y = triadValue[1][1];
				m_vertices[lineCounter].norm.z = triadValue[1][2];
				//std::cout << "Vertices: " << m_vertices[lineCounter].norm.x << " " << m_vertices[lineCounter].norm.y << " " << m_vertices[lineCounter].norm.z << std::endl;
				m_vertices[lineCounter].col.r = triadValue[2][0];
				m_vertices[lineCounter].col.g = triadValue[2][1];
				m_vertices[lineCounter].col.b = triadValue[2][2];

				m_vertices[lineCounter].texCoord.s = triadValue[3][0];
				m_vertices[lineCounter].texCoord.t = triadValue[3][1];
				i_Triad = j_Triad = 0;
				//std::cout << "Vertices: " << m_vertices[lineCounter].pos.x << " " << m_vertices[lineCounter].pos.y << " " << m_vertices[lineCounter].pos.z <<
				//	" Colors: " <<	m_vertices[lineCounter].col.r << " " << m_vertices[lineCounter].col.g << " " << m_vertices[lineCounter].col.b
				//	<< " TexCoords: " << m_vertices[lineCounter].texCoord.s << " " << m_vertices[lineCounter].texCoord.t << std::endl;
				lineCounter++;
			break;

			default:
				value += *it;
			break;
		}
	}
}

void VerticesBlockT::SetIndices(std::string textBlock, GLuint linesAmount)
{
	std::string value;
	GLuint line;
	float triadValue[3];
	int j_Triad = 0, lineCounter = 0;

	m_indices = new GLuint[3*linesAmount];
	m_indicesSize = 3*linesAmount;

	for (std::string::iterator it = textBlock.begin(); it != textBlock.end(); it++)
	{
		switch (*it)
		{
		case ',':
			triadValue[j_Triad] = atof(value.c_str());
			value.clear();
			j_Triad++;
			break;

		case '\n':
			triadValue[j_Triad] = atoi(value.c_str());
			value.clear();
			m_indices[lineCounter] = triadValue[0];
			m_indices[lineCounter+1] = triadValue[1];
			m_indices[lineCounter+2] = triadValue[2];
			//std::cout << m_indices[lineCounter] << " " << m_indices[lineCounter + 1] << " " << m_indices[lineCounter+2] << std::endl;
			j_Triad = 0;
			lineCounter+=3;
			break;

		default:
			value += *it;
			break;
		}
	}
}

void VerticesBlockT::SetTextures(std::string textBlock, GLuint linesAmount)
{
	std::string value;
	GLuint line;
	float triadValue[3];
	int i_Str = 0;

	m_texturesFilesArr = new std::string[linesAmount];
	m_texturesFilesArrLen = linesAmount;

	for (std::string::iterator it = textBlock.begin(); it != textBlock.end(); it++)
	{
		switch (*it)
		{
		case '\n':
			m_texturesFilesArr[i_Str] = value;
			value.clear();
			i_Str++;
			//std::cout << value << std::endl;
			break;

		default:
			value += *it;
			break;
		}
	}

}