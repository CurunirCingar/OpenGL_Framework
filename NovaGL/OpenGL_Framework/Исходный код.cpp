#pragma comment(lib, "opengl32.lib") //���������� ��� ������ � OpenGL
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h> //������������ ���� Windows
#include <gl/GL.h> //������������ ���� OpenGL
#include <malloc.h> //������������ ���� ��� ������ � �������
#include <time.h> //������������ ���� ��� ������ � ��������
#include "glext.h" //������������ ���� OpenGL Extension
#include "wglext.h" //������������ ���� Windows OpenGL Extension
#include "vmath.h" //������������ ���� ��������� ����������
#define UPDATE_TIMER_ID 200
#define VERTEX_ATRIB_COLOR 1
#define VERTEX_ATRIB_POSITION 0
#define BUFFER_OFFSET(i) ((GLbyte*)NULL + (i))
#define OPENGL_GET_PROC(type, func) \
	func = (type)wglGetProcAddress(#func); \
if (!func) \
	OutputDebugString("Loading extension '" #func "' fail\n")
HDC hDC = nullptr; //�������� ����������
HGLRC hRC = nullptr; //�������� ����������
//����� ���� � ��������� ����
auto windowClassName = "OpenGLApplication";
auto windowTitleName = "OpenGL Application";
//��������� �� ������� ���������� Windows OpenGL
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
//��������� �� ������� ���������� OpenGL
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLBUFFERDATAPROC glBufferData = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
PFNGLATTACHSHADERPROC glAttachShader = nullptr;
PFNGLCREATESHADERPROC glCreateShader = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
PFNGLDELETESHADERPROC glDeleteShader = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv = nullptr;
PFNGLDETACHSHADERPROC glDetachShader = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
GLuint programID = 0; //������������� ���������
GLuint VBO[2] = { 0 }; //������ ��� Vertex Buffer Objects
GLuint VAO[2] = { 0 }; //������ ��� Vertex Array Objects
//����������� ������ ��� ��������
struct Vertex {
	Vector2f Position;
	Vector3f Color;
};
/**
* ������� �������� ��������
*/
void LoadShaders() {
	auto status = 0;
	auto logLength = 0;
	auto vertexShaderSource = R"(#version 330 core
layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec3 inColor;
smooth out vec3 currentColor;
void main() {
currentColor = inColor;
gl_Position = vec4(inPosition, 0.0, 1.0);
})";
	auto fragmentShaderSource = R"(#version 330 core
out vec4 outputColor;
smooth in vec3 currentColor;
void main() {
outputColor = vec4(currentColor, 1.0);
})";
	//������� ���������
	programID = glCreateProgram();
	//������� ��������� ������
	auto vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	//��������� ��� �������� �������� ����� ���������� �������
	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	//���������� ���������� �������
	glCompileShader(vertexShaderID);
	//�������� ������ ����������
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//�������� ������ ���������
			glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//�������� ����������� ������ � ������
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//�������� ���������
			glGetShaderInfoLog(vertexShaderID, logLength, &logLength, log);
			//������� � ���� �������
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Vertex Shader Compilation Log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Vertex Shader Compilation Log: %s", log);
#endif
			//����������� ������
			free(log);
		}
#endif
		//������� ������
		glDeleteShader(vertexShaderID);
	}
	//����������� ������ � ����������
	glAttachShader(programID, vertexShaderID);
	//������� ���������� (�����������) ������
	auto fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//��������� ��� �������� �������� ����� ����������� �������
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
	//���������� ���������� �������
	glCompileShader(fragmentShaderID);
	//�������� ������ ����������
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//�������� ������ ���������
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//�������� ����������� ������ � ������
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//�������� ���������
			glGetShaderInfoLog(fragmentShaderID, logLength, &logLength, log);
			//������� � ���� �������
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Fragment Shader Compilation Log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Fragment Shader Compilation Log: %s", log);
#endif
			//����������� ������
				free(log);
		}
#endif
		//������� ������
		glDeleteShader(fragmentShaderID);
	}
	//����������� ������ � ����������
	glAttachShader(programID, fragmentShaderID);
	//��������� ��������� � ������ ����������
	glLinkProgram(programID);
	//�������� ������ ��������
	glGetProgramiv(programID, GL_LINK_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//�������� ������ ���������
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//�������� ����������� ������ � ������
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//�������� ���������
			glGetProgramInfoLog(programID, logLength, &logLength, log);
			//������� � ���� �������
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Program link log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Program link log: %s", log);
#endif
			//����������� ������
			free(log);
		}
