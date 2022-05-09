//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Parent.hpp"
using namespace std;

bool Parent::check() const {
   return true;
}

Parent::Parent(std::string name, Container *actualPosition) : Person(std::move(name), actualPosition) {

}
