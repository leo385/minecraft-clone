#include "Scene.h"

#include <iostream>


Scene::Scene(const IWindow& window) : window(window){


	mvpComponent = new MvpComponent();
	playerView = std::make_unique<PlayerViewComponent>(*mvpComponent);

	//cubeRender = std::make_unique<CubeRenderComponent>();
	//cubeGrassTexture = std::make_unique<GrassTextureComponent>();
	//cubeShader = std::make_unique<ShaderComponent>();
	//cubeBuffer = std::make_unique<BufferComponent>();

}

Scene::~Scene()
{
	if (!mvpComponent)
		delete mvpComponent;
	
}

void Scene::init()
{
	
	// player stuff
	player = std::make_unique<Player>(std::move(playerView));
	player->init();

	// set global view rotate mvp
	mvpComponent->setViewRotate(-55.0f, glm::vec3(0.0f, 0.0f, 0.0f));

	// set global projection mvp
	mvpComponent->setProjection(static_cast<float>(window.getWidth()) / static_cast<float>(window.getHeight()));

	// cube stuff
	/*cubeMesh = std::make_unique<Cube>(std::move(cubeRender), std::move(mvpComponent), std::move(cubeGrassTexture), std::move(cubeShader), std::move(cubeBuffer));
	cubeBoard = std::make_unique<CubeBoard>(*cubeMesh, std::move(cubeBuffer));*/

	//cubeBoard->init();

	// Create big cube terrain
	manageBoard = std::make_unique<ManageBoards>(std::move(mvpComponent), *player);
	
	//manageBoard->init();
}

void Scene::render()
{
	//cubeBoard->render();
	manageBoard->render(mvpComponent);
}

void Scene::update()
{
	player->update(window);
}

Player& Scene::getPlayer() const
{
	return *player;
}
