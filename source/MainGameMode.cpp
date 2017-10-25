//Brandon Nguyen VaporEngine 2017 - MainGameMode.cpp

#include "MainGameMode.h"

#include <SFML\Graphics.hpp>

namespace ve
{
	void MainGameMode::Init()
	{
		//Temp paddle initialization
		mPlayerPaddle.setSize(sf::Vector2f(30.0f, 30.0f));
		mPlayerPaddle.setPosition(sf::Vector2f(10.0f, 10.0f));
		mPlayerPaddle.setFillColor(sf::Color::Blue);
	}

	void MainGameMode::HandleInput()
	{
	}

	void MainGameMode::Update(float dt)
	{
		float speed = 3;

		//translate to the right every frame
		sf::Vector2f oldPos = mPlayerPaddle.getPosition();
		sf::Vector2f newPos = sf::Vector2f(oldPos.x + (speed), oldPos.y);
		mPlayerPaddle.setPosition(newPos);

		sf::Color oldColor = mPlayerPaddle.getFillColor();
		sf::Color newColor = sf::Color(oldColor.r + (speed), oldColor.g, oldColor.b, 255);
		mPlayerPaddle.setFillColor(newColor);
	}

	void MainGameMode::Draw(sf::RenderWindow &renderWindow)
	{
		renderWindow.draw(mPlayerPaddle);
	}

	void MainGameMode::Pause()
	{
	}

	void MainGameMode::Resume()
	{
	}
}

