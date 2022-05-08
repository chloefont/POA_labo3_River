#include "catch.hpp"
#include "../persons/Son.hpp"

TEST_CASE( "Mother" ) {
   Mother mother("Mother");

   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(mother.check());
      }

      SECTION("Should return false"){
         CHECK(false == mother.check());
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

}

