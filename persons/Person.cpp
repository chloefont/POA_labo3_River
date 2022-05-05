//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Person.hpp"

using namespace std;

Person::Person(const string &name) : name(name) {

}

bool Person::move(Container &to) const {
   throw logic_error("Function not yet implemented");
   return false;
}

bool Person::canDrive() const {
   return CAN_DRIVE;
}

std::string Person::getName() const {
   return name;
}


