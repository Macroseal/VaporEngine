//Brandon Nguyen VaporEngine 2017- Game.h
#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"

namespace ve
{
	class Game
	{
	public:
		Game();
		~Game() {};

		void HandleInput();
		void Update();
		void Render();

		sf::Time GetElapsed() const { return mClock.getElapsedTime(); }
		void RestartClock() { mElapsed = mClock.restart(); }

		const Window& GetWindow() const { return mWindow; }

	private:
		Window mWindow;
		sf::Clock mClock;
		sf::Time mElapsed;
	};

} //ve