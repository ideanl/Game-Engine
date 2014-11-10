#include "../include/textsprite.h"

// constructer
TextSprite::TextSprite() {
  textPointer = &text;
  textAddress = &text;
  transformables.push_back(textPointer);
}

// creates the sprite in memory, sets the attributes
void TextSprite::create(sf::RenderWindow* window, std::string s_messageString, std::string s_fontString, int s_charSize, sf::Vector3f s_color, int s_xPos, int s_yPos) {
	
	// settting all the memeber variables
	windowPointer = window;
	messageString = s_messageString;
	fontString = s_fontString;
	charSize = s_charSize;
	color.r = s_color.x;
	color.g = s_color.y;
	color.b = s_color.z;
	x_Pos = s_xPos;
	y_Pos = s_yPos;

	// checks to make sure the font loads
	if(!font.loadFromFile("./res/" + fontString))
		std::cerr << "Font " << fontString << " failed to load" << std::endl;
	else {
		// creates the sprite 
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
	text.setPosition(s_xPos, s_xPos);
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

// returns the sprite
sf::Text* TextSprite::getTextAddress() {
	return textAddress;
}

// destructer
TextSprite::~TextSprite() {

}
