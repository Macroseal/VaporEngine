//Brandon Nguyen VaporEngine 2017- ModeController.h
#pragma once

#include <cassert>
#include <Memory>
#include <Stack>
#include <Queue>

#include "Mode.h"

namespace ve
{
	typedef std::shared_ptr<Mode> ModeRef;

	class ModeController
	{
	public:
		ModeController() {}
		~ModeController() {}

		void RequestModePush(ModeType modeType, bool replaceTop = true);
		void RequestModePop(ModeType modeType);

		void ProcessStateChanges();
		ModeRef GetActiveMode() const;

	private:

		struct ModeRequestParameters
		{
			ModeRequestParameters()
				: mModeType(ModeType::None)
				, mIsPush(false)
				, mReplaceTop(false)
			{}

			void InitPush(ModeType modeType, bool replaceTop);
			void InitPop(ModeType modeType);

			ModeType mModeType;
			bool mIsPush;
			bool mReplaceTop;
		};

		ModeRef BuildMode(ModeType modeType) const;
		void ApplyModePush(ModeType modeType, bool replaceTop);
		void ApplyModePop(ModeType modeType);

		std::queue<ModeRequestParameters> mRequestQueue;
		std::stack<ModeRef> mModeStack;
	};
}