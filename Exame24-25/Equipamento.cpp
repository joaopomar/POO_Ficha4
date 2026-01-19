#include "Equipamento.h"
#include <iostream>
#include <sstream>
using namespace std;


int Equipamento::proxID = 1000;

Equipamento::Equipamento(const string& nome, int preco) {


	if (nome == "" || preco <= 0) {
		throw invalid_argument("Nome vazio ou preco invalido!");
	}
	this->nome = nome;
	this->preco = preco;
	this->id = proxID;
	proxID++;

	}


Equipamento::Equipamento() 
    : nome(""), preco(0), id(0) {
    
}


string Equipamento::representacaoTextual() const {
	ostringstream oss;
	oss << "Produto [id: '" << id << "', Nome: '" << nome << "', Preço: '" << preco << "']";
	return oss.str();
}

 ostream& operator<<(ostream& oss, const Equipamento& e) {
	 oss << e.representacaoTextual();
	 return oss;
}