#ifndef SHAPESPRITE_H
#define SHAPESPRITE_H

#include "basesprite.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// class for sprites that are just shapes
class ShapeSprite :public BaseSprite {
	public:
		// constructer
		ShapeSprite();
		// creates the sprite in memory, sets the attributes
		void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message);
    // moves the sprite
		void move(int s_xPos, int s_yPos);
		// checks for events
		void checkEvent();
		// updates the sprite
		void update();
		// draws the sprite
		void render();
		// destructer
		~ShapeSprite();
	protected:
	private:
		sf::RectangleShape rect_shape;
		sf::CircleShape circle_shape;
		sf::Transformable* rectanglePointer;
		sf::Transformable* circlePointer;
};

#endif
