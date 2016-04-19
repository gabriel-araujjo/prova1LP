#include <cmath>

#include "questao1.h"

double soma_sequencia_r(int n) {
	if (n < 1) return 0;
	return 1.0/pow(2.0, (double) n) + soma_sequencia_r(n -1);
}

double soma_sequencia_i(int n) {
	double result = 0;
	for(; n > 0; n--) {
		result += 1.0/pow(2.0, (double) n);
	}
	return result;
}
