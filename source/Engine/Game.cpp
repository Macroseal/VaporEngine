//Brandon Nguyen VaporEngine 2017- Game.cpp

#include "Game.h"

static constexpr const char* kWindowName = "MyGame";
static constexpr sf::Uint32 kWindowWidth = 800;
static constexpr sf::Uint32 kWindowHeight = 600;
static constexpr float kFrameTime = 1.0f / 60.f;

namespace ve
{
	Game::Game()
		: mWindow(kWindowName, sf::Vector2u(kWindowWidth, kWindowHeight))
	{
	}

	void Game::HandleInput()
	{
		
	}

	void Game::Update()
	{
		mWindow.Update();
	}

	void Game::Render()
	{
		mWindow.BeginDraw();
		/*mWindow.Draw(mSprite);*/
		mWindow.EndDraw();
	}
} //ve