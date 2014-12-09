#include "../include/shapesprite.h"
#include "../include/game.h"
#include <SFML/Graphics.hpp>
#include <ctype.h>

std::string lowerCase(std::string s_text);

// constructer
ShapeSprite::ShapeSprite() {
	rectanglePointer = &rect_shape;
	circlePointer = &circle_shape;
	transformables.push_back(rectanglePointer);
	transformables.push_back(circlePointer);
}

void ShapeSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config) {	
  // sets all the member variables
	windowPointer = window;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	width = s_width;
	height = s_height;
	textureFile = lowerCase(s_textureFile);
	color.r = s_color.x;
	color.g = s_color.y;
	color.b = s_color.z;

	// for circles
	if(textureFile == "circle") {
		circle_shape.setRadius(width);
		circle_shape.setFillColor(color);
		circle_shape.setPosition(x_Pos, y_Pos);
		// sets the width and height of the global bounding rectangle
		setBoundaries<sf::CircleShape>(circle_shape);
	}

	// for rectangles
	else if(textureFile == "rectangle") {
		rect_shape.setSize(sf::Vector2f(width, height));
		rect_shape.setFillColor(color);
		rect_shape.setPosition(x_Pos, y_Pos);
		// sets the width and height of the global bounding rectangle
		setBoundaries<sf::RectangleShape>(rect_shape);
	}
}

// sets the sprite position
void ShapeSprite::setPosition(int s_xPos, int s_yPos) {
  rect_shape.setPosition(s_xPos, s_yPos);
  circle_shape.setPosition(s_xPos, s_yPos);
  x_Pos = s_xPos;
  y_Pos = s_yPos;
}

// moves the sprite along the horizontal axis
void ShapeSprite::move_x(int s_xPos) {
  while(x_Pos < s_xPos) {
	  circle_shape.move(x_Velocity, 0);
	  rect_shape.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}
void ShapeSprite::move_x(bool isMoving) {
  while(isMoving) {
    circle_shape.move(x_Velocity, 0);
    rect_shape.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}

// moves the sprite along the vertical axis
void ShapeSprite::move_y(int s_yPos) {
  while(y_Pos < s_yPos) {
    circle_shape.move(0, y_Velocity);
    rect_shape.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}
void ShapeSprite::move_y(bool isMoving) {
  while(isMoving) {
    circle_shape.move(0, y_Velocity);
    rect_shape.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}

// checks for events
void ShapeSprite::checkEvent() {

}

// updates the sprite
void ShapeSprite::update() {

}

// draws the sprite
void ShapeSprite::render() {
	if(textureFile == "circle") 
		windowPointer->draw(circle_shape);
	if(textureFile == "rectangle") 
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
