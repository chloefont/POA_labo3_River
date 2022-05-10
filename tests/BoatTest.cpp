#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "../Controller.h"
#include "../persons/Father.hpp"
#include "../persons/Mother.hpp"
#include "../persons/Son.hpp"
#include "../persons/Daughter.hpp"
#include "../persons/Robber.hpp"

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
   list<Person*> family = {&father, &mother, &son, &daughter};
   Cop cop("Cop", &leftBank);
   Robber robber("Robber", family, &cop, &leftBank);

   SECTION("getBank()") {
      SECTION("Left bank") {
         REQUIRE(boat.getBank() == &leftBank);
      }
   }

   SECTION("MoveTo()") {

   }

   SECTION("addPerson()") {

   }

   SECTION("2 persons max on boat") {
      father.move(boat);
      mother.move(boat);

      CHECK(boat.getPersons().size() == 2);
      REQUIRE(son.move(boat) == false);
   }

   SECTION("children and robbers cannot drive boat") {
      SECTION("2 children cannot drive boat") {
         son.move(boat);
         daughter.move(boat);

         REQUIRE(boat.moveTo(&rightBank) == false);
      }

      SECTION("robber cannot drive boat") {
         robber.move(boat);

         REQUIRE(boat.moveTo(&rightBank) == false);
      }

      SECTION("1 child and 1 parent can drive boat") {
         son.move(boat);
         father.move(boat);

         REQUIRE(boat.moveTo(&rightBank) == true);
      }

      SECTION("robber and policeman can drive boat") {
         robber.move(boat);
         cop.move(boat);

         REQUIRE(boat.moveTo(&rightBank) == true);
      }
   }
}

