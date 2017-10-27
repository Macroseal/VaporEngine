//Brandon Nguyen VaporEngine 2017- main.cpp

#include <SFML/Graphics.hpp>

void main(int argc, char** argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing mushroom.");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
		//Draw stuff here
		window.display();
	}
}
