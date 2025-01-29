#include "ManageBoards.h"

#include <iostream>

ManageBoards::ManageBoards(MvpComponent* mvpComponent, const Player& player) : player(player), hasLoadedBoard(false)
{
	// set terrain position
	//mvpComponent->setModel(glm::vec3(0.0f, 0.0f, -20.0f));

	// set board 
	for (int x = 0; x < BOARD_WIDTH; ++x) {
		for (int z = 0; z < BOARD_HEIGHT; ++z) {

			glm::vec3 boardPosition = glm::vec3(x * CubeBoard::CHUNK_SIZE, 0, z * CubeBoard::CHUNK_SIZE);
			cubeBoards.push_back(std::make_unique<CubeBoard>(boardPosition, std::move(mvpComponent)));
		}
	}

}

void ManageBoards::loadCubeBoard(CubeBoard& cubeBoard)
{
	// save to ram memory at first time
	loadedBoards.push_back(&cubeBoard);
	
	hasLoadedBoard = true;

	if (!unloadedBoards.empty())
		unloadedBoards.clear();

}

void ManageBoards::unLoadCubeBoard(CubeBoard& cubeBoard)
{
	// after unload, we save it on disk to .bin file
	unloadedBoards.push_back(&cubeBoard);

	hasLoadedBoard = false;

	if (!loadedBoards.empty())
		loadedBoards.clear();
}

inline bool ManageBoards::IsinRenderedDistance(const Player& player, const CubeBoard& cubeboard)
{
	if (glm::distance(player.getPosition(), cubeboard.getPosition()) <= renderDistance) {

		return true;
	}

	return false;
}

void ManageBoards::render(MvpComponent* mvpComponent)
{

	for (const auto& cubeboard : cubeBoards) {

		if (IsinRenderedDistance(player, *cubeboard)) {
			
			if (!hasLoadedBoard) {

				loadCubeBoard(*cubeboard);

				if (!unloadedBoards.empty()) {

					unloadedBoards.clear();
				}
			}

		}
		else {

			unLoadCubeBoard(*cubeboard);
			loadedBoards.clear();

		}
	}

	for (auto& loadedBoard : loadedBoards) {

		if (IsinRenderedDistance(player, *loadedBoard)) {
			
			//std::cout << loadedBoard->getPosition().x << ", " << loadedBoard->getPosition().z << "\n";

			//mvpComponent->setModel(glm::vec3(0.0f, 0.01f, 0.0f));

			loadedBoard->init();
			loadedBoard->render();
		}
	}

	for (auto& unloadedBoard : unloadedBoards) {

		if (!IsinRenderedDistance(player, *unloadedBoard)) {

			unloadedBoard->destroyBuffers();

		}
	}

		
}
