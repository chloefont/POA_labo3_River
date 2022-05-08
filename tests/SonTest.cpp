#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Son" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft);

   Father father("Father", &bankLeft);
   Mother mother("Mother", &bankLeft);
   Son son("Son", &father, &mother, &bankLeft);


   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(son.check());
      }

      SECTION("Should return false"){
         CHECK(false == son.check());
      }

      SECTION("Should return true"){
         CHECK(true == son.check());
      }
   }

   SECTION( "getFather()" ) {
      SECTION("Should return father"){
         CHECK(&father == son.getFather());
      }
   }

   SECTION( "getMother()" ) {
      SECTION("Should return father"){
         CHECK(&mother == son.getMother());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(false == son.canDrive());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Son" == son.getName());
      }
   }

   SECTION("move()"){
      SECTION("Move to boat should be ok"){
         REQUIRE(son.move(boat));
      }

      SECTION("Move to right bank should be ok"){
         REQUIRE(son.move(bankRight));
      }

      SECTION("Move back to left bank should be ok"){
         REQUIRE(son.move(boat));
         REQUIRE(son.move(bankLeft));
      }
   }

}

