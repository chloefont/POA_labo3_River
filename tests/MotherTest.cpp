#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Mother" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft, 2);

   Mother mother("Mother", &bankLeft);


   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(mother.check());
      }

      SECTION("Should return true"){
         CHECK(true == mother.check());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Mother" == mother.getName());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(true == mother.canDrive());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(mother.move(boat));
      }

      SECTION("Move to right bank should be ok"){
         REQUIRE(mother.move(bankRight));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(mother.move(boat));
         REQUIRE(mother.move(bankLeft));
      }
   }

}

