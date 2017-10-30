//Brandon Nguyen VaporEngine 2017- Snake.h
#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

namespace ve
{
	class Window;
}

namespace Snake
{
	struct SnakeSegment
	{
		SnakeSegment(const sf::Vector2i &pos) 
			: mPos(pos)
		{}

		sf::Vector2i mPos;
	};

	enum class Direction
	{
		None,
		Up,
		Down,
		Left,
		Right
	};

	typedef std::vector<SnakeSegment> SegmentVect;

	class Snake
	{
	public:
		Snake();
		~Snake() {};

		void Init(const sf::Vector2i &startingPos);

		void Update();
		void Render(ve::Window &window);

		void Extend();

		Direction GetDirection() const { return mDirection; }
		void SetDirection(Direction dir);

		sf::Uint32 GetSpeed() const { return mSpeed; }
		bool GetCollidedWithSelf() const { return mCollidedWithSelf; }

		const sf::Vector2i& GetHeadPos() const { return mSnakeBody.front().mPos;};

	private:
		void UpdateSegmentPositions();
		void CheckSelfCollision();
		bool CanMove() const { return mDirection != Direction::None && mSpeed > 0; }
		Direction GetInferredDirection() const;
		
		SegmentVect mSnakeBody;
		Direction mDirection;
		sf::Uint32 mSpeed;
		sf::RectangleShape mSegmentShape;
		bool mCollidedWithSelf;
	};

}