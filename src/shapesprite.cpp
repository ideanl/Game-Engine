#include "../include/shapesprite.h"

ShapeSprite::ShapeSprite() {

}

void ShapeSprite::create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, bool s_isShape, std::string s_shapeType, int s_param1, int s_param2) {
	windowPointer = &window;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	isShape = s_isShape;
	shapeType = s_shapeType;
	if(isShape == true) {
		if(shapeType == "circle" || "Circle") {
			shape = sf::CircleShape;	
		}
		else if(shapeType == "rectangle" || "Rectangle") {
			shape = sf::RectangleShape;
		}
	}
	else {
		if(shapeType == "button" || "Button") {

		}
	}
}

