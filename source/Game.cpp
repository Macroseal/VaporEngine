//Brandon Nguyen VaporEngine 2017- Game.cpp

#include "Game.h"

namespace ve
{
	Game::Game()
	{
		mTexture.loadFromFile("mushroom.png");
		mSprite.setTexture(mTexture);
		mIncrement = sf::Vector2f(0.5, 0.5);
	}

	void Game::HandleInput()
	{
		mWindow.update
	}
	void Game::Update()
	{
	}
	void Game::Render()
	{
	}
	void Game::MoveMushroom()
	{
	}
} //ve