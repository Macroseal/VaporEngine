//Brandon Nguyen VaporEngine 2017- Window.cpp

#include "Window.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

static constexpr sf::Uint32 kBitsPerPixel = 32;

namespace ve
{
	inline Window::Window(const std::string & title, const sf::Vector2u & size)
	{
		Setup(title, size);
	}
	
	inline Window::~Window()
	{
		Destroy();
	}

	inline void Window::BeginDraw()
	{
		mWindow.clear(sf::Color::Black);
	}

	inline void Window::Draw(sf::Drawable & drawable)
	{
		mWindow.draw(drawable);
	}

	inline void Window::EndDraw()
	{
		mWindow.display();
	}

	void Window::Update()
	{
		//Handle events	
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mIsDone = true;
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11)
			{
				ToggleFullscreen();
			}
		}
	}

	void Window::Setup(const std::string & title, const sf::Vector2u & size)
	{
		mWindowTitle = title;
		mWindowSize = size;
		mIsFullscreen = false;
		mIsDone = false;
		Create();
	}

	void Window::Create()
	{
		sf::Uint32 style = mIsFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
		sf::VideoMode videoMode(mWindowSize.x, mWindowSize.y, kBitsPerPixel);
		mWindow.create(videoMode, mWindowTitle, style);
	}

	void Window::Destroy()
	{
		mWindow.close();
	}

	void Window::ToggleFullscreen()
	{
		mIsFullscreen = !mIsFullscreen;
		Destroy();
		Create();
	}

} //ve
