//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Son.hpp"

using namespace std;

bool Son::check() const {
   throw logic_error("Function not yet implemented");
   return false;
}

Son::Son(string name, Father &father, Mother &mother): Child(std::move(name), father, mother) {}
