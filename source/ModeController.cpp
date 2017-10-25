//Brandon Nguyen VaporEngine 2017- ModeController.cpp
#include "ModeController.h"

namespace ve
{
	void ModeController::RequestModePush(ModeType modeType, bool replaceTop /*= false*/)
	{
		ModeRequestParameters params;
		params.InitPush(modeType, replaceTop);
		mRequestQueue.push(params);
	}

	void ModeController::RequestModePop(ModeType modeType)
	{
		ModeRequestParameters params;
		params.InitPop(modeType);
		mRequestQueue.push(params);
	}

	void ModeController::ProcessStateChanges()
	{
		//If request queue is empty, don't need to do anything
		if (mRequestQueue.empty())
		{
			return;
		}

		ModeRequestParameters &params = mRequestQueue.front();
		if (params.mIsPush)
		{
			//Push new mode
			ApplyModePush(params.mModeType, params.mReplaceTop);
		}
		else
		{
			//Pop top mode
			ApplyModePop(params.mModeType);
		}

		mRequestQueue.pop();
	}

	ModeRef ModeController::GetActiveMode() const
	{
		if (!mModeStack.empty())
		{
			return mModeStack.top();
		}
		return nullptr;
	}

	ModeRef ModeController::BuildMode(ModeType modeType) const
	{
		switch (modeType)
		{
		case ModeType::MainGame:
			assert(false && "Not implemented yet");
			break;
		default:
			assert(false && "Invalid ModeType in ModeController::BuildMode");
			break;
		}

		return nullptr;
	}

	void ModeController::ApplyModePush(ModeType modeType, bool replaceTop)
	{
		ModeRef newModeRef = BuildMode(modeType);
		assert(newModeRef);
		assert(mModeStack.top());
		if (newModeRef && mModeStack.top())
		{
			if (replaceTop)
			{
				mModeStack.pop();
			}
			else
			{
				mModeStack.top()->Pause();
			}
			mModeStack.push(newModeRef);
		}
	}

	void ModeController::ApplyModePop(ModeType modeType)
	{
		assert(!mModeStack.empty());
		if (mModeStack.empty())
		{
			return;
		}

		bool popTopMode = true;
		assert(mModeStack.top());
		if (mModeStack.top())
		{
			//Ensure top mode is the mode requested to close
			ModeType topModeType = mModeStack.top()->GetModeType();
			assert(modeType == topModeType);
			if (modeType != topModeType)
			{
				popTopMode = false;
			}
		}

		if (popTopMode)
		{
			mModeStack.pop();

			assert(mModeStack.top());
			if (mModeStack.top())
			{
				mModeStack.top()->Resume();
			}
		}
	}

	void ModeController::ModeRequestParameters::InitPush(ModeType modeType, bool replaceTop)
	{
		mModeType = modeType;
		mIsPush = true;
		mReplaceTop = replaceTop;
	}

	void ModeController::ModeRequestParameters::InitPop(ModeType modeType)
	{
		mModeType = modeType;
		mIsPush = false;
	}
}