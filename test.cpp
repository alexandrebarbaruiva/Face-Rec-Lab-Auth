#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcoes.cpp"

TEST_CASE("Verificação de acesso", "[porta liberada]") {
    REQUIRE( processo(0) == 0 );
    REQUIRE( processo(1) == 1 );
    REQUIRE( processo(2) == 2 );
    REQUIRE( processo(3) == 3 );
    REQUIRE( processo(100) == -1 );

}
