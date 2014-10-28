#include "../include/menulevel.h"
#include "../include/scene.h"

void Level1::create() {
	sceneManager.add<MainScene>("MainScene");
	sceneManager.set("MainScene");
}

void Level1::menuLevelUpdate() {

}
