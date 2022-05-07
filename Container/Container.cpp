//
// Created by cfont on 05.05.2022.
//

#include "Container.h"

#include <utility>

Container::Container(std::string  name) : name(std::move(name)){
}

std::list<Person*> Container::getPersons() const {
   return persons;
}

std::string Container::getName() const {
   return name;
}

void Container::addPerson(Person *person) {
   persons.push_back(person);
}
