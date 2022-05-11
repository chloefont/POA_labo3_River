//
// Created by luca on 05/05/22.
//

#include <stdexcept>
#include "Child.hpp"
using namespace std;

bool Child::check() const {
   if(parent2->getActualContainer() == getActualContainer() &&
      parent1->getActualContainer() != getActualContainer()){
      if (getErrorManager() != nullptr)
         getErrorManager()->manageError(getName() + " ne peut pas rester sans son "
                                                  + parent1->getName() +
                                        "avec " + parent2->getName());
      return false;
   }
   return true;
}

Parent* Child::getPrefferedParent() const {
   return parent1;
}

Parent* Child::getSecondParent() const {
   return parent2;
}

Child::Child(string name, Parent *parent1, Parent *parent2,
             Container *actualPosition, ErrorManager *errorManager) : Person(std::move(name),
                                                 actualPosition, errorManager),
                                                                      parent1(parent1), parent2(parent2) {}

bool Child::canDrive() const {
   return CAN_DRIVE;
}
