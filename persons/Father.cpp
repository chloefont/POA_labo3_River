#include <stdexcept>
#include "Father.hpp"
using namespace std;

bool Father::check() const {
   return true;
}

Father::Father(std::string name, Container *actualPosition, ErrorManager *errorManager) : Parent(std::move
(name), actualPosition, errorManager) {

}
