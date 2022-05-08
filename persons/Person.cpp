//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Person.hpp"

using namespace std;

Person::Person(std::string name, Container *actualPosition) : name(std::move(name)) {

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
   if(!check()){
      actualContainer = old;
      return false;
   }
   return true;
}


