#include "../include/menulevel.h"
#include "../include/scene.h"
#include "../include/scenes/startscene.h"

void StartMenu::create() {
	sceneManager.add<StartScene>("StartScene");
	sceneManager.set("StartScene");
}

void StartMenu::menuLevelUpdate() {
}
