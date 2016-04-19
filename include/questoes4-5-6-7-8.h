#ifndef QUESTOES_4_5_6_7_8_H_
#define QUESTOES_4_5_6_7_8_H_

#include <vector>

#define SEXO_MASCULINO 'M'
#define SEXO_FEMININO 'F'
#define SEXO_OUTRO 'O'

typedef struct {
	int matricula;
	int idade;
	double altura;
	char sexo;
	char nomecompleto[80];
	char nome[40];
	char sobrenome[40];
} TAssinante;

typedef struct {
	char nome[40];
	int indice;
} TIndiceNome;

typedef struct {
	char nome[40];
	int matricula;
	int idade;
	int indice;
} TIndiceNomeMatriculaIdade;

template<class Indice>
void (*default_sort(std::vector<Indice>))(bool (*comparator)(Indice, Indice)) {
	return [](std::vector<Indice> indices)->{	
		std::sort (indices.begin(), indices.end(), comparator);
	}
}

// questao 4
std::vector<TIndiceNome> indexar_por_nome(std::vector<TAssinante> assinantes);

// questao 5
int buscar_por_nome(std::vector<TIndiceNome> indice_de_nomes, char nome[]);

// questao 6
std::vector<TIndiceNomeMatriculaIdade> indexar_por_nome_matricula_idade(std::vector<TAssinante> assinantes);

// questao 7
int buscar_por_nome_e_matricula(std::vector<TIndiceNomeMatriculaIdade> index, char nome[], int matricula);

// questao 8
std::vector<TIndiceNome> indexar_por_nome(std::vector<TAssinante> assinantes, void (*sort_impl)(std::vector<TIndiceNome>));

std::vector<TIndiceNomeMatriculaIdade> indexar_por_nome_matricula_idade(std::vector<TAssinante> assinantes, void (*sort_impl)(std::vector<TIndiceNomeMatriculaIdade>));

#endif // QUESTOES_4_5_6_7_8_H_
