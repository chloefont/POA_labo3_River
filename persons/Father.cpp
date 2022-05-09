//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Father.hpp"
using namespace std;

bool Father::check() const {
   return true;
}

Father::Father(std::string name) : Parent(std::move(name)) {

}
