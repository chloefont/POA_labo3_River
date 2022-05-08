#include "catch.hpp"
#include "../persons/Son.hpp"

TEST_CASE( "Father" ) {
   Father father("Father");

   SECTION("check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(father.check());
      }

      SECTION("Should return false"){
         CHECK(false == father.check());
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

}

