//
// Created by cfont on 14.04.2022.
//

#include "Person.h"

Person::Person(const std::string &name) : name(name) {
}

std::string Person::getName() const {
   return name;
}
