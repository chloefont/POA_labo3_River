#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../Container/Bank.h"
#include "../Container/Boat.h"

TEST_CASE( "Son" ) {
   Bank bankLeft("Left");
   Bank bankRight("Right");
   Boat boat("Boat", &bankLeft, 2);

   Father father("Father", &bankLeft, nullptr);
   Mother mother("Mother", &bankLeft, nullptr);
   Son son("Son", &father, &mother, &bankLeft, nullptr);


   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(son.check());
      }

      SECTION("Should return false"){
         Mother mother2("Mother", &bankRight, nullptr);
         Son son2("Son", &father, &mother2, &bankRight, nullptr);
         CHECK(false == son2.check());
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

   SECTION("Cannot stay with mother if father is not there"){
      SECTION("Father cannot leave his son with mother"){
         REQUIRE(father.move(boat) == false);
      }

      SECTION("Mother can leave her son with father") {
         REQUIRE(mother.move(boat) == true);
      }
   }

}

