//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Cop.hpp"
using namespace std;

bool Cop::check() const {
   return true;
}

Cop::Cop(std::string name) : Person(std::move(name)) {

}
