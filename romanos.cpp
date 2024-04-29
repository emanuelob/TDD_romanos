#include "romanos.hpp"
#include <stdexcept>  // para usar a exceção std::invalid_argument
#include <cctype>  // para usar toupper()
#include <cstring>  // para usar std::strlen

int romanos_para_decimal(char const * numero_romano) {
  // variável decimal armazena o resultado,
  // a variável último seria o valor do último algarismo verifcado
  int decimal = 0;
  int ultimo = 0;
  bool subtracao = false;
  int terceiraLetra = 0;
  int quartaLetra = 0;

  if (!numero_romano || !*numero_romano) {
    throw std::invalid_argument("Número romano vazio.");
  }

  while (*numero_romano) {
      char caractere_romano = toupper(*numero_romano);
      int atual = 0;
      // determina o valor decimal do algarismo atual
      switch (caractere_romano) {
          case 'I': atual = 1; break;
          case 'V': atual = 5; break;
          case 'X': atual = 10; break;
          case 'L': atual = 50; break;
          case 'C': atual = 100; break;
          case 'D': atual = 500; break;
          case 'M': atual = 1000; break;
          default: throw std::invalid_argument("Algarismo inválido.");
      }

      // se o último algarismo for menor que o atual e a combinação for válida,
      // subtrai o valor do último do total.
      if (ultimo < atual) { 
          // se o último algarismo não pode ser subtraído, como V, L ou D
          if (ultimo == 5 || ultimo == 50 || ultimo == 500) {
          throw std::invalid_argument("Combinação de subtração inválida.");
          } else {
              decimal += atual - 2 * ultimo;
              subtracao = ultimo != 0;
          }
      } else if (ultimo == atual) {
          // se o algarismo atual é um dos que podem ser repetidos, como I, X, C ou M
          if (atual == 1 || atual == 10 || atual == 100 || atual == 1000) {
              decimal += atual;
              subtracao = false;
          } else {
              throw std::invalid_argument("Combinação inválida. Algarismos não repetem.");
          }
      } else {
        decimal += atual;
        subtracao = false;
      }

      // verifica quantas vezes o caractere se repete: IIII, XXXX, CCCC, MMMM
      int repeticoes = 1;
      while (*(numero_romano + repeticoes) && toupper(*(numero_romano + repeticoes)) == caractere_romano) {
        repeticoes++;
      }
      // se o número de repetições for maior que 3, lança uma exceção
      if (repeticoes > 3) { 
        throw std::invalid_argument("Combinação inválida. Algarismos não repetem.");
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
        }

        if (subtracao && ultimo == terceiraLetra) {
            throw std::invalid_argument("Subtração seguida de adição inválida. Exemplo: IXI, IVI...");
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
            }
            
            if (subtracao && quartaLetra < terceiraLetra) {
              throw std::invalid_argument("Subtração seguida de subtração inválida...");
            }
        }
      }
    
      ultimo = atual;
      numero_romano++;
    }
    
  return decimal;
}