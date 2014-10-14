#ifndef CHARACTER_H
#define CHARACTER_H

#include "imagesprite.h"
#include <SFML/Graphics.hpp>

// base class for characters
class Character :public ImageSprite{
	public:
		// constructer
		Character();
		void create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity);
		// checks for events
		void checkEvent();
		// updates the character
		void update();
		// draws the character
		void render();
		// destructer
		~Character();
	protected:
	private:
};

#endif
