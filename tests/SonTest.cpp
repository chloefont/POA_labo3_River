#include "catch.hpp"
#include "../persons/Son.hpp"

TEST_CASE( "Son" ) {
   Father father("Father");
   Mother mother("Mother");
   Son son("Son", &father, &mother);

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

}

