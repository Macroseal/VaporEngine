//Brandon Nguyen VaporEngine 2017- Game.h
#pragma once

#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>

static constexpr const char* kWindowName = "MyGame";
static constexpr sf::Uint32 kWindowWidth = 800;
static constexpr sf::Uint32 kWindowHeight = 600;

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

		const sf::Window& GetWindow() const { return mWindow; }

	private:
		void MoveMushroom();
		sf::Window mWindow;

		//Temp code
		sf::Texture mTexture;
		sf::Sprite mSprite;
		sf::Vector2f mIncrement
	};

} //ve