//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Daughter.hpp"

using namespace std;

Daughter::Daughter(std::string name, Father *father, Mother *mother,
                   Container *actualPosition, ErrorManager *errorManager) : Child(std::move(
                                                                              name),
                                                                                  mother,
                                                                                  father,
                                                                           actualPosition, errorManager) {

}

Father *Daughter::getFather() {
   return (Father *)getSecondParent();
}

Mother *Daughter::getMother() {
   return (Mother*)getPrefferedParent();
}
