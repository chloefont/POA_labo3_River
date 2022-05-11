#ifndef LABO4_RIVER_PARENT_HPP
#define LABO4_RIVER_PARENT_HPP


#include "Person.hpp"

/**
 * @brief This class represents a parent
 * @authors Luca Coduri & Chloé Fontaine
 */
class Parent : public Person {
protected:
   /**
    *
    * @param name Parent's name
    * @param actualPosition Parent's actual position
    * @param errorManager The error manager
    */
   explicit Parent(std::string name, Container *actualPosition,
                   ErrorManager *errorManager);
};


#endif //LABO4_RIVER_PARENT_HPP
