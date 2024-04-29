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
    // algumas letras que não são válidas em num romanos
    REQUIRE_THROWS_AS(romanos_para_decimal("G"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("O"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("a"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("g"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("k"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("H"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("A"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("U"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("z"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("w"), std::invalid_argument);

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
    REQUIRE_THROWS_AS(romanos_para_decimal("~"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("?"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(","), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("."), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal(" "), std::invalid_argument);
};

TEST_CASE("Numeros romanos - combinações de algarismos", "[romanos]") {
    // combinações de soma de algarismos
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("CX") == 110);
    REQUIRE(romanos_para_decimal("DC") == 600);
    REQUIRE(romanos_para_decimal("MC") == 1100);

    // combinações de subtração de algarismos
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("CM") == 900);

    // combinações de soma e subtração
    REQUIRE(romanos_para_decimal("XIX") == 19);
    REQUIRE(romanos_para_decimal("XLV") == 45);
    REQUIRE(romanos_para_decimal("CDXLIV") == 444);
    REQUIRE(romanos_para_decimal("CMXCIV") == 994);
    REQUIRE(romanos_para_decimal("MMDCCCLXXXVIII") == 2888);
};

TEST_CASE("Numeros romanos - combinações inválidas", "[romanos]") {
    // algarismos que não podem ser repetidos
    REQUIRE_THROWS_AS(romanos_para_decimal("VV"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("LL"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("DD"), std::invalid_argument);

    // algarismos que não são permitidos juntos
    REQUIRE_THROWS_AS(romanos_para_decimal("IIII"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("VVVV"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("XXXX"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("LLLL"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("CCCC"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("DDDD"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("MMMM"), std::invalid_argument);

    // mistura subtração e adição de maneira inválida
    REQUIRE_THROWS_AS(romanos_para_decimal("IVI"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("XLX"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("CMC"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("IVX"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("XLC"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("IVI"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("IVIV"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("IXIX"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("XCXC"), std::invalid_argument);
};

TEST_CASE("Numeros romanos - combinações de caracteres não permitidos", "[romanos]") {
    // o switch case não aceita caracteres inválidos, não é precisa testar todos
    // combinações de caracteres não permitidos com caracteres válidos
    REQUIRE_THROWS_AS(romanos_para_decimal("Ia"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("Ld"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("Df"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("EF"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("OP"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("YZ"), std::invalid_argument);

    // Combinações de caracteres especiais e símbolos com caracteres válidos
    REQUIRE_THROWS_AS(romanos_para_decimal("I!"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("V@"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("X#"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("D^"), std::invalid_argument);
    REQUIRE_THROWS_AS(romanos_para_decimal("M&"), std::invalid_argument);
};