#include <stdexcept>
#include "Parent.hpp"

using namespace std;

Parent::Parent(std::string name, Container *actualPosition,
               ErrorManager *errorManager)
   : Person(std::move(name), actualPosition, errorManager) {}
