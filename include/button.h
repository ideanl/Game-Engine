#ifndef BUTTON_H
#define BUTTON_H

#include "basesprite.h"
#include "imagesprite.h"
#include "textsprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// class for buttons
class Button :public BaseSprite{
	public:
		// constructer
		Button();
		// creates the button in memory, sets the attributes
		void create(sf::RenderWindow* window, std::string s_messageString, std::string s_fontString, std::string s_textureFile, int s_charSize, sf::Color s_color, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity);
		// checks for events
		void checkEvent();
		// tells if button was clicked
		bool isClicked();
		// updates the button
		void update();
		// draws the button
		void render();
		// destructer
		~Button();
	protected:
	private:
		ImageSprite image;
		TextSprite text;
		sf::Mouse mouse;
		sf::Vector2i mousePos;
		std::string messageString, fontString, textureFile; 
		int charSize, x_textPos, y_textPos, imageWidth, imageHeight, textWidth, textHeight;
		sf::Color color;
};

#endif
