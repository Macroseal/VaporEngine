//Brandon Nguyen VaporEngine 2017 - Game.cpp
#include "Game.h"

namespace ve
{
	static const float kMaxFrameTime = 0.25f;
	static const float kTickTime = 1.0f / 60.0f;

	Game::Game(uint32_t windowWidth, uint32_t windowHeight, std::string title)
	{
		//Initialize game data
		mGameDataRef = std::make_shared<GameData>();

		//Initialize main window
		mGameDataRef->mMainWindow.create(sf::VideoMode(windowWidth, windowHeight), title);
	}

	void Game::Run()
	{
		assert(mGameDataRef);
		if (!mGameDataRef)
		{
			return;
		}

		//Get references to game data members
		sf::RenderWindow &mainWindow = mGameDataRef->mMainWindow;
		sf::Clock &mainClock = mGameDataRef->mMainClock;
		ModeController &modeController = mGameDataRef->mModeController;


		//Init timers
		float newTime, frameTime;
		float currentTime = mainClock.getElapsedTime().asSeconds();
		float accumulator = 0;

		while (mainWindow.isOpen())
		{
			//Handle system events
			sf::Event event;
			while (mainWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					mainWindow.close();
				}
			}

			//Handle mode change requests
			modeController.ProcessStateChanges();

			//Update timers
			newTime = mainClock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			if (frameTime > kMaxFrameTime)
			{
				//Limit max frametime
				frameTime = kMaxFrameTime;
			}
			currentTime = newTime;
			accumulator += frameTime;

			//Verify there is an active mode, or close the main window
			const std::shared_ptr<Mode> activeModeRef = modeController.GetActiveMode();
			assert(activeModeRef);
			if(!activeModeRef)
			{
				mainWindow.close();
			}

			while (accumulator >= kTickTime)
			{
				assert(activeModeRef);
				if (activeModeRef)
				{
					activeModeRef->HandleInput();
					activeModeRef->Update(kTickTime);
				}
				accumulator -= kTickTime;
			}

			assert(activeModeRef);
			if (activeModeRef)
			{
				activeModeRef->Draw(accumulator/kTickTime);
			}


			mainWindow.clear();
			//mMainWindow.draw(shape);
			mainWindow.display();
		}
	}
}

