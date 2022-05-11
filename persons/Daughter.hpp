//
// Created by cfont on 14.04.2022.
//

#ifndef LABO4_RIVER_DAUGHTER_HPP
#define LABO4_RIVER_DAUGHTER_HPP


#include "Child.hpp"

class Daughter: public Child {
public:
   /**
    * Daughter construcotr.
    * @param name Daughter's name.
    * @param father Daughter's father.
    * @param mother Daughter's mother.
    * @param actualPosition Daughter's position.
    * @param errorManager The errorManager.
    */
   Daughter(std::string name, Father *father, Mother *mother,
            Container *actualPosition, ErrorManager *errorManager);
   bool check() const override;
};


#endif //LABO4_RIVER_DAUGHTER_HPP
