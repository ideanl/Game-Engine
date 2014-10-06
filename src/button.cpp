#include "../include/button.h"

// constructer
Button::Button() {

}

// creates the button in memory, sets the attributes
void Button::create(sf::RenderWindow window, std::string s_messageString, std::string s_fontString, std::string s_textureFile, int s_charSize, sf::Color s_color, int s_xVelocity, int s_yVelocity, int s_xPos, int s_yPos) {
	windowPointer = &window; 
	messageString = s_messageString;
	fontString = s_fontString;
	textureFile = s_textureFile;
	charSize = s_charSize;
	color = s_color;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;
	image.create(windowPointer, textureFile, x_Pos, y_Pos, x_Velocity, y_Velocity);
	text.create(windowPointer, messageString, fontString, charSize, color, x_Pos, y_Pos);
	imageWidth = image.getWidth();
	imageHeight = image.getHeight();
	textWidth = text.getWidth();
	textHeight = text.getHeight();
	x_textPos = x_Pos + (imageWidth - textWidth) / 2;
	y_textPos = y_Pos + (imageHeight - textHeight) / 2;
	text.move(x_textPos, y_textPos);
}
// checks for events
void Button::checkEvent() {
	// if(isClicked() {
	// do this 
	// }
}

// tells if button was clicked
bool Button::isClicked() {
	mousePos = mouse.getPosition();
	if(mouse.isButtonPressed(sf::Mouse::Left)) {
		if(mousePos.x > x_Pos && mousePos.x < x_Pos + imageWidth && mousePos.y > y_Pos && mousePos.y < y_Pos + imageHeight)
			return true;
		else 
			return false;
	}
	return false;
}

// updates the button
void Button::update() {

}

// draws the button
void Button::render() {

}

// destructer
Button::~Button() {

}
