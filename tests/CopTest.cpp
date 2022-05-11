#include "catch.hpp"
#include "../persons/Cop.hpp"
#include "../Container/Bank.hpp"
#include "../Container/Boat.hpp"

TEST_CASE("Cop") {
   const size_t MAX_CAPACITY = 2;
   Bank leftBank("Gauche");
   Bank rightBank("Droite");
   Boat boat("Bateau", &leftBank, MAX_CAPACITY);
   Cop cop("Cop", &leftBank, nullptr);

   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(cop.check());
      }

      SECTION("Should return true"){
         CHECK(true == cop.check());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Cop" == cop.getName());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return true"){
         CHECK(true == cop.canDrive());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(cop.move(boat));
      }

      SECTION("Move to right bank should be ok by driving boat"){
         REQUIRE(cop.move(boat));
         REQUIRE(boat.moveTo(&rightBank));
         REQUIRE(cop.move(rightBank));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(cop.move(boat));
         REQUIRE(cop.move(leftBank));
      }
   }

}