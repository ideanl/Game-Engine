#include "../../include/menus/startmenu.h"
#include "../../include/scenes/startscene.h"

void StartMenu::create() {
  sceneManager.set<StartScene>("StartScene");
}

void StartMenu::menuLevelUpdate() {

}
