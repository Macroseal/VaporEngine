//Brandon Nguyen VaporEngine 2017- Game.cpp

#include "Game.h"
#include "../Snake/Snake.h"

static constexpr const char* kWindowName = "MyGame";
static constexpr sf::Uint32 kWindowWidth = 480;
static constexpr sf::Uint32 kWindowHeight = 480;
static constexpr float kFrameTime = 1.0f / 60.f;

namespace ve
{
	Game::Game()
		: mWindow(kWindowName, sf::Vector2u(kWindowWidth, kWindowHeight))
		, mClock()
		, mElapsed()
		, mSnakeWorld(sf::Vector2u(kWindowWidth, kWindowHeight))
	{}

	void Game::ProcessInput()
	{
		Snake::Snake &snake = mSnakeWorld.GetSnake();

		//Handle input to control snake
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			snake.SetDirection(Snake::Direction::Up);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			snake.SetDirection(Snake::Direction::Down);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			snake.SetDirection(Snake::Direction::Left);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			snake.SetDirection(Snake::Direction::Right);
		}
	}

	void Game::Update()
	{
		mWindow.Update();

		Snake::Snake &snake = mSnakeWorld.GetSnake();
		float timeStep = 1.0f / snake.GetSpeed();
		if (mElapsed >= timeStep)
		{
			//Update snake world
			mSnakeWorld.Update();

			//Update elapsed timer
			mElapsed -= timeStep;
		}
	}

	void Game::Render()
	{
		mWindow.BeginDraw();
		mSnakeWorld.Render(mWindow);
		mWindow.EndDraw();
	}
} //ve