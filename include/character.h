#ifndef CHARACTER_H
#define CHARACTER_H

#include "imagesprite.h"
#include <SFML/Grahpics.hpp>

// base class for characters, playable or not
class Character :ImageSprite {
	public:
		// constructer
		Character();
		// creates the character in memory, sets all its attributes
		void create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity);
		// checks for events
		void checkEvent();
		// updates the character
		void update();
		// draws the character
		void render();
		// destructer
		~ImageSprite();
	protected:
	private:
};

#endif 
