#pragma once

#include "Cube.h"
#include "Camera.h"
#include "CameraMoving.h"

#include "CubeRenderComponent.h"
#include "GrassTextureComponent.h"
#include "CubeBoard.h"

#include "Player.h" // with playerViewComponent included

class Scene
{
private:

	// cube stuff
	std::unique_ptr<RenderComponent> cubeRender;
	std::unique_ptr<TextureComponent> cubeGrassTexture;
	std::unique_ptr<ShaderComponent> cubeShader;
	std::unique_ptr<BufferComponent> cubeBuffer;
	
	std::unique_ptr<Cube> cubeMesh;
	std::unique_ptr<CubeBoard> cubeBoard;

	// player stuff
	std::unique_ptr<PlayerViewComponent> playerView; // it has camera handling
	std::unique_ptr<Player> player;

	MvpComponent* mvpComponent;

	const IWindow& window;

public:
	explicit Scene(const IWindow&);
	~Scene();

	void init();
	void render();
	void update();

	Player& getPlayer() const;
};

