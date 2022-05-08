//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Cop.hpp"
using namespace std;

bool Cop::check() const {
   throw logic_error("Function not yet implemented");
}

Cop::Cop(std::string name) : Person(std::move(name), nullptr) {

}
