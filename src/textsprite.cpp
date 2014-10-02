#include "../include/textsprite.h"

TextSprite::TextSprite() {

}

void TextSprite::create(sf::RenderWindow window, std::string s_messageString, std::string s_fontString, int s_charSize, sf::Color s_color, int s_xPos, int s_yPos) {
	windowPointer = &window;
	messageString = s_messageString;
	fontString = s_fontString;
	charSize = s_charSize;
	color = s_color;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
}

void TextSprite::checkEvent() {

}

void TextSprite::update() {

}

void TextSprite::render() {

}

TextSprite::~TextSprite() {

}
