//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Son.hpp"

using namespace std;

bool Son::check() const {
   if(getMother()->getActualContainer() == getActualContainer() &&
   getFather()->getActualContainer() != getActualContainer()){
      return false;
   }
   return true;
}

Son::Son(string name, Father *father, Mother *mother, Container *actualPosition)
   : Child(std::move(name),
           father, mother, actualPosition) {}
