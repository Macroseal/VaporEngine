//Brandon Nguyen VaporEngine 2017- World.h
#include "World.h"

#include <string>
#include "../Engine/Window.h"

namespace Snake
{
	static constexpr sf::Uint32 kTileSize = 16; //in pixels
	static constexpr sf::Uint32 kMaxPickups = 1;
	static constexpr const char* kFontPath = "E:\\Development\\SFML\\VaporEngine\\res\\Roboto-Black.ttf";

	World::World(const sf::Vector2u & windowSize)
		: mScore(0)
	{
		mWidth = windowSize.x / kTileSize;
		mHeight = windowSize.y / kTileSize;

		//Initialize snake
		sf::Vector2i startPos;
		GetStartPos(startPos);
		mSnake.Init(startPos);

		//Init pickup shape
		mPickupShape.setFillColor(sf::Color::Red);
		mPickupShape.setRadius(kTileSize *0.5f);

		//Init score text
		mScoreFont.loadFromFile(kFontPath);
		mScoreText.setFont(mScoreFont);
		mScoreText.setPosition({ 10, 10 });
	}

	void World::Update()
	{
		//Spawn pickups if needed
		TrySpawnPickups();

		//Update snake
		mSnake.Update();

		if (mSnake.GetCollidedWithSelf())
		{
			//Check if snake has collided with self
			ResetGame();
		}
		else if (CheckEdgeCollisions())
		{
			//Check if snake has collided with edges of map
			ResetGame();
		}
		else if (TryProcessPickupCollision())
		{
			//Increase snake length
			mSnake.Extend();
		}

		//Set score text
		std::string scoreText = "Score: " + std::to_string(mScore);
		mScoreText.setString(scoreText);
	}

	void World::Render(ve::Window &window)
	{
		//Render snake
		mSnake.Render(window);

		//Render pickups
		for (const sf::Vector2i &pos : mPickupPosVect)
		{
			mPickupShape.setPosition(sf::Vector2f(static_cast<float>(pos.x * kTileSize), static_cast<float>(pos.y * kTileSize)));
			window.Draw(mPickupShape);
		}

		//Render score text
		window.Draw(mScoreText);
	}

	sf::Uint32 World::GetTileSize()
	{
		return kTileSize;
	}

	void World::GetStartPos(sf::Vector2i & outStartPos) const
	{
		outStartPos = sf::Vector2i(static_cast<int>(mWidth * 0.5f), static_cast<int>(mHeight * 0.5f));
	}

	bool World::CheckEdgeCollisions() const
	{
		const sf::Vector2i& headPos = mSnake.GetHeadPos();
		if (headPos.x < 0 || headPos.x >= mWidth || headPos.y < 0 || headPos.y >= mHeight)
		{
			return true;
		}
		return false;
	}

	bool World::TryProcessPickupCollision()
	{
		const sf::Vector2i& headPos = mSnake.GetHeadPos();
		auto it = mPickupPosVect.begin();
		bool collided = false;
		for (; it != mPickupPosVect.end(); it++)
		{
			if (headPos == (*it))
			{
				collided = true;
				break;
			}
		}

		//Remove pickup if collision occured
		if (collided)
		{
			mPickupPosVect.erase(it);
			mScore++;
		}

		return collided;
	}

	void World::TrySpawnPickups()
	{
		if (mPickupPosVect.size() >= kMaxPickups)
		{
			return;
		}

		//Get random coordinates to spawn pickup
		sf::Uint32 randX = std::rand() % (mWidth); //rand between 0 - mWidth-1
		sf::Uint32 randY = std::rand() % (mHeight); //rand between 0 - mWidth-1
		mPickupPosVect.push_back(sf::Vector2i(randX, randY));
	}

	void World::ResetGame()
	{
		sf::Vector2i startPos;
		GetStartPos(startPos);
		mSnake.Init(startPos);
		mPickupPosVect.clear();
	}
}