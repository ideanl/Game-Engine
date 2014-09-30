#ifndef SHAPESPRITE_H
#define SHAPESPRITE_H

#include "basesprite.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class ShapeSprite :public BaseSprite {
	public:
		ShapeSprite();
		void create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, bool s_isShape, std::string s_shapeType, int s_param1, int s_param2);
		void checkEvent();
		void update();
		void render();
		~ShapeSprite();
	protected:
	private:
		std::string shapeType;
		bool isShape;
		sf::Shape shape;
};

#endif
