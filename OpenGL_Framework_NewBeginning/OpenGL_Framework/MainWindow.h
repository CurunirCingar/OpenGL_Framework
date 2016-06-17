#pragma once
#include "resource.h"
#include <list>
#include <time.h>
using namespace std;

#include "Camera.h"
#include "GameObject.h"
#include "Skybox.h"
#include "Terrain.h"

class MainWindow
{
public:
	MainWindow(int width, int height, const std::string& title);
	virtual ~MainWindow();

	void MainCycle();
	void Clear();
	void ReadSceneInfo();
	void StartSetup();
	void Update();
	void UpdateStates();
	void MoveCamera();
	bool IsClosed();
	
private:
	SDL_Window* m_window;
	GLuint m_width, m_height;
	SDL_GLContext m_glcontext;

	std::list<GameObject*> GameObjects;
	std::list<GameObject*> BlendedGameObjects;

	GameObject* Sun;
	GameObject* characterController;

	Skybox* skybox;
	Terrain* terrain;

	GLboolean isClosed;
	GLboolean isPaused;
	GLboolean cursorWrapped;
	SDL_Event e;
};

