#ifndef QUESTAO_2_H_
#define QUESTAO_2_H_

/**
 * Retorna a soma entre a e b
 * @param a - número inteiro
 * @param b - número inteiro
 * @return a + b
 */
int junta(int a, int b);

/**
 * Retorna a soma entre a e b
 * @param a - número em ponto flutuante com precisão dupla
 * @param b - número em ponto flutuante com precisão dupla
 * @return a + b
 */
double junta(double a, double b);

/**
 * Retorna uma string contendo a concatenação de a com b
 * @param a - um caracter
 * @param b - um caracter
 * @return ab
 */
std::string junta(char a, char b);

/**
 * @param a - string qualquer
 * @param b - string qualquer
 * @return uma nova string contendo a concatenação de a com b
 */
std::string junta(std::string a, std::string b);

#endif // QUESTAO_2_H_
