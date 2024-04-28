#include <Application.h>


#include <iostream>




Application::Application() {

	window = std::make_unique<Window>();
}

Application::~Application() {
	
	Terminate();
}

bool Application::Initialize() {


	if (!glfwInit()) {
		std::cerr << "B³¹d inicjalizacji GLFW\n";
		return false;
	}


	window->setOpenGLVersion();

	window->createWindow(640, 480);

	window->initialize();

	window->makeContextCurrentFrame();
	window->setFrameBufferSizeCallback();



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

	
	renderObjectCube = new Cube(*window);

	renderObjectCube->init();

	
	glEnable(GL_DEPTH_TEST);

	MainLoop();
}



void Application::MainLoop()
{
	while (!window->windowShouldClose()) {
		Render();
	}

}

void Application::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	renderObjectCube->render();



	window->swapBuffers();
	glfwPollEvents();
}

void Application::Terminate()
{
	window->destroyWindow();
	glfwTerminate();
}
