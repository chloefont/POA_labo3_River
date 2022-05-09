//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Cop.hpp"
using namespace std;

bool Cop::check() const {
   return true;
}

Cop::Cop(std::string name, Container *actualPosition) : Person(std::move(name), actualPosition) {

}
