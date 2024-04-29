#include "romanos.hpp"
#include <stdexcept>  // para usar a exceção std::invalid_argument 
#include <cctype>  // para usar isdigit()

int romanos_para_decimal(char const * numero_romano) {
  // variável decimal armazena o resultado,
  // a variável último seria o valor do último algarismo verifcado
  int decimal = 0;
  int ultimo = 0;

  while (*numero_romano) {

      if (isdigit(*numero_romano)) {// se o caractere é um dígito decimal
        throw std::invalid_argument("Algarismo inválido. É um dígito decimal.");
      }

      int atual = 0;
      // determina o valor decimal do algarismo atual
      switch (*numero_romano) {
          case 'I': atual = 1; break;
          case 'V': atual = 5; break;
          case 'X': atual = 10; break;
          case 'L': atual = 50; break;
          case 'C': atual = 100; break;
          case 'D': atual = 500; break;
          case 'M': atual = 1000; break;
          default: throw std::invalid_argument("Algarismo inválido encontrado.");
      }

      // verificaçao que indica uma dupla válida. Se sim,subtrai os valores
      if (atual > ultimo) {
          decimal += atual - 2 * ultimo;
      } else {  // caso contrário,soma o valor decimal atual ao total
          decimal += atual;
      }

      ultimo = atual;  // atualiza o último algarismo verificado
      numero_romano++;  // prox caractere
  }

  // após encerrar o loop, retorna o valor decimal resultante
  return decimal;
}
