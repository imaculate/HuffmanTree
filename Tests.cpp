#define CATCH_CONFIG_MAIN  
#include "catch.hpp"



TEST_CASE( "Frequency counting", "[frequency]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE ("Tree construction","[tree]"){
}

TEST_CASE("Code table construction"){
   
}

TEST_CASE("Encoding"){
   
}