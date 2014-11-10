#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H

#include "basesprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// class for sprites that are just text
class TextSprite :public BaseSprite{
	public:
		// constructer
		TextSprite();
		// creates sprite in memory, sets all attributes
		void create(sf::RenderWindow* window, std::string s_messageString, std::string s_fontString, int s_charSize, sf::Vector3f s_color, int s_xPos, int s_yPos);
		// moves the sprite
		void move(int s_xPos, int s_yPos);
		// checks for events
		void checkEvent();
		// updates the sprite
		void update();
		// draws the sprite
		void render();
		// returns the text
		sf::Text* getTextAddress();
		// destructer
		~TextSprite();
	protected:
	private:
		std::string messageString, fontString;
		int charSize;

		sf::Color color;
		sf::Font font;
		sf::Text text;
    	sf::Transformable* textPointer;
		sf::Text* textAddress;
};

#endif

