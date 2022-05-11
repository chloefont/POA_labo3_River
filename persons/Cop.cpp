#include <stdexcept>
#include "Cop.hpp"
using namespace std;

bool Cop::check() const {
   return true;
}

Cop::Cop(std::string name, Container *actualPosition, ErrorManager *errorManager)
: Person(std::move(name), actualPosition, errorManager) {}
