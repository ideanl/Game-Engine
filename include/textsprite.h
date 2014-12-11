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
    void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config = 0);
    // sets the sprite position
    void setPosition(int s_xPos, int s_yPos);
    // moves the sprite along the horizontal axis
		void move_x(int s_xPos);
    void move_x(bool isMoving);
    // moves the sprite along the vertical axis
    void move_y(int s_yPos);
    void move_y(bool isMoving);
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
		int charSize;

		sf::Font font;
		sf::Text text;
    sf::Transformable* textPointer;
		sf::Text* textAddress;
};

#endif

