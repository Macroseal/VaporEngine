//Brandon Nguyen VaporEngine 2017 - Application.h

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
	class Application
	{
	public:
		Application(uint32_t windowWidth, uint32_t windowHeight, std::string title);
		~Application() {};

		void Run();
	private:

		GameDataRef mGameDataRef;
	};


}

