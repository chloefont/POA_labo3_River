//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Mother.hpp"
using namespace std;
bool Mother::check() const {
   return true;
}

Mother::Mother(std::string name, Container *actualPosition, ErrorManager
*errorManager) : Parent(std::move(name), actualPosition, errorManager) {

}
