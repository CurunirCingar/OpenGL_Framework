#pragma comment(lib, "opengl32.lib") //Библиотека для работы с OpenGL
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h> //Заголовочный файл Windows
#include <gl/GL.h> //Заголовочный файл OpenGL
#include <malloc.h> //Заголовочный файл для работы с памятью
#include <time.h> //Заголовочный файл для работы с временем
#include "glext.h" //Заголовочный файл OpenGL Extension
#include "wglext.h" //Заголовочный файл Windows OpenGL Extension
#include "vmath.h" //Заголовочный файл векторной математики
#define UPDATE_TIMER_ID 200
#define VERTEX_ATRIB_COLOR 1
#define VERTEX_ATRIB_POSITION 0
#define BUFFER_OFFSET(i) ((GLbyte*)NULL + (i))
#define OPENGL_GET_PROC(type, func) \
	func = (type)wglGetProcAddress(#func); \
if (!func) \
	OutputDebugString("Loading extension '" #func "' fail\n")
HDC hDC = nullptr; //Контекст устройства
HGLRC hRC = nullptr; //Контекст рендеринга
//Класс окна и заголовок окна
auto windowClassName = "OpenGLApplication";
auto windowTitleName = "OpenGL Application";
//Указатели на функции расширения Windows OpenGL
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
//Указатели на функции расширения OpenGL
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
GLuint programID = 0; //Идентификатор программы
GLuint VBO[2] = { 0 }; //Массив для Vertex Buffer Objects
GLuint VAO[2] = { 0 }; //Массив для Vertex Array Objects
//Необходимые данные для вертекса
struct Vertex {
	Vector2f Position;
	Vector3f Color;
};
/**
* Функция загрузки шейдеров
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
	//Создаем программу
	programID = glCreateProgram();
	//Создаем вершинный шейдер
	auto vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	//Указываем где хранится исходный текст вершинного шейдера
	glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
	//Производим компиляцию шейдера
	glCompileShader(vertexShaderID);
	//Проверям статус коспиляции
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//Получаем размер сообщения
			glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//Выделяем необходимый размер в памяти
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//Получаем сообщение
			glGetShaderInfoLog(vertexShaderID, logLength, &logLength, log);
			//Выводим в окно отладки
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Vertex Shader Compilation Log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Vertex Shader Compilation Log: %s", log);
#endif
			//Освобождаем память
			free(log);
		}
#endif
		//Удаляем шейдер
		glDeleteShader(vertexShaderID);
	}
	//Ассоциируем шейдер с программой
	glAttachShader(programID, vertexShaderID);
	//Создаем пиксельный (фрагментный) шейдер
	auto fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//Указываем где хранится исходный текст пиксельного шейдера
	glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
	//Производим компиляцию шейдера
	glCompileShader(fragmentShaderID);
	//Проверям статус компиляции
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//Получаем размер сообщения
		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//Выделяем необходимый размер в памяти
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//Получаем сообщение
			glGetShaderInfoLog(fragmentShaderID, logLength, &logLength, log);
			//Выводим в окно отладки
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Fragment Shader Compilation Log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Fragment Shader Compilation Log: %s", log);
#endif
			//Освобождаем память
				free(log);
		}
#endif
		//Удаляем шейдер
		glDeleteShader(fragmentShaderID);
	}
	//Ассоциируем шейдер с программой
	glAttachShader(programID, fragmentShaderID);
	//Загружаем программу в память видеокарты
	glLinkProgram(programID);
	//Проверям статус загрузки
	glGetProgramiv(programID, GL_LINK_STATUS, &status);
	if (!status) {
#if defined(_DEBUG) || defined(DEBUG)
		//Получаем размер сообщения
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength) {
			//Выделяем необходимый размер в памяти
			auto log = (GLchar*)calloc(logLength, sizeof(GLchar));
			//Получаем сообщение
			glGetProgramInfoLog(programID, logLength, &logLength, log);
			//Выводим в окно отладки
#if defined(_WIN32) || defined(_WINDOWS)
			OutputDebugString("Program link log:\n");
			OutputDebugString(log);
			OutputDebugString("\n");
#elif defined(__APPLE__)
			NSLog(@"Program link log: %s", log);
#endif
			//Освобождаем память
			free(log);
		}
#endif
		//Удаляем программу
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
	//Делаем активной программной
	glUseProgram(programID);
}
/**
* Функция первоначальной инициализации сцены
*/
void InitScene() {
	//Очистка экрана в черный цвет (Фон)
	glClearColor(0.0f /* Red */, 0.0f /* Green */, 0.0f /* Blue */, 0.0f /* Alpha */);
	//Массив вершин прямоугольника
	Vertex quadMesh[] = {
		{ Vector2f(-0.2f, 0.095f), Vector3f(1.0f, 0.0f, 0.0f) },
		{ Vector2f(-0.2f, -0.5f), Vector3f(0.0f, 1.0f, 0.0f) },
		{ Vector2f(0.2f, 0.095f), Vector3f(0.0f, 0.0f, 1.0f) },
		{ Vector2f(0.2f, -0.5f), Vector3f(1.0f, 1.0f, 0.0f) }
	};
	//Массив вершин треугольника
	Vertex triangleMesh[] = {
		{ Vector2f(-0.2f, 0.1f), Vector3f(1.0f, 0.0f, 0.0f) },
		{ Vector2f(0.2f, 0.1f), Vector3f(0.0f, 0.0f, 1.0f) },
		{ Vector2f(0.0f, 0.7f), Vector3f(1.0f, 1.0f, 1.0f) }
	};
	glGenVertexArrays(2, VAO); //Создать 2 VAO (для треугольника и прямоугольника)
	glGenBuffers(2, VBO); //Создать 2 VBO
	//Загружаем треугольник в память видеокарты
	//Установить первый VAO текущим
	glBindVertexArray(VAO[0]);
	//Привязываем первый VBO к текущему VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	//Копируем массив в память видеокарты и говорим что он неизменяемый (GL_STATIC_DRAW)
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleMesh), triangleMesh, GL_STATIC_DRAW);
	//Разрешить использование вершинного атрибута
	glEnableVertexAttribArray(VERTEX_ATRIB_POSITION);
	//Указываем параметры доступа вершинного атрибута к VBO
	glVertexAttribPointer(VERTEX_ATRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(0));
	//Разрешить использование вершинного атрибута
	glEnableVertexAttribArray(VERTEX_ATRIB_COLOR);
	//Указываем параметры доступа вершинного атрибута к VBO
	glVertexAttribPointer(VERTEX_ATRIB_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(sizeof(Vector2f)));
	//Загружаем прямоугольник в память видеокарты
	//Установить второй VAO текущим
	glBindVertexArray(VAO[1]);
	//Привязываем второй VBO к текущему VAO
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	//Копируем массив в память видеокарты и говорим что он неизменяемый (GL_STATIC_DRAW)
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadMesh), quadMesh, GL_STATIC_DRAW);
	//Разрешить использование вершинного атрибута
	glEnableVertexAttribArray(VERTEX_ATRIB_POSITION);
	//Указываем параметры доступа вершинного атрибута к VBO
	glVertexAttribPointer(VERTEX_ATRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(0));
		//Разрешить использование вершинного атрибута
		glEnableVertexAttribArray(VERTEX_ATRIB_COLOR);
	//Указываем параметры доступа вершинного атрибута к VBO
	glVertexAttribPointer(VERTEX_ATRIB_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		BUFFER_OFFSET(sizeof(Vector2f)));
}
/**
* Функция инициализации расширений OpenGL
* @param _hWnd Контекст окна
*/
void InitOpenGLExt(HWND& _hWnd) {
	hDC = GetDC(_hWnd); //Получить контекст устройства для данного окна
	PIXELFORMATDESCRIPTOR _pfd = { 0 }; //Первоначальная инициализация структуры
	_pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR); //Размер структуры
	_pfd.dwFlags = PFD_DRAW_TO_WINDOW | //Вывод в текущие окно
		PFD_SUPPORT_OPENGL | //Поддержка OpenGL
		PFD_DOUBLEBUFFER; //Поддержка двойной буферизации
	_pfd.iLayerType = PFD_MAIN_PLANE; //Тип слоя
	_pfd.iPixelType = PFD_TYPE_RGBA; //Поддержка RGBA формата
	_pfd.cDepthBits = 24; //Размер буфера глубины (точность)
	_pfd.cColorBits = 24; //Глубина цвета (R = 8bit, G = 8bit, B = 8bit)
	_pfd.cAlphaBits = 8; //Глубина альфа канала
	_pfd.nVersion = 1; //Номер версии
	//Найти ближайшее совпадение для формата пикселов
	auto _pixelFormat = ChoosePixelFormat(hDC, &_pfd);
	//Установить текущий формат пикселя
	SetPixelFormat(hDC, _pixelFormat, &_pfd);
	//Создать временный контекст рендеринга
	auto _hrcFake = wglCreateContext(hDC);
	//Сделать текущим контекстом
	wglMakeCurrent(hDC, _hrcFake);
	//Получить адреса расширений Windows OpenGL
	OPENGL_GET_PROC(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB);
	OPENGL_GET_PROC(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB);
	//Освобождение ресурсов
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(_hrcFake);
}
/**
* Функция инициализации OpenGL
* @param _hWnd Контекст окна
*/
void InitOpenGL(HWND& _hWnd) {
	GLint _pixelFormat = 0;
	GLuint _numFormats = 0;
	PIXELFORMATDESCRIPTOR _pfd = { 0 }; //Первоначальная инициализация структуры
	const GLint _pixelFormatAttribList[] = {
		//WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB, //Поддержка драйверами
		видеокарты
		WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB, //Поддержка RGBA формата
		WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, //Вывод в текущие окно
		WGL_SUPPORT_OPENGL_ARB, GL_TRUE, //Поддержка OpenGL
		WGL_DOUBLE_BUFFER_ARB, GL_TRUE, //Поддержка двойной буферизации
		WGL_DEPTH_BITS_ARB, 24, //Размер буфера глубины (точность)
		WGL_COLOR_BITS_ARB, 24, //Глубина цвета (R = 8bit, G = 8bit, B = 8bit)
		WGL_ALPHA_BITS_ARB, 8, //Глубина альфа канала
		0 // End of attributes list
	};
	GLint _сontextAttribVersion[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		0 // End of attributes list
	};
	//Найти ближайшее совпадение для формата пикселов
	wglChoosePixelFormatARB(hDC, _pixelFormatAttribList, NULL, 1, &_pixelFormat, &_numFormats);
	//Установить текущий формат пикселя
	SetPixelFormat(hDC, _pixelFormat, &_pfd);
	//Создать контекст рендеринга выбранной версии
	hRC = wglCreateContextAttribsARB(hDC, 0, _сontextAttribVersion);
	//Сделать текущим контекстом
	wglMakeCurrent(hDC, hRC);
	//Получить адреса "расширений" OpenGL
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
	InitScene(); //Первоначальная инициализация сцены
	LoadShaders(); //Загрузка шейдеров
}
/**
* Функция масштабирования сцены
* @param _width Ширина области просмотра, в пикселях
* @param _height Высота области просмотра, в пикселях
* @param _x Координаты нижнего левого угла области просмотра, в пикселях.
* По умолчанию 0
* @param _y Координаты нижнего левого угла области просмотра, в пикселях.
* По умолчанию 0
*/
void Reshape(GLsizei _width, GLsizei _height, GLint _x = 0, GLint _y = 0) {
	if (!_height)
		return;
	//Установка текущей области просмотра
	glViewport(_x, _y, _width, _height);
}
/**
* Функция отрисовки сцены
* @param _elapsedTime Кол-во мс прошедших с момента запуска таймера
*/
void DrawScene(GLdouble _elapsedTime) {
	//Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT);
	//Используем первый VAO (треугольник)
	glBindVertexArray(VAO[0]);
	//Рисуем треугольник из VBO привязанного к VAO
	glDrawArrays(GL_TRIANGLES /* Вид примитива */, 0 /* начальный индекс */, 3 /* кол-во вершин */);
	//Используем второй VAO (прямоугольник)
	glBindVertexArray(VAO[1]);
	//Рисуем прямоугольник из VBO привязанного к VAO
	glDrawArrays(GL_TRIANGLE_STRIP /* Вид примитива */, 0 /* начальный индекс */, 4 /* кол-во вершин
																					*/);
}
/**
* Функция освобождения ресурсов OpenGL
* @param _hWnd Контекст окна
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
	DrawScene((dwTime - startTime) / 1000.0); //Нарисовать сцену
	SwapBuffers(hDC); //Переключить буфер экрана
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
* Функция регистрации класса окна
* @param _hInstance Дескриптор окна
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
* Функция создания окна
* @param _hInstance Дескриптор окна
* @param _nCmdShow Параметр показа окна.
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