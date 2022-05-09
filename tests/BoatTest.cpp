#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "../Controller.h"
#include "../persons/Father.hpp"
#include "../persons/Mother.hpp"
#include "../persons/Son.hpp"
#include "../persons/Daughter.hpp"

using namespace std;

TEST_CASE( "Boat" ) {
   const size_t MAX_CAPACITY = 2;
   Bank leftBank("Gauche");
   Bank rightBank("Droite");
   Boat boat("Bateau", &leftBank, MAX_CAPACITY);

   Father father("Father", &leftBank);
   Mother mother("Mother", &leftBank);
   Son son("Son", &father, &mother, &leftBank);
   Daughter daughter("Daughter", &father, &mother, &leftBank);

   SECTION("2 persons max on boat") {
      boat.addPerson(&father);
      boat.addPerson(&mother);

      CHECK(boat.getPersons().size() == 2);
      REQUIRE_THROWS(boat.addPerson(&son));
   }

   SECTION("2 children cannot drive boat") {

   }


}
