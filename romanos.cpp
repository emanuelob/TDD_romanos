#include "romanos.hpp"
#include <cctype>  // para usar toupper()
#include <cstring>  // para usar std::strlen
#include <unordered_map>  // para usar std::unordered_map
#include <string>  // para usar std::string

int romanos_para_decimal(char const * numero_romano) {
  int decimal = 0;
  int ultimo = 0;
  bool subtracao = false;
  int terceiraLetra = 0;
  int quartaLetra = 0;
  int valor_maximo = 0;

  int tamanho = 0;
  while (numero_romano[tamanho] != '\0') {
      tamanho++;
      if (tamanho >= 30) {
          return -1;  // tamanho exceder 30 caracteres
      }
  }

  static const std::unordered_map<char, std::string> pares_invalidos = {
    {'X', "MD"},
    {'L', "MD"},
    {'D', "MD"},
    {'V', "MDCLX"}
  };

  while (*numero_romano) {
      char caractere_romano = toupper(*numero_romano);
      int atual = 0;
      switch (caractere_romano) {
          case 'I': atual = 1; break;
          case 'V': atual = 5; break;
          case 'X': atual = 10; break;
          case 'L': atual = 50; break;
          case 'C': atual = 100; break;
          case 'D': atual = 500; break;
          case 'M': atual = 1000; break;
          default: return -1;
      }

      valor_maximo += atual;
      if (valor_maximo > 3000) {
          return -1;
      }

      if (*(numero_romano + 1) && pares_invalidos.count(caractere_romano) &&
      pares_invalidos.at(caractere_romano).find(toupper(*(numero_romano + 1)))
      != std::string::npos) {
          return -1;
      }

      if (ultimo < atual) {
          // se o último algarismo não pode ser subtraído, como V, L ou D
          if (ultimo == 5 || ultimo == 50 || ultimo == 500) {
            return -1;
          } else {
              decimal += atual - 2 * ultimo;
              subtracao = ultimo != 0;
          }
      } else if (ultimo == atual) {
          // se o algarismo atual é um dos que podem ser repetidos
          if (atual == 1 || atual == 10 || atual == 100 || atual == 1000) {
              decimal += atual;
              subtracao = false;
          } else {
              return -1;
          }
      } else {
        decimal += atual;
        subtracao = false;
      }

      // verifica quantas vezes o caractere se repete: IIII, XXXX, CCCC, MMMM
      int repeticoes = 1;
      while (*(numero_romano + repeticoes) &&
      toupper(*(numero_romano + repeticoes)) == caractere_romano) {
        repeticoes++;
      }
      // se o número de repetições for maior que 3, lança uma exceção
      if (repeticoes > 3) {
        return -1;
      }

      if (subtracao && *(numero_romano + 1)) {
        char proximo_caractere = toupper(*(numero_romano + 1));
        switch (proximo_caractere) {
            case 'I': terceiraLetra = 1; break;
            case 'V': terceiraLetra = 5; break;
            case 'X': terceiraLetra = 10; break;
            case 'L': terceiraLetra = 50; break;
            case 'C': terceiraLetra = 100; break;
            case 'D': terceiraLetra = 500; break;
            case 'M': terceiraLetra = 1000; break;
            default: return -1;
        }

        if (subtracao && ultimo == terceiraLetra) {
            return -1;
        }

        if (terceiraLetra >= 10 && *(numero_romano + 2)) {
            char quarto_caractere = toupper(*(numero_romano + 2));
            switch (quarto_caractere) {
                case 'I': quartaLetra = 1; break;
                case 'V': quartaLetra = 5; break;
                case 'X': quartaLetra = 10; break;
                case 'L': quartaLetra = 50; break;
                case 'C': quartaLetra = 100; break;
                case 'D': quartaLetra = 500; break;
                case 'M': quartaLetra = 1000; break;
                default: return -1;
            }
            if (subtracao && quartaLetra < terceiraLetra) {
              return -1;
            }
        }
      }
      ultimo = atual;
      numero_romano++;
    }
  return decimal;
}
