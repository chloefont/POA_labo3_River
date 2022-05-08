#include <iostream>
#include "Controller.h"

using namespace std;

int main() {
   Controller controller;
   controller.showMenu();
   controller.display();
   controller.nextTurn();
   return 0;
}
