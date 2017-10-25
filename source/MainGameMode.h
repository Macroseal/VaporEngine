//Brandon Nguyen VaporEngine 2017 - MainGameMode.h

#pragma once
#include "Mode.h"

#include <SFML/Graphics/Rect.hpp>

namespace ve
{
	class MainGameMode : public Mode
	{
	public:
		MainGameMode()
			: Mode(ModeType::MainGame)
		{}

		~MainGameMode() {};

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

		void Pause() override;
		void Resume() override;

	private:
		sf::Graphics::rect mPlayerPaddle;

	};
}

