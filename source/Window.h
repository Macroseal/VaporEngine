//Brandon Nguyen VaporEngine 2017- Window.h

#pragma once
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace ve
{
	class Window
	{
	public:
		Window(const std::string& title, const sf::Vector2u& size);
		~Window();

		void BeginDraw();
		void Draw(sf::Drawable& drawable);
		void EndDraw();

		void Update();

		bool GetIsDone() const { return mIsDone; }
		bool GetIsFullscreen() const { return mIsFullscreen; }
		const sf::Vector2u& GetWindowSize() const { return mWindowSize; }

	private:
		void Setup(const std::string& title, const sf::Vector2u& size);
		void Create();
		void Destroy();

		void ToggleFullscreen();

		sf::RenderWindow mWindow;
		sf::Vector2u mWindowSize;
		std::string mWindowTitle;
		bool mIsDone;
		bool mIsFullscreen;
	};

} //ve