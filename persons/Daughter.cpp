//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Daughter.hpp"

using namespace std;

bool Daughter::check() const {
   if(getMother()->getActualContainer() != getActualContainer() &&
      getFather()->getActualContainer() == getActualContainer()){
      //throw logic_error("la fille ne peut pas rester sans sa mere avec son pere");
      return false;
   }

   return true;
}

Daughter::Daughter(std::string name, Father *father, Mother *mother,
                   Container *actualPosition) : Child
                                                                          (std::move(
                                                                              name),
                                                                           father,
                                                                           mother,
                                                                           actualPosition) {

}
