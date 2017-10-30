//Brandon Nguyen VaporEngine 2017- main.cpp

#include "Game.h"

void main(int argc, char** argv[])
{
	ve::Game game;
	while (!game.GetWindow().GetIsDone())
	{
		game.ProcessInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
}
