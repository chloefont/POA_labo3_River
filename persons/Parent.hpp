#ifndef LABO4_RIVER_PARENT_HPP
#define LABO4_RIVER_PARENT_HPP


#include "Person.hpp"

class Parent: public Person {
public:
   bool check() const override;

protected:
   /**
    *
    * @param name Parent's name
    * @param actualPosition Parent's actual position
    * @param errorManager The error manager
    */
   explicit Parent(std::string name, Container *actualPosition, ErrorManager *errorManager);
};


#endif //LABO4_RIVER_PARENT_HPP
