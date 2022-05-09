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

void Boat::addPerson(Person *person) {
   if (getNbPeople() >= capacity)
      throw runtime_error("Boat is full");

   Container::addPerson(person);
}

void Boat::setBank(Bank* bank) {
   this->bank = bank;
}
