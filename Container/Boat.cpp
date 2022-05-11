#include <stdexcept>
#include "Boat.hpp"

using namespace std;

Boat::Boat(string name, Bank *bank, size_t capacity) : Container(move(name)),
                                                       bank(bank),
                                                       capacity(capacity) {
}

Bank *Boat::getBank() const {
   return bank;
}

bool Boat::addPerson(Person *person) {
   if (getNbPeople() >= capacity) {
      if (person->getErrorManager())
         person->getErrorManager()->manageError("Le bateau est plein");
      return false;
   } else if (!getBank()->personInContainer(person)) {
      if (person->getErrorManager())
         person->getErrorManager()->manageError("la personne n'est pas sur la bonne "
                                                "rive");
      return false;
   }

   Container::addPerson(person);
   return true;
}

bool Boat::moveTo(Bank *bank) {
   if (bank == this->bank)
      return true;

   for (Person *person: getPersons()) {
      if (person->canDrive()) {
         this->bank = bank;
         return true;
      }
   }

   return false;
}


