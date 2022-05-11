#include <stdexcept>
#include <utility>
#include "Daughter.hpp"

using namespace std;

Daughter::Daughter(std::string name, Father *father, Mother *mother,
                   Container *actualPosition, ErrorManager *errorManager) :
                   Child(std::move(name),mother,father,
                         actualPosition, errorManager) {}

Father *Daughter::getFather() const {
   return (Father *)getSecondParent();
}

Mother *Daughter::getMother() const {
   return (Mother*) getPreferredParent();
}
