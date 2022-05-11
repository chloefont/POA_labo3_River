#ifndef LABO4_RIVER_DAUGHTER_HPP
#define LABO4_RIVER_DAUGHTER_HPP


#include "Child.hpp"

/**
 * @brief This class represents a daughter.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Daughter : public Child {
public:
   /**
    * Daughter constructor.
    * @param name Daughter's name.
    * @param father Daughter's preferredParent.
    * @param mother Daughter's secondParent.
    * @param actualPosition Daughter's position.
    * @param errorManager The errorManager.
    */
   Daughter(std::string name, Father *father, Mother *mother,
            Container *actualPosition, ErrorManager *errorManager);

   Father *getFather() const;

   Mother *getMother() const;
};


#endif //LABO4_RIVER_DAUGHTER_HPP
