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
		void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config = 0);
    // checks for events
		void checkEvent();
		// tells if button was clicked
		bool isClicked();
    // moves the button
    void move(int s_xPos, int s_yPos);
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
		sf::Transformable* textSpritePointer;
		sf::Transformable* imageSpritePointer;
		// add pointers in header and source for textsprite and imagesprite
};

#endif
