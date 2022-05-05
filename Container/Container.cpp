//
// Created by cfont on 05.05.2022.
//

#include "Container.h"

Container::Container(const std::string& name) : name(name){
}

std::list<Person*> Container::getPersons() const {
   return persons;
}

std::string Container::getName() const {
   return name;
}
