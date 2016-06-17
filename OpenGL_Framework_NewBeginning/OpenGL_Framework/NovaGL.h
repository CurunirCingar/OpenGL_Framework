//#pragma once
//#include <string>
//#include "resource.h"
//#include <list>
//#include <time.h>
//using namespace std;
//#include "Camera.h"
//#include "GameObject.h"
//#include "Skybox.h"
//#include "Terrain.h"
//
//namespace NGL
//{
//	class MainWindow
//	{
//	public:
//		__declspec(dllexport) MainWindow(int width, int height, const std::string& title);
//		__declspec(dllexport) ~MainWindow();
//
//		static __declspec(dllexport) void MainCycle();
//		static __declspec(dllexport) void Clear();
//		static __declspec(dllexport) void ReadSceneInfo();
//		static __declspec(dllexport) void StartSetup();
//		static __declspec(dllexport) void Update();
//		static __declspec(dllexport) void UpdateStates();
//		static __declspec(dllexport) void MoveCamera();
//		static __declspec(dllexport) bool IsClosed();
//
//	private:
//		static SDL_Window* m_window;
//		static GLuint m_width, m_height;
//		static SDL_GLContext m_glcontext;
//		static std::list<GameObject*> GameObjects;
//			   
//		static GameObject* characterController;
//			   
//		static Skybox* skybox;
//		static Terrain* terrain;
//			   
//		static GLboolean isClosed;
//		static GLboolean isPaused;
//		static GLboolean cursorWrapped;
//		static SDL_Event e;
//	};
//};