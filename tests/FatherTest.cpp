#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Father" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft, 2);

   Father father("Father", &bankLeft, nullptr);


   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(father.check());
      }

      SECTION("Should return true"){
         CHECK(true == father.check());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Father" == father.getName());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(true == father.canDrive());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(father.move(boat));
      }

      SECTION("Move to right bank should be ok by driving boat"){
         REQUIRE(father.move(boat));
         REQUIRE(boat.moveTo(&bankRight));
         REQUIRE(father.move(bankRight));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(father.move(boat));
         REQUIRE(father.move(bankLeft));
      }
   }

}

