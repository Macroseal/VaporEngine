//Brandon Nguyen VaporEngine 2017- TextBox.h
#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <String>
#include <Vector>

namespace ve
{
	class TextBox
	{
	public:
		TextBox();
		TextBox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
		~TextBox();

		void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
		void Add(std::string l_message);
		void Clear();

		void Render(sf::RenderWindow& l_wind);
	private:
		std::vector<std::string> m_messages;
		int m_numVisible;

		sf::RectangleShape m_backdrop;
		sf::Font m_font;
		sf::Text m_content;
	};
}