#include "questoes4-5-6-7-8.h"
#include <string.h>
#include <vector>

bool comparador_nomes(TIndiceNome a, TIndiceNome b) {
	return strcmp(a.nome, b.nome) > 0;	
}

bool comparador_nome_matricula_idade(TIndiceNomeMatriculaIdade a, TIndiceNomeMatriculaIdade b) {
	int comparacao = strcmp(a.nome, b.nome);	
	if (comparacao != 0) {
		return comparacao > 0;
	}
	comparacao = a.matricula - b.matricula;
	if (comparacao != 0) {
		return comparacao > 0;
	}
	return a.idade - b.idade;	
}

bool comparador_nome_matricula(TIndiceNomeMatriculaIdade a, TIndiceNomeMatriculaIdade b) {
	int comparacao = strcmp(a.nome, b.nome);	
	if (comparacao != 0) {
		return comparacao > 0;
	}
	return a.matricula - b.matricula;
}

int busca_binaria_recursiva (
	char nome[],
	std::vector<TIndiceNome> index, 
	std::vector<TIndiceNome>::iterator inicio, 
	std::vector<TIndiceNome>::iterator fim) {

    if( inicio > fim ){
        return -1; // INSUCESSO
    }
	std::vector<TIndiceNome>::iterator meio = inicio + std::distance(inicio, fim)/2;
    if( strcmp(nome, (*meio).nome) < 0){
        // Continua a busca na parte esquerda
        return busca_binaria_recursiva (nome, index, inicio, meio-1);
    }
    else if( strcmp(nome, (*meio).nome) > 0 ){
        // Continua a busca na parte direita
        return busca_binaria_recursiva (nome, index, meio+1, fim);
    }
    else{
        return meio - index.begin(); // SUCESSO
    }
}

// questao 4
std::vector<TIndiceNome> indexar_por_nome(std::vector<TAssinante> &assinantes) {
	return indexar_por_nome(assinantes, 
		default_sort(comparador_nomes));
}

// questao 5
int buscar_por_nome(std::vector<TIndiceNome> indice_de_nomes, char nome[]) {
	return busca_binaria_recursiva(nome, indice_de_nomes, indice_de_nomes.begin(), indice_de_nomes.end());
}

// questao 6
std::vector<TIndiceNomeMatriculaIdade> indexar_por_nome_matricula_idade(
		std::vector<TAssinante> assinantes) {
	return indexar_por_nome_matricula_idade(assinantes, 
		default_sort(comparador_nome_matricula_idade))
}

// questao 7
int buscar_por_nome_e_matricula(std::vector<TIndiceNomeMatriculaIdade> index, char nome[], int matricula) {
	// Falta
	return -1;
}


// questao 8
std::vector<TIndiceNome> indexar_por_nome(
		std::vector<TAssinante> &assinantes,
		void (*sort_impl)(std::vector<TIndiceNome>)) {
	
	std::vector<TIndiceNome> indexes;
	int i = 0;
	std::vector<TAssinante>::iterator it = assinantes.begin();	
	for ( ; it != assinantes.end(); ++it, ++i) {
		TAssinante a = *it;
		TIndiceNome entrada = {a.nome, i};
		indexes.push_back(entrada);
	}

	sort_impl(indexes);
	return indexes;
}

std::vector<TIndiceNomeMatriculaIdade> indexar_por_nome_matricula_idade(
		std::vector<TAssinante> assinantes, 
		void (*sort_impl)(std::vector<TIndiceNomeMatriculaIdade>)) {
	
	std::vector<TIndiceNomeMatriculaIdade> indexes;
	int i = 0;
	std::vector<TAssinante>::iterator it = assinantes.begin();	
	for ( ; it != assinantes.end(); ++it, ++i) {
		TAssinante a = *it;
		TIndiceNomeMatriculaIdade entrada = {a.nome, a.matricula, a.idade, i};
		indexes.push_back(entrada);
	}

	sort_impl(indexes);
	return indexes;
}
