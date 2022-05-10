//
// Created by cfont on 05.05.2022.
//

#include <stdexcept>
#include "Boat.h"

using namespace std;

Boat::Boat(const std::string& name, Bank* bank, size_t capacity) : Container(name),
bank(bank), capacity(capacity) {
}

Bank* Boat::getBank() const {
   return bank;
}

bool Boat::addPerson(Person *person) {
   if (getNbPeople() >= capacity)
      return false;
      //throw runtime_error("le bateau est plein");

   Container::addPerson(person);
   return true;
}

bool Boat::moveTo(Bank* bank) {
   if (bank == this->bank)
      return true;

   for (Person* person : getPersons()) {
      if (person->canDrive()) {
         this->bank = bank;
         return true;
      }
   }

   return false;
}


