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
		void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, std::string s_shapeType, float s_param1, float s_param2, sf::Vector3f s_color);
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
    sf::RenderWindow* windowPointer;
		std::string shapeType;
		int param1, param2;
		sf::RectangleShape rect_shape;
		sf::CircleShape circle_shape;
		sf::Color color;
		sf::Transformable* rectanglePointer;
		sf::Transformable* circlePointer;
};

#endif
