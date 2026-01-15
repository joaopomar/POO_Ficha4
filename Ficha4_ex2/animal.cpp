#include "animal.h"
#include <sstream>
#include <string>

int animal::nrAnimais = 0;  

animal::animal(string especie, string nome, string dataNascimento, float peso) {
	float pesoFinal = peso;
	if (peso <= 0) {
		pesoFinal = 5.0f;
	}

	//Inicializacao 
	this->nome = nome;
	this->dataNascimento = dataNascimento;
	this->peso = pesoFinal;

	//gerar codigo 
	nrAnimais++;
	ostringstream oss;
	oss << 1000 + nrAnimais << "-" << especie;
	this->codigo = oss.str();

}

string animal::getDescricao() const {
    ostringstream oss;
    oss << "Codigo: " << codigo 
        << " | Nome: " << nome
        << " | Peso: " << peso << "kg"
        << " | Data Nasc: " << dataNascimento;
    return oss.str();
}