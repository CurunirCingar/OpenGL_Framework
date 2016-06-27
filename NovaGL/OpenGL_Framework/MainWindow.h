#pragma once
#include "resource.h"
#include <list>
#include <map>
#include <time.h>
using namespace std;

#include "Camera.h"
#include "GameObject.h"
#include "Skybox.h"
#include "Terrain.h"
#include "Framebuffer.h"

class MainWindow
{
public:
	MainWindow(int width, int height, const string& title);
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

	list<GameObject*> GameObjects;
	list<GameObject*> BlendedGameObjects;

	GameObject* Sun;
	GameObject* characterController;

	Skybox* skybox;
	Terrain* terrain;

	Framebuffer* framebuffer;

	GLboolean isClosed;
	GLboolean isPaused;
	GLboolean cursorWrapped;
	SDL_Event e;
};

