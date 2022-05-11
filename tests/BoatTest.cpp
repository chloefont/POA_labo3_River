#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "../Controller.hpp"
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

   Father father("Father", &leftBank, nullptr);
   Mother mother("Mother", &leftBank, nullptr);
   Son son("Son", &father, &mother, &leftBank, nullptr);
   Daughter daughter("Daughter", &father, &mother, &leftBank, nullptr);
   list<Person*> family = {&father, &mother, &son, &daughter};
   Cop cop("Cop", &leftBank, nullptr);
   Robber robber("Robber", family, &cop, &leftBank, nullptr);

   SECTION("getBank()") {
      SECTION("Left bank") {
         REQUIRE(boat.getBank() == &leftBank);
      }

      SECTION("Right bank") {
         Boat boat2("Bateau", &rightBank, MAX_CAPACITY);
         REQUIRE(boat2.getBank() == &rightBank);
      }
   }

   SECTION("MoveTo()") {
      SECTION("Move to with no one") {
         REQUIRE(boat.moveTo(&rightBank) == false);
         REQUIRE(boat.getBank() == &leftBank);
      }

      SECTION("Move to with one driver") {
         Father father2("Father2", &leftBank, nullptr);
         REQUIRE(father2.move(boat) == true);
         REQUIRE(boat.moveTo(&rightBank) == true);
      }
   }

   SECTION("move person on boat") {
      SECTION("add person from bank next to boat") {
         REQUIRE(robber.move(boat));
         REQUIRE(boat.getNbPeople() == 1);
      }

      SECTION("add person from bank far from boat") {
         Robber robber2("Robber2", family, &cop, &rightBank, nullptr);
         CHECK(boat.getBank() == &leftBank);
         REQUIRE(robber2.move(boat) == false);
         REQUIRE(boat.getNbPeople() == 0);
      }
   }

   SECTION("2 persons max on boat") {
      robber.move(boat);
      cop.move(boat);

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

