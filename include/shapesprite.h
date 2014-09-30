#ifndef SHAPESPRITE_H
#define SHAPESPRITE_H

#include "basesprite.h"
#include <iostream>
class ShapeSprite :public BaseSprite {
	public:
		ShapeSprite();
		void create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, bool s_shape, std::string s_shapeType);
		void checkEvent();
		void update();
		void render();
		~ShapeSprite();
	protected:
	private:
		std::string shapeType;
		bool shape;
};

#endif
