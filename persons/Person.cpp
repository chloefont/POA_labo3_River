#include <stdexcept>
#include "Person.hpp"

using namespace std;

Person::Person(std::string name, Container *actualPosition,
               ErrorManager *errorManager) : name(std::move
                                                     (name)) {
   if (actualPosition == nullptr) {
      throw invalid_argument("Actual position cannot be nullptr");
   }

   this->actualContainer = actualPosition;
   this->errorManager = errorManager;
   actualContainer->addPerson(this);
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

   if (!to.addPerson(this)) {
      actualContainer = old;
      return false;
   }
   old->removePerson(this);

   for (Person *p: old->getPersons())
      canMove = canMove && p->check();

   for (Person *p: to.getPersons())
      canMove = canMove && p->check();


   if (!canMove) {
      actualContainer->removePerson(this);
      actualContainer = old;
      old->addPerson(this);

   }

   return canMove;
}

ErrorManager *Person::getErrorManager() const {
   return errorManager;
}

bool Person::check() const {
   return true;
}


