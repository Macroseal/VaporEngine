//Brandon Nguyen VaporEngine 2017- Snake.cpp

#include "Snake.h"

#include "World.h"
#include "../Engine/Window.h"

static constexpr sf::Uint32 kStartSpeed = 3;
static constexpr sf::Uint32 kSpeedIncrement = 1;
static constexpr sf::Uint32 kStartingSize = 3;

namespace Snake
{
	Snake::Snake()
		: mSnakeBody()
		, mDirection(Direction::None)
		, mSpeed(0)
		, mSegmentShape(sf::Vector2f(static_cast<float>(World::GetTileSize()), static_cast<float>(World::GetTileSize())))
		, mCollidedWithSelf(false)
	{}

	void Snake::Init(const sf::Vector2i &startingPos)
	{
		mSnakeBody.clear();
		//Initialize starting segments
		SnakeSegment seg(startingPos);
		for (sf::Uint32 i = 0; i < kStartingSize; i++)
		{
			mSnakeBody.push_back(seg);
			seg.mPos.y++;
		}

		//Initialize starting parameters
		SetDirection(Direction::None);
		mSpeed = kStartSpeed;
		mCollidedWithSelf = false;
	}

	void Snake::Update()
	{
		//Move segments
		UpdateSegmentPositions();

		//Check for collisions
		CheckSelfCollision();
	}

	void Snake::Render(ve::Window & window)
	{
		//Draw each segment of the snake
		auto it = mSnakeBody.begin();
		auto end = mSnakeBody.end();
		for (; it != end; it++)
		{
			sf::Color color = it == mSnakeBody.begin() ? sf::Color::Green : sf::Color::Blue;
			mSegmentShape.setFillColor(color);

			const sf::Vector2f pos(static_cast<float>(it->mPos.x * World::GetTileSize()), static_cast<float>(it->mPos.y * World::GetTileSize()));
			mSegmentShape.setPosition(pos);
			window.Draw(mSegmentShape);
		}
	}

	void Snake::Extend()
	{
		if (mSnakeBody.size() <= 2)
		{
			return;
		}

		auto end = mSnakeBody.end();
		const sf::Vector2i &tailPos = (end - 1)->mPos;
		const sf::Vector2i &tailNextPos = (end - 2)->mPos;

		if (tailNextPos.x > tailPos.x)
		{
			//We are moving right so add to the left
			mSnakeBody.push_back(sf::Vector2i(tailPos.x - 1, tailPos.y));
		}
		else if (tailNextPos.x < tailPos.x)
		{
			//We are moving left so add to the right
			mSnakeBody.push_back(sf::Vector2i(tailPos.x + 1, tailPos.y));
		}
		else if (tailNextPos.y > tailPos.y)
		{
			//We are moving down so add up
			mSnakeBody.push_back(sf::Vector2i(tailPos.x, tailPos.y - 1));
		}
		else if (tailNextPos.y < tailPos.y)
		{
			//We are moving up so add down
			mSnakeBody.push_back(sf::Vector2i(tailPos.x, tailPos.y + 1));
		}

		mSpeed += kSpeedIncrement;
	}

	void Snake::SetDirection(Direction dir)
	{
		//Don't allow direction to be set to the opposite of the inferred direction
		Direction inferredDir = GetInferredDirection();
		switch (dir)
		{
		case Direction::Up:
			mDirection = inferredDir == Direction::Down ? inferredDir : dir;
			break;
		case Direction::Down:
			mDirection = (inferredDir == Direction::Up || inferredDir == Direction::None) ? inferredDir : dir;
			break;
		case Direction::Left:
			mDirection = inferredDir == Direction::Right ? inferredDir : dir;
			break;
		case Direction::Right:
			mDirection = inferredDir == Direction::Left ? inferredDir : dir;
			break;
		default:
			mDirection = dir;
			break;
		}
	}

	void Snake::UpdateSegmentPositions()
	{
		if (mSnakeBody.size() == 0 || !CanMove())
		{
			return;
		}

		//Each segment will receive the position of the previous segment
		auto rit = mSnakeBody.rbegin();
		auto rend = mSnakeBody.rend();
		for (; rit != rend; rit++)
		{
			//Set to the next segment's position if there is one
			if (rit + 1 != rend)
			{
				rit->mPos = (rit + 1)->mPos;
			}
		}

		//Update the first segment's position
		sf::Vector2i &headPos = mSnakeBody.front().mPos;
		switch (mDirection)
		{
		case Direction::Up:
			headPos.y--;
			break;
		case Direction::Down:
			headPos.y++;
			break;
		case Direction::Left:
			headPos.x--;
			break;
		case Direction::Right:
			headPos.x++;
			break;
		default:
			break;
		}
	}

	void Snake::CheckSelfCollision()
	{
		if (mSnakeBody.empty() || !CanMove())
		{
			return;
		}

		const sf::Vector2i &headPos = GetHeadPos();
		for (auto it = mSnakeBody.begin() + 1; it != mSnakeBody.end(); it++)
		{
			if (headPos == it->mPos)
			{
				mCollidedWithSelf = true;
				return;
			}
		}
	}
	Direction Snake::GetInferredDirection() const
	{
		if (mSnakeBody.size() <= 2)
		{
			return Direction::None;
		}

		const sf::Vector2i &headPos = GetHeadPos();
		const sf::Vector2i &headNextPos = (mSnakeBody.begin()+1)->mPos;

		if (headPos.x > headNextPos.x)
		{
			return Direction::Right;
		}
		else if (headPos.x < headNextPos.x)
		{
			return Direction::Left;
		}
		else if (headPos.y > headNextPos.y)
		{
			return Direction::Down;
		}
		else if (headPos.y < headNextPos.y)
		{
			return Direction::Up;
		}
		return Direction::None;
	}
}