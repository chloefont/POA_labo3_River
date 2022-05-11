#ifndef LABO4_RIVER_COP_H
#define LABO4_RIVER_COP_H


#include "Person.hpp"

class Cop: public Person {
public:
   /**
    * Cop constructor.
    * @param name Cop's name.
    * @param actualPosition Cop's position.
    * @param errorManager The error manager.
    */
   explicit Cop(std::string name, Container *actualPosition, ErrorManager *errorManager);

   bool check() const override;
};


#endif //LABO4_RIVER_COP_H
