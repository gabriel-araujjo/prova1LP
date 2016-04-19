#include "log_util.h"
#include "questao3.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

enum ComparationType {INTEIRO, PONTO_FLUTUANTE, CARACTER, STRING};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

void test_cases(const char * cases_path, ComparationType type, const char * mensagem_sucesso, const char * mensagem_erro);


template <class T>
void assert_test(T a, T b, std::string esperado, const char * mensagem_sucesso, const char * mensagem_erro) {
	std::string::size_type sz;
	double result = std::stod (esperado, &sz);
	if (result - junta(a, b) < 0.01) {
		SUCESSO(mensagem_sucesso, esperado.c_str(), a, b);
	} else {
		ERRO(mensagem_erro, esperado.c_str(), a, b, junta(a,b));
	}
}

template<>
void assert_test(char a, char b, std::string esperado, const char * mensagem_sucesso, const char * mensagem_erro) {
	if (esperado.compare(junta_char(a, b)) == 0) {
		SUCESSO(mensagem_sucesso, esperado.c_str(), a, b);
	} else {
		ERRO(mensagem_erro, esperado.c_str(), a, b, junta_char(a,b).c_str());
	}
}


template<>
void assert_test(std::string a, std::string b, std::string esperado, const char * mensagem_sucesso, const char * mensagem_erro) {
	if (esperado.compare(junta(a, b)) == 0) {
		SUCESSO(mensagem_sucesso, esperado.c_str(), a.c_str(), b.c_str());
	} else {
		ERRO(mensagem_erro, esperado.c_str(), a.c_str(), b.c_str(), junta(a,b).c_str());
	}
}

int main (int argc, char **argv) {

	std::cout << std::endl << "Testando junta inteiros " << std::endl;
	test_cases("test/cases/junta_inteiros_cases.txt", INTEIRO, "%s é a soma entre %d e %d", "%s é a soma entre %d e %d, mas %d for retornado");

	std::cout << std::endl << "Testando junta ponto flutuante " << std::endl;
	test_cases("test/cases/junta_doubles_cases.txt", PONTO_FLUTUANTE, "%s é a soma entre %f e %f", "%s é a soma entre %f e %f, mas %f for retornado");

	std::cout << "Testando junta caracteres " << std::endl;
	test_cases("test/cases/junta_chars_cases.txt", CARACTER, "'%s' é a concatenação entre '%c' e '%c'", "'%s' é a concatenação entre '%c' e '%c', mas '%s' foi retornado");

	std::cout << std::endl << "Testando junta string " << std::endl;
	test_cases("test/cases/junta_strings_cases.txt", STRING, "\"%s\" é a concatenação entre \"%s\" e \"%s\"", "\"%s\" é a concatenação entre \"%s\" e \"%s\", mas \"%s\" for retornado");
}

void test_cases(const char * cases_path, ComparationType type, const char * mensagem_sucesso, const char * mensagem_erro) {
	std::ifstream cases;
	cases.open(cases_path);
	if(!cases.is_open( ))
    {
        std::cout << "Não foi possível abrir arquivo " << cases_path << "Programa será terminado!" << std::endl;
        cases.clear( );
		exit(1);
    }
	switch(type) {
		case INTEIRO: {
			int a, b;
			std::string esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
		case PONTO_FLUTUANTE: {
			float a, b;
			std::string esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
		case CARACTER: {
			char a, b;
			std::string esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::stringstream lineStream(line);

				lineStream >> a >> b >> esperado;
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
		case STRING: {
			std::string a, b, esperado;
			std::string line;
			while (std::getline(cases, line)) {
				std::vector<std::string> elems;
				split(line, ' ', elems);
				a = elems[0];
				b = elems[1];
				esperado = elems[2];
		
				assert_test(a, b, esperado, mensagem_sucesso, mensagem_erro);
			}
			break;
		}
	}
	cases.close();
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
