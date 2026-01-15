#include "cao.h"
#include <sstream>
#include <cstdlib>

cao::cao(string nome, float peso, string dataNascimento) : animal("Cao", nome, dataNascimento, peso) {
}

string cao::comer() {

	ostringstream oss;
	float pesoAtual = getPeso();
	float novoPeso = pesoAtual * 1.05;
	if (novoPeso > 20) { novoPeso = 20; }
	setPeso(novoPeso);

	oss << "biscoitos bons. obrigado";
	return oss.str();
	
}


string cao::exercitar() {

	ostringstream oss;
	int km = rand() % 5 + 1;

	oss << "corri " << km << " quilometros";
	return oss.str();

}

string cao::getDescricao() const {
    ostringstream oss;
    oss << animal::getDescricao() << " | Tipo: Cao";
    return oss.str();
}