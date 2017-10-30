//Brandon Nguyen VaporEngine 2017- Game.h
#pragma once

#include <SFML/Graphics.hpp>

#include "../Snake/World.h"

#include "Window.h"

namespace ve
{
	class Game
	{
	public:
		Game();
		~Game() {};

		void ProcessInput();
		void Update();
		void Render();

		void RestartClock() { mElapsed += mClock.restart().asSeconds(); }

		const Window& GetWindow() const { return mWindow; }

	private:
		Window mWindow;
		sf::Clock mClock;
		float mElapsed;

		Snake::World mSnakeWorld;
	};

} //ve