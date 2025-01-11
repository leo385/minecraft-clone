#include "Player.h"


void Player::init()
{
	playerViewComponent->init();
}

void Player::update(const IWindow& window)
{
	playerViewComponent->update(window);

	// Here is camera position now, but it's important to add player position to camera position
	position = playerViewComponent->getPos();

}

glm::vec3 Player::getPosition() const
{
	return position;
}
