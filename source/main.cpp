//Brandon Nguyen VaporEngine 2017- main.cpp

#include "Game.h"

int main()
{
	//Initialize main game and let it run
	std::unique_ptr<ve::Game> gameUniqueRef = std::make_unique<ve::Game>(500, 500, "Pong");
	gameUniqueRef->Run();

	return 0;
}