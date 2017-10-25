//Brandon Nguyen VaporEngine 2017- Mode.h
#pragma once

#include "stdint.h"

namespace ve
{
	enum class ModeType : uint32_t
	{
		None = 0,
		MainMenu,
		MainGame,
	};

	class Mode
	{
	public:
		Mode(ModeType modeType) 
			: mModeType(ModeType::None)
		{};
		virtual ~Mode() {};

		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update() = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() {}
		virtual void Resume() {}

		ModeType GetModeType() const { return mModeType; }

	private:
		ModeType mModeType;
	};
}