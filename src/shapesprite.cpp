#include "../include/shapesprite.h"

ShapeSprite::ShapeSprite() {

}

void ShapeSprite::create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, bool s_shape, std::string s_shapeType, int shapeParam1, int shapeParam2) {
	windowPointer = &window;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	shape = s_shape;
	shapeType = s_shapeType;
	if(shape == true) {
		if(shapeType == "circle" || "Circle") {
			

