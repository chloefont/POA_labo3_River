#ifndef LABO4_RIVER_COP_H
#define LABO4_RIVER_COP_H


#include "Person.hpp"

/**
 * @brief This class represents a cop.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Cop : public Person {
public:
   /**
    * Cop constructor.
    * @param name Cop's name.
    * @param actualPosition Cop's position.
    * @param errorManager The error manager.
    */
   explicit Cop(std::string name, Container *actualPosition,
                ErrorManager *errorManager);

   Cop(const Cop &cop) = delete;

   Cop &operator=(const Cop &cop) = delete;

};


#endif //LABO4_RIVER_COP_H
