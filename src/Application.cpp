#include "Application.h"
#include <iostream>


Application::Application() {

	window = std::make_unique<Window>();
}

Application::~Application() {
	
	Terminate();
}

void Application::Terminate()
{
	window->destroyWindow();
	glfwTerminate();
}

bool Application::Initialize() {


	if (!glfwInit()) {
		std::cerr << "B³¹d inicjalizacji GLFW\n";
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
		std::cerr << "Nie uda³o siê zainicjalizowaæ biblioteki GLEW\n";
		return false;
	}

	return true;
}

void Application::Run()
{
	// Pobranie wersji OpenGL
    const GLubyte* renderer = glGetString(GL_RENDERER); // pobiera renderer
    const GLubyte* version = glGetString(GL_VERSION); // pobiera wersjê OpenGL

    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;


	/* Game Scene init */
	scene = std::make_unique<Scene>(*window);
	scene->init(); 

	/* ImGui init */
	gui = std::make_unique<GuiHandler>();
	gui->init(*window);

	glEnable(GL_DEPTH_TEST);
	MainLoop();
}



void Application::MainLoop()
{
	while (!window->windowShouldClose()) {

		window->setWindowFocusCallback();
		Render();
	}

}

void Application::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	scene->update();
	scene->render();


	gui->getInfo(&scene->getPlayer());
	gui->render();


	window->swapBuffers();
	glfwPollEvents();
}
