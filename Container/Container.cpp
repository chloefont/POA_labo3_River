//
// Created by cfont on 05.05.2022.
//

#include "Container.h"
#include <utility>
#include <algorithm>

using namespace std;

Container::Container(std::string  name) : name(std::move(name)){
}

std::list<Person*> Container::getPersons() const {
   return persons;
}

std::string Container::getName() const {
   return name;
}

void Container::addPerson(Person *person) {
   if (!personInContainer(person))
      persons.push_back(person);
}

void Container::removePerson(Person *person) {
   persons.remove(person);
}

size_t Container::getNbPeople() const {
   return persons.size();
}

bool Container::personInContainer(Person *person) {
   return find(persons.begin(), persons.end(), person) != persons.end();
}
