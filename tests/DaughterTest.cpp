
#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../persons/Daughter.hpp"

TEST_CASE( "Daughter" ) {
   Father father("Father");
   Mother mother("Mother");
   Daughter daughter("Daughter", &father, &mother);

   SECTION("Check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(daughter.check());
      }

      SECTION("Should return false"){
         CHECK(false == daughter.check());
      }

      SECTION("Should return true"){
         CHECK(true == daughter.check());
      }
   }
   SECTION( "getFather()" ) {
      SECTION("Should return father"){
         CHECK(&father == daughter.getFather());
      }
   }

   SECTION( "getMother()" ) {
      SECTION("Should return father"){
         CHECK(&mother == daughter.getMother());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(false == daughter.canDrive());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return name"){
         CHECK("Daughter" == daughter.getName());
      }
   }

}