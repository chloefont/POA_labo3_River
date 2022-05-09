//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Mother.hpp"
using namespace std;
bool Mother::check() const {
   return true;
}

Mother::Mother(std::string name) : Parent(std::move(name)) {

}
