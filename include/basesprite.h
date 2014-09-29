#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class BaseSprite {
  public:
    BaseSprite();
    virtual void create() = 0;
    virtual void checkEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
	virtual void setWidth() = 0;
	virtual void setHeight() = 0;
    ~BaseSprite();
  protected:
    int x_Velocity, y_Velocity, x_Pos, y_Pos, width, height;
    sf::RenderWindow* windowPointer;
	sf::FloatRect boundaries;
  private:
};

#endif
