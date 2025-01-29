#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "CubeBoard.h"
#include "Player.h"

typedef std::unique_ptr<CubeBoard> UniqueCubeBoard;

#define BOARD_WIDTH 1
#define BOARD_HEIGHT 1

class ManageBoards {
private:

	std::vector<UniqueCubeBoard> cubeBoards;

	std::vector<CubeBoard*> loadedBoards;
	std::vector<CubeBoard*> unloadedBoards;

	const Player& player;

	void loadCubeBoard(CubeBoard&);
	void unLoadCubeBoard(CubeBoard&);

	bool hasLoadedBoard;
	inline bool IsinRenderedDistance(const Player&, const CubeBoard&);

	const float renderDistance = 10.0f;

public:
	ManageBoards(MvpComponent* mvpComponent, const Player& player);

	void render(MvpComponent* mvpComponent);
};