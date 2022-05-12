#ifndef LABO4_RIVER_FATHER_HPP
#define LABO4_RIVER_FATHER_HPP


#include "Parent.hpp"

/**
 * @brief This class represents a father.
 * @authors Luca Coduri & Chloé Fontaine
 */
class Father : public Parent {
public:
   /**
    * Father constructor.
    * @param name
    * @param actualPosition
    * @param errorManager
    */
   explicit Father(std::string name, Container *actualPosition,
                   ErrorManager *errorManager);

   Father(const Father &father) = delete;

   Father &operator=(const Father &father) = delete;

};


#endif //LABO4_RIVER_FATHER_HPP
