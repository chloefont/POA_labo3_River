#ifndef LABO4_RIVER_SON_HPP
#define LABO4_RIVER_SON_HPP

#include "Child.hpp"

/**
 * @brief This class represents a son.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Son : public Child {
public:
   /**
    * Son constructor
    * @param name Son's name.
    * @param father Son's preferredParent.
    * @param mother Son's secondParent.
    * @param actualPosition Son's actual position
    * @param errorManager The error manager.
    */
   Son(std::string name, Father *father, Mother *mother, Container *actualPosition, ErrorManager *errorManager);

   Son(const Son &son) = delete;

   Son &operator=(const Son &son) = delete;

   Father *getFather() const;

   Mother *getMother() const;
};


#endif //LABO4_RIVER_SON_HPP
