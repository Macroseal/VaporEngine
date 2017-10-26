//Brandon Nguyen VaporEngine 2017 - PongMode.h

#pragma once
#include "Mode.h"

#include <SFML/Graphics/RectangleShape.hpp>

namespace ve
{
	class PongMode : public Mode
	{
	public:
		PongMode()
			: Mode(ModeType::Pong)
		{}

		~PongMode() {};

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(sf::RenderWindow &renderWindow) override;

		void Pause() override;
		void Resume() override;

	private:
		sf::RectangleShape mPlayerPaddle;

	};
}

