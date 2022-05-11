#include <stdexcept>
#include "Son.hpp"

using namespace std;


Son::Son(string name, Father *father, Mother *mother, Container *actualPosition, ErrorManager *errorManager)
   : Child(std::move(name), father, mother, actualPosition, errorManager) {}

Father *Son::getFather() const {
   return (Father *)(getPreferredParent());
}

Mother *Son::getMother() const {
   return (Mother *)getSecondParent();
}
