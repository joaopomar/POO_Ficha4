#pragma once
#include <string>
#include "Ingredientes.h"

using namespace std;


class Receita
{
	string descricao;
	string nome;
	int nrIngredientes;
	int capacidade;
	Ingredientes** ingredientes;


public:

	Receita(const string& nome, const string& descricao);
	Receita(const Receita& outra);              
	~Receita();
	Receita& operator=(const Receita& outra);   

	void acrescentarIngrediente(const string& nome, int valor);
	string obtemRepresentacaoTextual() const;
};

