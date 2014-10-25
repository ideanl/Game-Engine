#include "../include/textsprite.h"

// constructer
TextSprite::TextSprite() {

}

// creates the sprite in memory, sets the attributes
void TextSprite::create(sf::RenderWindow* window, std::string s_messageString, std::string s_fontString, int s_charSize, sf::Color s_color, int s_xPos, int s_yPos) {
	windowPointer = window;
	messageString = s_messageString;
	fontString = s_fontString;
	charSize = s_charSize;
	color = s_color;
	x_Pos = s_xPos;
	y_Pos = s_yPos;

	// checks to make sure the font loads
	if(!font.loadFromFile("res/" + fontString))
		std::cerr << "Font " << fontString << " failed to load" << std::endl;
	else {
		text.setFont(font);
		text.setString(messageString);
		text.setCharacterSize(charSize);
		text.setColor(color);
		text.setPosition(x_Pos, y_Pos);
		// gets the width and height of the global bounding rectangle
		setBoundaries<sf::Text>(text);
	}
}

// moves the sprite
void TextSprite::move(int s_xPos, int s_yPos) {
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	text.setPosition(x_Pos, y_Pos);
}

// checks for events
void TextSprite::checkEvent() {

}

// updates the sprite
void TextSprite::update() {

}

// draws the sprite
void TextSprite::render() {
	windowPointer->draw(text);
}

// destructer
TextSprite::~TextSprite() {

}
