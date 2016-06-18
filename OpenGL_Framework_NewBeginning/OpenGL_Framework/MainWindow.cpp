#include "MainWindow.h"

bool ReadStringFromFile(ifstream& in, string& str)
{
	char readbuf[256];
	char* pBuf = readbuf;
	char len = 0;
	in.read((char*)&len, sizeof(char));
	readbuf[len] = '\0';

	for (int i = 0; i < len; i++)
	{
		in.read(pBuf, 1);
		pBuf++;
	}

	str = readbuf;
	return !in.eof();
};

bool ReadVec3FromFile(ifstream& in, glm::vec3& vector)
{
	float* pBuf = &vector.x;

	for (int i = 0; i < 3; i++)
	{
		in.read((char*)pBuf, sizeof(*pBuf));
		pBuf++;
	}

	return !in.eof();
};

MainWindow::MainWindow(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glcontext = SDL_GL_CreateContext(m_window);
	m_width = width;
	m_height = height;

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cout << "Glew failed to initialize" << std::endl;
	}

	glViewport(0, 0, width, height);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

	glClearColor(0.5, 0.5, 0.5, 1.0f);
	isPaused = false;
	isClosed = false;

	SDL_ShowCursor(SDL_DISABLE);
	cursorWrapped = false;

	MainCycle();
}

void MainWindow::MainCycle()
{
	ReadSceneInfo();

	StartSetup();

	double frameTime, timePassed, secoundTime = 1;
	int FramesCounter = 0, FPS = 0;
	frameTime = 1;
	while (!isClosed)
	{
		if (frameTime >= 0.0016)
		{
			timePassed = clock();
			
			if (((clock() - secoundTime) / CLOCKS_PER_SEC) >= 1)
			{
				//cout << FramesCounter << endl;
				FramesCounter = 0;
				secoundTime = clock();
			}
			else
				FramesCounter++;

			Update();
		}
		frameTime = (clock() - timePassed) / CLOCKS_PER_SEC;
	}
}

void MainWindow::ReadSceneInfo()
{
	char readbuf[50];
	char* pBuf = readbuf;
	ifstream in("Res/SceneInfo.scn", ios::binary | ios::in);

	GameObject* newGameObject;
	string name, shaderName, lightType, modelPath;
	glm::vec3 bufVec;

	int objectsCount = 0;
	in.read((char*)&objectsCount, sizeof(objectsCount));

	if (in.is_open())
	for (int i = 0; i < objectsCount; i++)
	{
		ReadStringFromFile(in, name);
		ReadStringFromFile(in, modelPath);
		ReadStringFromFile(in, shaderName);
		ReadStringFromFile(in, lightType);

		newGameObject = new GameObject(name, shaderName, modelPath);
		if (newGameObject->shader->type == sdr::Light)
			((LightShader*)(newGameObject->shader))->SetLightSourceType(lightSrc::type[lightType]);

		ReadVec3FromFile(in, bufVec);
		newGameObject->transform->SetPosition(bufVec);

		ReadVec3FromFile(in, bufVec);
		newGameObject->transform->SetRotation(bufVec);
		
		ReadVec3FromFile(in, bufVec);
		newGameObject->transform->SetScale(bufVec);

		if (!name.compare("Sun"))
			Sun = newGameObject;

		else if (!name.compare("Player"))
			newGameObject->SetCamera();
	}

	vector<string> texFilenames;
	string texFilenameBuf;

	for (int i = 0; i < 6; i++)
	{
		ReadStringFromFile(in, texFilenameBuf);
		texFilenames.push_back(texFilenameBuf);
	}

	skybox = new Skybox(texFilenames, sdr::Light);

	int tileSize, textureTiling;
	texFilenames.clear();
	for (int i = 0; i < 2; i++)
	{
		ReadStringFromFile(in, texFilenameBuf);
		texFilenames.push_back(texFilenameBuf);
	}
	in.read((char*)&tileSize, sizeof(tileSize));
	in.read((char*)&textureTiling, sizeof(textureTiling));

	terrain = new Terrain(texFilenames, tileSize, textureTiling, sdr::Standard);

	in.close();
}

void MainWindow::StartSetup()
{
	list<void*>::iterator i;

	for (i = Graphics::instance()->GameObjects.begin(); i != Graphics::instance()->GameObjects.end(); i++)
		GameObjects.push_back((GameObject*)(*i));

	for (i = Graphics::instance()->BlendedGameObjects.begin(); i != Graphics::instance()->BlendedGameObjects.end(); i++)
		BlendedGameObjects.push_back((GameObject*)(*i));

	for each (GameObject* gameObject in GameObjects)
		gameObject->Start();

	for each (GameObject* gameObject in BlendedGameObjects)
		gameObject->Start();

	skybox->Start();
	terrain->Start();
}

void MainWindow::Update()
{
	static glm::vec3 sinVec;
	static float sinC;

	UpdateStates();

	Clear();

	skybox->Update();

	list<GameObject*>::iterator i;
	for (i = GameObjects.begin(); i != GameObjects.end(); i++)
		(*i)->Update();

	for (i = BlendedGameObjects.begin(); i != BlendedGameObjects.end(); i++)
		(*i)->Update();
	
	terrain->Update();

	
}

MainWindow::~MainWindow()
{
	SDL_GL_DeleteContext(m_glcontext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void MainWindow::Clear()
{
	SDL_GL_SwapWindow(m_window);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MainWindow::UpdateStates()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			isClosed = true;

		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_c:
					for (list<GameObject*>::iterator i = GameObjects.begin(); i != GameObjects.end(); i++)
						(*i)->ChangeDrawingMode();
					break;
				case SDLK_p:
					isPaused = !isPaused;
					break;
				case SDLK_ESCAPE:
					isClosed = true;
					break;
				case SDLK_1:
					Sun->transform->RotateAround(1, glm::vec3(1, 0, 0));
					break;
				case SDLK_2:
					Sun->transform->RotateAround(1, glm::vec3(0, 1, 0));
					break;
				case SDLK_3:
					Sun->transform->RotateAround(1, glm::vec3(0, 0, 1));
					break;
			}
		}

		if (e.type == SDL_MOUSEMOTION)
		{
			if ( cursorWrapped )
				cursorWrapped = false;
			else
			{
				((Camera*)(Graphics::instance()->MainCamera))->Rotate(e.motion.xrel, e.motion.yrel);
				SDL_WarpMouseInWindow(m_window, m_width / 2, m_height / 2);
				cursorWrapped = true;
			}
		}
	}	

	MoveCamera();
}

void MainWindow::MoveCamera()
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	int xShift = 0;
	int yShift = 0;
	bool run = false;

	if (keystate[SDL_SCANCODE_W])
		yShift += 1;
	if (keystate[SDL_SCANCODE_S])
		yShift -= 1;
	if (keystate[SDL_SCANCODE_D])
		xShift += 1;
	if (keystate[SDL_SCANCODE_A])
		xShift -= 1;
	if (keystate[SDL_SCANCODE_LSHIFT])
		run = true;

	if (xShift || yShift)
	{
		if (run)
		{
			xShift *= 2;
			yShift *= 2;
		}
		((Camera*)(Graphics::instance()->MainCamera))->Move(xShift, yShift);
	}
}

bool MainWindow::IsClosed()
{
	return isClosed;
}
