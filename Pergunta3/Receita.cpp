#include "Receita.h"



Receita::Receita(const string& nome, const string& descricao) {
	this->nome = nome;
	this->descricao = descricao;
	this->capacidade = 10;      
	this->nrIngredientes = 0;   
	ingredientes = new Ingredientes * [capacidade];

	for (int i = 0; i < capacidade; i++) {
		ingredientes[i] = nullptr;
	}
}



Receita::~Receita() {
	for (int i = 0; i < capacidade; i++) {
		if (ingredientes[i] != nullptr) {
			delete ingredientes[i];
		}
	}
	delete[] ingredientes;
}
Receita::Receita(const Receita& outra) {}


Receita::Receita& operator=(const Receita& outra) {

}

void Receita::acrescentarIngrediente(const string& nome, int valor) {

}
string Receita::obtemRepresentacaoTextual() const {

}

