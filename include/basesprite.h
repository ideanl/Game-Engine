#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class BaseSprite {
  public:
    BaseSprite();
    virtual void checkEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
	template<class Type>
	void setBoundaries(Type& object) {
		sf::FloatRect boundaries = object.getGlobalBounds();
		width = boundaries.width;
		height = boundaries.height;
	}
    ~BaseSprite();
  protected:
    int x_Velocity, y_Velocity, x_Pos, y_Pos, width, height;
    sf::RenderWindow* windowPointer;
	sf::FloatRect boundaries;
  private:
};

#endif
