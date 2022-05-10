//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Person.hpp"

using namespace std;
//TODO override operator<<
Person::Person(std::string name, Container *actualPosition) : name(std::move(name)) {
   actualContainer = actualPosition;
}

bool Person::canDrive() const {
   return CAN_DRIVE;
}

std::string Person::getName() const {
   return name;
}

Container *Person::getActualContainer() const {
   return actualContainer;
}

bool Person::move(Container &to) {
   auto old = actualContainer;
   actualContainer = &to;
   bool canMove = true;

   for (Person* p : old->getPersons())
      canMove = canMove && p->check();

   for (Person* p : to.getPersons())
      canMove = canMove && p->check();

   canMove = canMove && to.addPerson(this);

   if (canMove) {
      old->removePerson(this);

   } else {
      actualContainer = old;
   }

   return canMove;
}


