#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos únicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("X") == 10);
    REQUIRE(romanos_para_decimal("L") == 50);
    REQUIRE(romanos_para_decimal("C") == 100);
    REQUIRE(romanos_para_decimal("D") == 500);
    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - algarismos subtraidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("XC") == 90);
    REQUIRE(romanos_para_decimal("CD") == 400);
    REQUIRE(romanos_para_decimal("CM") == 900);
};

TEST_CASE("Numeros romanos - algarismos repetidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("III") == 3);
    REQUIRE(romanos_para_decimal("VII") == 7);
    REQUIRE(romanos_para_decimal("VIII") == 8);
    REQUIRE(romanos_para_decimal("XX") == 20);
    REQUIRE(romanos_para_decimal("XXX") == 30);
    REQUIRE(romanos_para_decimal("LXX") == 70);
    REQUIRE(romanos_para_decimal("LXXX") == 80);
    REQUIRE(romanos_para_decimal("CC") == 200);
    REQUIRE(romanos_para_decimal("CCC") == 300);
    REQUIRE(romanos_para_decimal("DCC") == 700);
    REQUIRE(romanos_para_decimal("DCCC") == 800);
    REQUIRE(romanos_para_decimal("MM") == 2000);
    REQUIRE(romanos_para_decimal("MMM") == 3000);
};

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
    // o switch case não aceita caracteres inválidos, não é precisa testar todos
    // algumas letras maiúsculas e minúsculas que não são válidas em num romanos
    REQUIRE_THROWS_AS(romanos_para_decimal("G"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("O"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("i"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("v"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("x"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("H"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("A"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("U"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("d"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("m"), std::invalid_argument);

    // números e símbolos que não são válidos em números romanos
    REQUIRE_THROWS_AS(romanos_para_decimal("0"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("1"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("2"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("3"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("4"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("5"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("6"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("7"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("8"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("9"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("!"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("@"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("#"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("$"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("%"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("^"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("&"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("*"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(":"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(";"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("'"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("`"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("~"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("?"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("/"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(","), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("."), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(" "), std::invalid_argument);
};
