#include <iostream>
#include "Controller.h"
#include "persons/Daughter.hpp"

using namespace std;

int main() {
   Controller controller;
   controller.showMenu();
   controller.display();
   controller.nextTurn();
   return 0;
}
