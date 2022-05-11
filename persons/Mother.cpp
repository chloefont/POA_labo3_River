#include <stdexcept>
#include "Mother.hpp"
using namespace std;

Mother::Mother(std::string name, Container *actualPosition, ErrorManager
*errorManager) : Parent(std::move(name), actualPosition, errorManager) {}

bool Mother::check() const {
   return true;
}
