//
// Created by cfont on 14.04.2022.
//

#include "Daughter.hpp"

#include <utility>

bool Daughter::check() const {
   if(getMother()->getActualContainer() != getActualContainer() &&
      getFather()->getActualContainer() == getActualContainer()){
      return false;
   }

   return true;
}

Daughter::Daughter(std::string name, Father* father, Mother* mother) : Child
(std::move(name),
                                                                             father,
                                                                             mother) {

}
