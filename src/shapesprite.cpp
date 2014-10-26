#include "../include/shapesprite.h"
#include "../include/game.h"
#include <SFML/Graphics.hpp>
#include <ctype.h>

std::string lowerCase(std::string s_text);

// constructer
ShapeSprite::ShapeSprite() {
}

// creates the sprite in memory, sets all the attributes
void ShapeSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, std::string s_shapeType, float s_param1, float s_param2, sf::Color s_color) {
  windowPointer = window;
	color = s_color;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	param1 = s_param1;
	param2 = s_param2;
	shapeType = lowerCase(s_shapeType);

	// for circles
	if(shapeType == "circle") {
		circle_shape.setRadius(param1);
		circle_shape.setFillColor(color);
		circle_shape.setPosition(x_Pos, y_Pos);
		// sets the width and height of the global bounding rectangle
		setBoundaries<sf::CircleShape>(circle_shape);
	}

	// for rectangles
	else if(shapeType == "rectangle") {
		rect_shape.setSize(sf::Vector2f(param1, param2));
		rect_shape.setFillColor(color);
		rect_shape.setPosition(x_Pos, y_Pos);
		// sets the width and height of the global bounding rectangle
		setBoundaries<sf::RectangleShape>(rect_shape);
	}
}

// moves the sprite
void ShapeSprite::move(int s_xPos, int s_yPos) {
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	circle_shape.setPosition(x_Pos, y_Pos);
	rect_shape.setPosition(x_Pos, y_Pos);
}
// checks for events
void ShapeSprite::checkEvent() {

}

// updates the sprite
void ShapeSprite::update() {

}

// draws the sprite
void ShapeSprite::render() {
	if(shapeType == "circle") 
		windowPointer->draw(circle_shape);
	if(shapeType == "rectangle") 
		windowPointer->draw(rect_shape);
}

// destructer
ShapeSprite::~ShapeSprite() {

}

std::string lowerCase(std::string s_text) {
	std::string text = s_text;
	for(int i = 0; i < text.length(); i++) {
		text[i] = tolower(text[i]);
	}
	return text;
}
