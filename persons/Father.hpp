#ifndef LABO4_RIVER_FATHER_HPP
#define LABO4_RIVER_FATHER_HPP


#include "Parent.hpp"

class Father: public Parent {
public:
   /**
    * Father constructor.
    * @param name
    * @param actualPosition
    * @param errorManager
    */
   explicit Father(std::string name, Container *actualPosition, ErrorManager *errorManager);

   bool check() const override;
};


#endif //LABO4_RIVER_FATHER_HPP
