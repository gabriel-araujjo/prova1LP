#include <string>

#include "questao2.h"

int junta(int a, int b) {
	return a + b;
}

double junta(double a, double b) {
	return a + b;
}

std::string junta(char a, char b) {
	std::string result;
	return result + a + b;
}

std::string junta(std::string a, std::string b) {
	return a + b;
}
