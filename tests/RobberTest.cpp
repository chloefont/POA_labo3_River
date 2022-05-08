
#include "catch.hpp"
#include "../persons/Son.hpp"
#include "../persons/Robber.hpp"
#include "../persons/Daughter.hpp"

TEST_CASE( "Robber" ) {
   Father father("Father");
   Mother mother("mother");
   Son son1("Son1", &father, &mother);
   Son son2("Son2", &father, &mother);
   Daughter daughter1("Daughter1", &father, &mother);
   Daughter daughter2("Daughter2", &father, &mother);
   Cop cop("Cop");
   FamilyList familyList = {
      &father,
      &mother,
      &son1,
      &son2,
      &daughter1,
      &daughter2
   };
   Robber robber("Robber", familyList, &cop);

   SECTION("Check()"){
      SECTION("Should not throw exception"){
         REQUIRE_NOTHROW(robber.check());
      }

      SECTION("Should return false"){
         CHECK(false == robber.check());
      }

      SECTION("Should return true"){
         CHECK(true == robber.check());
      }
   }

   SECTION( "getFamily()" ) {
      SECTION("Should return the family"){
         CHECK(familyList == robber.getFamily());
      }
   }

   SECTION( "getName()" ) {
      SECTION("Should return father"){
         CHECK("Robber" == robber.getName());
      }
   }

   SECTION( "canDrive()" ) {
      SECTION("Should return false"){
         CHECK(false == robber.canDrive());
      }
   }

   SECTION( "getCop()" ) {
      SECTION("Should return false"){
         CHECK(&cop == robber.getCop());
      }
   }

}

