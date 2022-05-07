//
// Created by cfont on 14.04.2022.
//

#include <stdexcept>
#include <utility>
#include "Father.hpp"
using namespace std;

bool Father::check() const {
   throw logic_error("Function not yet implemented");
}

Father::Father(std::string name) : Parent(std::move(name)) {

}
