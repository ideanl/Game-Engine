#ifndef SCENE_H
#define SCENE_H
#include <string>
#include "imagesprite.h"
#include <SFML/Graphics.hpp>

class Scene {
  public:
    std::string name;
    void update();
    void render();
	protected: 
		sf::RenderWindow* windowPointer;
};

class StartScene: public Scene {
	public:
		void create(sf::RenderWindow& window);
		void render();
	private:
		ImageSprite character;		
};
#endif
