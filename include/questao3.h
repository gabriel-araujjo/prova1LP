#ifndef QUESTAO_3_H_
#define QUESTAO_3_H_

#include <string>

template<class T>
T junta(T a, T b) {
	return a + b;
}

/**
 * Não dá para especializar junta com caracteres pois o retorno não é outro
 * caracter
 */
std::string junta_char(char a, char b);

#endif // QUESTAO_3_H_
