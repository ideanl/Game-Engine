#include "../../include/levels/testlevel.h"
#include "../../include/scenes/testscene.h"

void TestLevel::create() {
  sceneManager.set<TestScene>("TestScene");
}

void TestLevel::menuLevelUpdate() {

}

