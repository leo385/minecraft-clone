#include "Application.h"
#include <iostream>

Application::Application() {

	window = std::make_unique<Window>();
}

Application::~Application() {
	
	Terminate();
}

bool Application::Initialize() {


	if (!glfwInit()) {
		std::cerr << "B��d inicjalizacji GLFW\n";
		return false;
	}


	window->setOpenGLVersion();

	window->createWindow(1920, 1080);

	window->initialize();

	window->makeContextCurrentFrame();
	window->setFrameBufferSizeCallback();
	window->setCursorDisabled();

	window->setWindowFocusAttrib();
	window->setCursorPositionCallback();

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cerr << "Nie uda�o si� zainicjalizowa� biblioteki GLEW\n";
		return false;
	}

	return true;
}

void Application::Run()
{
	// Pobranie wersji OpenGL
    const GLubyte* renderer = glGetString(GL_RENDERER); // pobiera renderer
    const GLubyte* version = glGetString(GL_VERSION); // pobiera wersj� OpenGL

    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;

	scene = std::make_unique<Scene>(*window);
	scene->init(); 

	glEnable(GL_DEPTH_TEST);

	MainLoop();
}



void Application::MainLoop()
{
	while (!window->windowShouldClose()) {

		window->setWindowFocusCallback();
		//window->setCursorPos();

		Render();

	}

}

void Application::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	scene->handleInput();
	scene->render();

	

	window->swapBuffers();
	glfwPollEvents();
}

void Application::Terminate()
{
	window->destroyWindow();
	glfwTerminate();
}