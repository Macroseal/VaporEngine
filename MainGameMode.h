#pragma once
#include "Mode.h"

namespace ve
{
	class MainGameMode : public Mode
	{
	public:
		MainGameMode()
			: Mode(ModeType::MainGame)
		{}

		~MainGameMode() {};

		

	};
}

