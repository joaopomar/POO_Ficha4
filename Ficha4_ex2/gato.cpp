#include "gato.h"
#include <sstream>
#include <cstdlib>

gato::gato(string nome, float peso, string dataNascimento) : animal("gato", nome, dataNascimento, peso) {
}

string gato::comer() {

	ostringstream oss;
	oss << "o quê, este patê reles novamente?";
	return oss.str();

}


string gato::exercitar() {

	ostringstream oss;
	int jarras = rand() % 4;
	int pessoas = rand() % 5;
	oss << "derrubei " << jarras << " jarras e arranhei " << pessoas << " pessoas";

	float pesoAtual = getPeso();
	float novoPeso = pesoAtual * 0.9;
	if (novoPeso < 2.5) { novoPeso = 2.5; }
	setPeso(novoPeso);
	return oss.str();

}

string gato::getDescricao() const {
    ostringstream oss;
    oss << animal::getDescricao() << " | Tipo: Gato";
    return oss.str();
}