#pragma once

#include "PlayerViewComponent.h"

class Player {
private:
	std::unique_ptr<PlayerViewComponent> playerViewComponent;
	glm::vec3 position;

public:
	explicit Player(std::unique_ptr<PlayerViewComponent> playerViewComponent) : 
		playerViewComponent(std::move(playerViewComponent)), 
		position(0) { }

	void init();
	void update(const IWindow& window);

	glm::vec3 getPosition() const;
};