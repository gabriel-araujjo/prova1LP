#include "log_util.h"
#include "questao1.h"

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

void test_cases(const char * cases_path, double (*sum)(int));

void assert_test(double (*sum)(int), int elements, double result, const char * success_message, const char * error_message);

int main (int argc, char **argv) {
	std::cout << "Testando soma de progressão geométrica (implementação recursiva) " << std::endl;
	test_cases("test/cases/soma_pg_cases.txt", soma_sequencia_r);

	std::cout << std::endl << "Testando implementação iterativa " << std::endl;
	test_cases("test/cases/soma_pg_cases.txt", soma_sequencia_i);
}

void test_cases(const char * cases_path, double (*sum)(int)) {
	std::ifstream cases;
	cases.open(cases_path);
	if(!cases.is_open( ))
    {
        std::cout << "Não foi possível abrir arquivo " << cases_path << "Programa será terminado!" << std::endl;
        cases.clear( );
		exit(1);
    }
	// A entrada da função
	int n;
	// O valor esperado de retorno
	double result;
	// Linha do arquivo de teste
	std::string line;
	while (std::getline(cases, line)) {
		std::stringstream lineStream(line);

		lineStream >> n >> result;
		
		assert_test(sum, n, result, 
			"%f foi retornado para a soma dos %d primeiros elementos",
			"%f deveria ser retornado para a soma dos %d primeiros elementos, %f era esperado");
	}
	cases.close();
}

void assert_test(double (*sum)(int), int elements, double result, const char * success_message, const char * error_message) {
    if (std::abs(sum(elements) - result) < 0.001) {
		SUCESSO(success_message, result, elements);
	} else {
		ERRO(error_message, result, elements, sum(elements));
	}
}
