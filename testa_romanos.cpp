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
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("O") == -1);
    REQUIRE(romanos_para_decimal("a") == -1);
    REQUIRE(romanos_para_decimal("g") == -1);
    REQUIRE(romanos_para_decimal("k") == -1);
    REQUIRE(romanos_para_decimal("H") == -1);
    REQUIRE(romanos_para_decimal("A") == -1);
    REQUIRE(romanos_para_decimal("U") == -1);
    REQUIRE(romanos_para_decimal("z") == -1);
    REQUIRE(romanos_para_decimal("w") == -1);

    // números e símbolos que não são válidos em números romanos
    REQUIRE(romanos_para_decimal("0") == -1);
    REQUIRE(romanos_para_decimal("1") == -1);
    REQUIRE(romanos_para_decimal("2") == -1);
    REQUIRE(romanos_para_decimal("3") == -1);
    REQUIRE(romanos_para_decimal("4") == -1);
    REQUIRE(romanos_para_decimal("5") == -1);
    REQUIRE(romanos_para_decimal("6") == -1);
    REQUIRE(romanos_para_decimal("7") == -1);
    REQUIRE(romanos_para_decimal("8") == -1);
    REQUIRE(romanos_para_decimal("9") == -1);
    REQUIRE(romanos_para_decimal("!") == -1);
    REQUIRE(romanos_para_decimal("@") == -1);
    REQUIRE(romanos_para_decimal("#") == -1);
    REQUIRE(romanos_para_decimal("$") == -1);
    REQUIRE(romanos_para_decimal("~") == -1);
    REQUIRE(romanos_para_decimal("?") == -1);
    REQUIRE(romanos_para_decimal(",") == -1);
    REQUIRE(romanos_para_decimal(".") == -1);
    REQUIRE(romanos_para_decimal(" ") == -1);
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
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("LL") == -1);
    REQUIRE(romanos_para_decimal("DD") == -1);

    // sequencia entre dois números sem relação
    REQUIRE(romanos_para_decimal("XM") == -1);
    REQUIRE(romanos_para_decimal("LM") == -1); 
    REQUIRE(romanos_para_decimal("DM") == -1); 
    REQUIRE(romanos_para_decimal("VM") == -1);  

    // algarismos que não são permitidos juntos
    REQUIRE(romanos_para_decimal("IIII") == -1);
    REQUIRE(romanos_para_decimal("VVVV") == -1);
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("LLLL") == -1);
    REQUIRE(romanos_para_decimal("CCCC") == -1);
    REQUIRE(romanos_para_decimal("DDDD") == -1);
    REQUIRE(romanos_para_decimal("MMMM") == -1);

    // máximo permitidp
    REQUIRE(romanos_para_decimal("MMMIII") == -1);

    // string de tamanho maior que 30
    REQUIRE(romanos_para_decimal("MMXIXMMXIXMMXIXMMXIXMMXIXMMXIXMMXIXMMXIXMMXIXMMXIXMMXIX") == -1);

    // mistura subtração e adição de maneira inválida
    REQUIRE(romanos_para_decimal("IVI") == -1);
    REQUIRE(romanos_para_decimal("XLX") == -1);
    REQUIRE(romanos_para_decimal("CMC") == -1);
    REQUIRE(romanos_para_decimal("IVX") == -1);
    REQUIRE(romanos_para_decimal("XLC") == -1);
    REQUIRE(romanos_para_decimal("IVI") == -1);
    REQUIRE(romanos_para_decimal("IVIV") == -1);
    REQUIRE(romanos_para_decimal("IXIX") == -1);
    REQUIRE(romanos_para_decimal("XCXC") == -1);
};

TEST_CASE("Numeros romanos - comb. de carac. não permitidos", "[romanos]") {
    // o switch case não aceita caracteres inválidos, não é precisa testar todos
    // combinações de caracteres não permitidos com caracteres válidos
    REQUIRE(romanos_para_decimal("Ia") == -1);
    REQUIRE(romanos_para_decimal("Ld") == -1);
    REQUIRE(romanos_para_decimal("Df") == -1);
    REQUIRE(romanos_para_decimal("EF") == -1);
    REQUIRE(romanos_para_decimal("OP") == -1);
    REQUIRE(romanos_para_decimal("YZ") == -1);

    // Combinações de caracteres especiais e símbolos com caracteres válidos
    REQUIRE(romanos_para_decimal("I!") == -1);
    REQUIRE(romanos_para_decimal("V@") == -1);
    REQUIRE(romanos_para_decimal("X#") == -1);
    REQUIRE(romanos_para_decimal("D^") == -1);
    REQUIRE(romanos_para_decimal("M&") == -1);
};
