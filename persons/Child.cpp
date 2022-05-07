//
// Created by luca on 05/05/22.
//

#include <stdexcept>
#include "Child.hpp"
using namespace std;

bool Child::check() const {
   throw logic_error("Function not yet implemented");
   return true;
}

Father* Child::getFather() const {
   return father;
}

Mother* Child::getMother() const {
   return mother;
}

Child::Child(string name, Father* father, Mother* mother):Person(std::move(name)),
father(father), mother(mother) {}

bool Child::canDrive() const {
   return CAN_DRIVE;
}
