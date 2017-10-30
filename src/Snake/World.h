//Brandon Nguyen VaporEngine 2017- World.h
#pragma once

#include <Vector>
#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Snake.h"

namespace ve
{
	class Window;
}

namespace Snake
{
	class World
	{
	public:
		World()
			: mWidth(0)
			, mHeight()
			, mSnake()
			, mPickupPosVect()
			, mPickupShape()
		{}

		World(const sf::Vector2u &windowSize);
		~World() {}

		void Update();
		void Render(ve::Window &window);

		Snake& GetSnake() { return mSnake; };

		static sf::Uint32 GetTileSize();

	private:
		void GetStartPos(sf::Vector2i &outStartPos) const;
		bool CheckEdgeCollisions() const;
		bool TryProcessPickupCollision();
		void TrySpawnPickups();
		void ResetGame();

		sf::Uint32 mWidth;
		sf::Uint32 mHeight;
		Snake mSnake;
		std::vector<sf::Vector2i> mPickupPosVect;
		sf::CircleShape mPickupShape;
		sf::Text mScoreText;
		sf::Font mScoreFont;
		sf::Uint32 mScore;
	};
}