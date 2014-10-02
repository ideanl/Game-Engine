#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H

#include "basesprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class TextSprite :public BaseSprite{
	public:
		TextSprite();
		void create(sf::RenderWindow window, std::string s_messageString, std::string s_fontString, int s_charSize, sf::Color s_color, int s_xPos, int s_yPos);
		void checkEvent();
		void update();
		void render();
	protected:
	private:
		std::string messageString, fontString;
		int charSize; 
		sf::Color color;

		sf::Font font;
		sf::Text text;
};

#endif

