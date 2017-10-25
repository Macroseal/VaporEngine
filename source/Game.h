//Brandon Nguyen VaporEngine 2017 - Game.h

#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "ModeController.h"

namespace ve
{
	struct GameData
	{
		sf::RenderWindow mMainWindow;
		sf::Clock mMainClock;
		ModeController mModeController;
	};

	typedef std::shared_ptr<GameData> GameDataRef;
	class Game
	{
	public:
		Game(uint32_t windowWidth, uint32_t windowHeight, std::string title);
		~Game() {};

		void Run();
	private:

		GameDataRef mGameDataRef;
	};


}

