#ifndef LABO4_RIVER_MOTHER_HPP
#define LABO4_RIVER_MOTHER_HPP


#include "Parent.hpp"

class Mother: public Parent {
public:
   /**
    *
    * @param name Mother's name
    * @param actualPosition Mother's actual position
    * @param errorManager the error manager
    */
   explicit Mother(std::string name, Container *actualPosition, ErrorManager *errorManager);
};


#endif //LABO4_RIVER_MOTHER_HPP
