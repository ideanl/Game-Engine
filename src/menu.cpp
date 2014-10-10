#include "../include/menulevel.h"
#include "../include/scene.h"

StartMenu::StartMenu() {
  sceneManager.add<StartScene>("StartScene");
  sceneManager.set("StartScene");
}