#endif
		//������� ���������
		glDeleteProgram(programID);
		return;
	}
	if (vertexShaderID) {
		glDetachShader(programID, vertexShaderID);
		glDeleteShader(vertexShaderID);
	}
	if (fragmentShaderID) {
		glDetachShader(programID, fragmentShaderID);
		glDeleteShader(fragmentShaderID);
	}
	//������ �������� �����������
	glUseProgram(programID);
}
/**
* ������� �������������� ������������� �����
*/
void InitScene() {
	//������� ������ � ������ ���� (���)
	glClearColor(0.0f /* Red */, 0.0f /* Green */, 0.0f /* Blue */, 0.0f /* Alpha */);
	//������ ������ ��������������
	Vertex quadMesh[] = {
		{ Vector2f(-0.2f, 0.095f), Vector3f(1.0f, 0.0f, 0.0f) },
		{ Vector2f(-0.2f, -0.5f), Vector3f(0.0f, 1.0f, 0.0f) },
		{ Vector2f(0.2f, 0.095f), Vector3f(0.0f, 0.0f, 1.0f) },
		{ Vector2f(0.2f, -0.5f), Vector3f(1.0f, 1.0f, 0.0f) }
	};
	//������ ������ ������������
	Vertex triangleMesh[] = {
		{ Vector2f(-0.2f, 0.1f), Vector3f(1.0f, 0.0f, 0.0f) },
		{ Vector2f(0.2f, 0.1f), Vector3f(0.0f, 0.0f, 1.0f) },
		{ Vector2f(0.0f, 0.7f), Vector3f(1.0f, 1.0f, 1.0f) }
	};
	glGenVertexArrays(2, VAO); //������� 2 VAO (��� ������������ � ��������������)
	glGenBuffers(2, VBO); //������� 2 VBO
	//��������� ����������� � ������ ����������
	//���������� ������ VAO �������
	glBindVertexArray(VAO[0]);
	//����������� ������ VBO � �������� VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	//�������� ������ � ������ ���������� � ������� ��� �� ������������ (GL_STATIC_DRAW)
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleMesh), triangleMesh, GL_STATIC_DRAW);
	//��������� ������������� ���������� ��������
	glEnableVertexAttribArray(VERTEX_ATRIB_POSITION);
	//��������� ��������� ������� ���������� �������� � VBO
	glVertexAttribPointer(VERTEX_ATRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(0));
	//��������� ������������� ���������� ��������
	glEnableVertexAttribArray(VERTEX_ATRIB_COLOR);
	//��������� ��������� ������� ���������� �������� � VBO
	glVertexAttribPointer(VERTEX_ATRIB_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(sizeof(Vector2f)));
	//��������� ������������� � ������ ����������
	//���������� ������ VAO �������
	glBindVertexArray(VAO[1]);
	//����������� ������ VBO � �������� VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	//�������� ������ � ������ ���������� � ������� ��� �� ������������ (GL_STATIC_DRAW)
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadMesh), quadMesh, GL_STATIC_DRAW);
	//��������� ������������� ���������� ��������
	glEnableVertexAttribArray(VERTEX_ATRIB_POSITION);
	//��������� ��������� ������� ���������� �������� � VBO
	glVertexAttribPointer(VERTEX_ATRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(0));
		//��������� ������������� ���������� ��������
		glEnableVertexAttribArray(VERTEX_ATRIB_COLOR);
	//��������� ��������� ������� ���������� �������� � VBO
	glVertexAttribPointer(VERTEX_ATRIB_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(sizeof(Vector2f)));
}
/**
* ������� ������������� ���������� OpenGL
* @param _hWnd �������� ����
*/
void InitOpenGLExt(HWND& _hWnd) {
	hDC = GetDC(_hWnd); //�������� �������� ���������� ��� ������� ����
	PIXELFORMATDESCRIPTOR _pfd = { 0 }; //�������������� ������������� ���������
	_pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR); //������ ���������
	_pfd.dwFlags = PFD_DRAW_TO_WINDOW | //����� � ������� ����
		PFD_SUPPORT_OPENGL | //��������� OpenGL
		PFD_DOUBLEBUFFER; //��������� ������� �����������
	_pfd.iLayerType = PFD_MAIN_PLANE; //��� ����
	_pfd.iPixelType = PFD_TYPE_RGBA; //��������� RGBA �������
	_pfd.cDepthBits = 24; //������ ������ ������� (��������)
	_pfd.cColorBits = 24; //������� ����� (R = 8bit, G = 8bit, B = 8bit)
	_pfd.cAlphaBits = 8; //������� ����� ������
	_pfd.nVersion = 1; //����� ������
	//����� ��������� ���������� ��� ������� ��������
	auto _pixelFormat = ChoosePixelFormat(hDC, &_pfd);
	//���������� ������� ������ �������
	SetPixelFormat(hDC, _pixelFormat, &_pfd);
	//������� ��������� �������� ����������
	auto _hrcFake = wglCreateContext(hDC);
	//������� ������� ����������
	wglMakeCurrent(hDC, _hrcFake);
	//�������� ������ ���������� Windows OpenGL
	OPENGL_GET_PROC(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB);
	OPENGL_GET_PROC(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB);
	//������������ ��������
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(_hrcFake);
}
/**
* ������� ������������� OpenGL
* @param _hWnd �������� ����
*/
void InitOpenGL(HWND& _hWnd) {
	GLint _pixelFormat = 0;
	GLuint _numFormats = 0;
	PIXELFORMATDESCRIPTOR _pfd = { 0 }; //�������������� ������������� ���������
	const GLint _pixelFormatAttribList[] = {
		//WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB, //��������� ����������
		����������
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB, //��������� RGBA �������
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, //����� � ������� ����
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE, //��������� OpenGL
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE, //��������� ������� �����������
		WGL_DEPTH_BITS_ARB, 24, //������ ������ ������� (��������)
		WGL_COLOR_BITS_ARB, 24, //������� ����� (R = 8bit, G = 8bit, B = 8bit)
		WGL_ALPHA_BITS_ARB, 8, //������� ����� ������
		0 // End of attributes list
	};
	GLint _�ontextAttribVersion[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		0 // End of attributes list
	};
	//����� ��������� ���������� ��� ������� ��������
	wglChoosePixelFormatARB(hDC, _pixelFormatAttribList, NULL, 1, &_pixelFormat, &_numFormats);
	//���������� ������� ������ �������
	SetPixelFormat(hDC, _pixelFormat, &_pfd);
	//������� �������� ���������� ��������� ������
	hRC = wglCreateContextAttribsARB(hDC, 0, _�ontextAttribVersion);
	//������� ������� ����������
	wglMakeCurrent(hDC, hRC);
	//�������� ������ "����������" OpenGL
	OPENGL_GET_PROC(PFNGLGENBUFFERSPROC, glGenBuffers);
	OPENGL_GET_PROC(PFNGLBINDBUFFERPROC, glBindBuffer);
	OPENGL_GET_PROC(PFNGLBUFFERDATAPROC, glBufferData);
	OPENGL_GET_PROC(PFNGLUSEPROGRAMPROC, glUseProgram);
	OPENGL_GET_PROC(PFNGLGETSHADERIVPROC, glGetShaderiv);
	OPENGL_GET_PROC(PFNGLLINKPROGRAMPROC, glLinkProgram);
	OPENGL_GET_PROC(PFNGLATTACHSHADERPROC, glAttachShader);
	OPENGL_GET_PROC(PFNGLCREATESHADERPROC, glCreateShader);
	OPENGL_GET_PROC(PFNGLSHADERSOURCEPROC, glShaderSource);
	OPENGL_GET_PROC(PFNGLDELETESHADERPROC, glDeleteShader);
	OPENGL_GET_PROC(PFNGLGETPROGRAMIVPROC, glGetProgramiv);
	OPENGL_GET_PROC(PFNGLDETACHSHADERPROC, glDetachShader);
	OPENGL_GET_PROC(PFNGLCOMPILESHADERPROC, glCompileShader);
	OPENGL_GET_PROC(PFNGLCREATEPROGRAMPROC, glCreateProgram);
	OPENGL_GET_PROC(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
	OPENGL_GET_PROC(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);
	OPENGL_GET_PROC(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);
	OPENGL_GET_PROC(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);
	OPENGL_GET_PROC(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
	OPENGL_GET_PROC(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	OPENGL_GET_PROC(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);
	OPENGL_GET_PROC(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	OPENGL_GET_PROC(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
#if defined(_DEBUG) || defined(DEBUG)
#if defined(_WIN32) || defined(_WINDOWS)
	OutputDebugString("OpenGL Render Context Information:\n");
	OutputDebugString(" Renderer : ");
	OutputDebugString((const char*)glGetString(GL_RENDERER));
		OutputDebugString("\n Vendor : ");
	OutputDebugString((const char*)glGetString(GL_VENDOR));
	OutputDebugString("\n Version : ");
	OutputDebugString((const char*)glGetString(GL_VERSION));
	OutputDebugString("\n GLSL version : ");
	OutputDebugString((const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	OutputDebugString("\n");
#elif defined(__APPLE__)
	NSLog(@"\nOpenGL Render Context Information:"
		@"\n Renderer : %s"
		@"\n Vendor : %s"
		@"\n Version : %s"
		@"\n GLSL version : %s\n",
		glGetString(GL_RENDERER),
		glGetString(GL_VENDOR),
		glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif
#endif
	InitScene(); //�������������� ������������� �����
	LoadShaders(); //�������� ��������
}
/**
* ������� ��������������� �����
* @param _width ������ ������� ���������, � ��������
* @param _height ������ ������� ���������, � ��������
* @param _x ���������� ������� ������ ���� ������� ���������, � ��������.
* �� ��������� 0
* @param _y ���������� ������� ������ ���� ������� ���������, � ��������.
* �� ��������� 0
*/
void Reshape(GLsizei _width, GLsizei _height, GLint _x = 0, GLint _y = 0) {
	if (!_height)
		return;
	//��������� ������� ������� ���������
	glViewport(_x, _y, _width, _height);
}
/**
* ������� ��������� �����
* @param _elapsedTime ���-�� �� ��������� � ������� ������� �������
*/
void DrawScene(GLdouble _elapsedTime) {
	//������� ������ �����
	glClear(GL_COLOR_BUFFER_BIT);
	//���������� ������ VAO (�����������)
	glBindVertexArray(VAO[0]);
	//������ ����������� �� VBO ������������ � VAO
	glDrawArrays(GL_TRIANGLES /* ��� ��������� */, 0 /* ��������� ������ */, 3 /* ���-�� ������ */);
	//���������� ������ VAO (�������������)
	glBindVertexArray(VAO[1]);
	//������ ������������� �� VBO ������������ � VAO
	glDrawArrays(GL_TRIANGLE_STRIP /* ��� ��������� */, 0 /* ��������� ������ */, 4 /* ���-�� ������
																					*/);
}
/**
* ������� ������������ �������� OpenGL
* @param _hWnd �������� ����
*/
void DeInitOpenGL(HWND& _hWnd) {
	glUseProgram(NULL);
	glDeleteProgram(programID);
	glBindVertexArray(NULL);
	glDeleteBuffers(2, VBO);
	glDeleteVertexArrays(2, VAO);
	::wglMakeCurrent(NULL, NULL);
	::wglDeleteContext(hRC);
	::ReleaseDC(_hWnd, hDC);
}
static DWORD startTime = 0;
void CALLBACK DrawTimer(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	DrawScene((dwTime - startTime) / 1000.0); //���������� �����
	SwapBuffers(hDC); //����������� ����� ������
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_ACTIVATE:
		switch (LOWORD(wParam)) {
		case WA_ACTIVE:
		case WA_CLICKACTIVE:
			startTime = GetTickCount();
			::SetTimer(hWnd, UPDATE_TIMER_ID, USER_TIMER_MINIMUM, (TIMERPROC)&DrawTimer);
			break;
		case WA_INACTIVE:
			::KillTimer(hWnd, UPDATE_TIMER_ID);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hWnd);
		break;
	case WM_SIZE:
		Reshape(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_DESTROY:
		::KillTimer(hWnd, UPDATE_TIMER_ID);
		DeInitOpenGL(hWnd);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
		return 0;
}
/**
* ������� ����������� ������ ����
* @param _hInstance ���������� ����
*/
ATOM MyRegisterClass(HINSTANCE& _hInstance) {
	WNDCLASSEX _wcex = { 0 };
	_wcex.cbSize = sizeof(WNDCLASSEX);
	_wcex.style = CS_OWNDC;
	_wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	_wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	_wcex.lpszClassName = windowClassName;
	_wcex.lpfnWndProc = WndProc;
	_wcex.hInstance = _hInstance;
	return RegisterClassEx(&_wcex);
}
/**
* ������� �������� ����
* @param _hInstance ���������� ����
* @param _nCmdShow �������� ������ ����.
*/
BOOL InitInstance(HINSTANCE& _hInstance, int& _nCmdShow) {
	auto _hWnd = CreateWindow(windowClassName, windowTitleName, WS_OVERLAPPED | WS_SYSMENU |
		WS_SIZEBOX, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, _hInstance, NULL);
	if (!_hWnd)
		return FALSE;
	InitOpenGLExt(_hWnd);
	InitOpenGL(_hWnd);
	ShowWindow(_hWnd, _nCmdShow);
	return TRUE;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MyRegisterClass(hInstance);
	if (!InitInstance(hInstance, nCmdShow))
		return FALSE;
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnregisterClass(windowClassName, hInstance);
	return static_cast<int>(msg.wParam);
}