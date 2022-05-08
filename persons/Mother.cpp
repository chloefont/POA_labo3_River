//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Mother.hpp"
using namespace std;
bool Mother::check() const {
   throw logic_error("Function not yet implemented");
   return false;
}

Mother::Mother(std::string name, Container *actualPosition) : Parent(std::move(name), actualPosition) {

}
