#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// The Base class for all other sprites
class BaseSprite {
  public:
  	// construter
    BaseSprite();
	// creates the button in memory, stores all its attributes
  virtual void create();
	// checks for events
	virtual void checkEvent() = 0;
	// updates the sprite position and such
  virtual void update() = 0;
	// draws the sprite
  virtual void render() = 0;
	// moves the sprite
	virtual void move(int s_xPos, int s_yPos) = 0;
	// reutns the gobal bouding rectangle width
	int getWidth();
	// returns the gobla bouding rectange height
	int getHeight();
	// returns the drawables
	std::vector<sf::Transformable*> getTransformables();
	// gets and sets the rectangle surrounding the sprite
	template <class Type> void setBoundaries(Type& object) {
		sf::FloatRect boundaries = object.getGlobalBounds();
		width = boundaries.width;
		height = boundaries.height;
	}
  // moves the sprite
  template <class s_type> void move(int s_xPos, int s_yPos, s_type object) {
    for(int i = 0; i < object->getTransformables().size(); i++) {
	  object->getTransformables()[i]->setPosition(s_xPos, s_yPos);
    }
  }
	// destructer
    ~BaseSprite();
  protected:
    int x_Velocity, y_Velocity, x_Pos, y_Pos, width, height;
    sf::RenderWindow* windowPointer;
	sf::FloatRect boundaries;
	std::vector<sf::Transformable*> transformables;
  private:
};

#endif
