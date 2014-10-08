#ifndef CHARACTER_H
#define CHARACTER_H

#include "imagesprite.h"
#include <SFML/Graphics.hpp>

// base class for characters
class Character :public ImageSprite{
	public:
		// constructer
		Character();
		// checks for events
		void checkEvent();
		// updates the character
		void update();
		// draws the character
		void render();
		// deconstructer
		~Character();
		
};

#endif
