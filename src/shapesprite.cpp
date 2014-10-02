#include "../include/shapesprite.h"

ShapeSprite::ShapeSprite() {

}

void ShapeSprite::create(sf::RenderWindow& window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, std::string s_shapeType, float s_param1, float s_param2, sf::Color s_color) {
	windowPointer = &window;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	param1 = s_param1;
	param2 = s_param2;
	shapeType = s_shapeType;
	color = s_color;
	if(shapeType == "circle" || "Circle") {
		circle_shape.setRadius(param1);
		circle_shape.setFillColor(color);
		circle_shape.setPosition(x_Pos, y_Pos);
	}
	else if(shapeType == "rectangle" || "Rectangle") {
		rect_shape.setSize(sf::Vector2f(param1, param2));
		rect_shape.setFillColor(color);
		rect_shape.setPosition(x_Pos, y_Pos);
	}
}

void ShapeSprite::checkEvent() {

}

void ShapeSprite::update() {

}

void ShapeSprite::render() {
	if(shapeType == "circle" || "Circle") 
		windowPointer->draw(circle_shape);
	if(shapeType == "rectangle" || "Rectangle") 
		windowPointer->draw(rect_shape);
}

ShapeSprite::~ShapeSprite() {

}
