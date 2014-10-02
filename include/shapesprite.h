#ifndef SHAPESPRITE_H
#define SHAPESPRITE_H

#include "basesprite.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class ShapeSprite :public BaseSprite {
	public:
		ShapeSprite();
		void create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, std::string s_shapeType, float s_param1, float s_param2, sf::Color s_color);
		void checkEvent();
		void update();
		void render();
		~ShapeSprite();
	protected:
	private:
		std::string shapeType;
		int param1, param2;
		sf::RectangleShape rect_shape;
		sf::CircleShape circle_shape;
		sf::Color color;
};

#endif
