#ifndef _LOG_UTIL_H_
#define _LOG_UTIL_H_

#include <iostream>
#include <stdio.h>

#define ERRO(...) { \
	char buffer [255]; \
	sprintf(buffer, __VA_ARGS__); \
	std::cout << "\t\033[1;31m✘\033[0m\t\033[31m" << buffer << "\033[0m\n"; \
}

#define SUCESSO(...) { \
	char buffer [255]; \
	sprintf(buffer, __VA_ARGS__); \
	std::cout << "\t\033[1;32m✔\033[0m\t\033[32m" << buffer << "\033[0m\n"; \
}

#endif // _LOG_UTIL_H_
