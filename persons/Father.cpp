//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include "Father.hpp"
using namespace std;

bool Father::check() const {
   return true;
}

Father::Father(std::string name, Container *actualPosition) : Parent(std::move(name), actualPosition) {

}
