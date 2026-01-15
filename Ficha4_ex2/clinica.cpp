#include "clinica.h"
#include <sstream>
#include <iostream>

clinica::clinica() : totalAnimais(0) {

	for (int i = 0; i < 200; i++) {
		listaAnimais[i] = nullptr;
	}
}


void clinica::registarAnimal(animal* a) {

	if (a == nullptr) {
		return;
	}

	for (int i = 0; i < totalAnimais; i++) {
		if (listaAnimais[i]->getCodigo() == a->getCodigo()) {
			return;
		}
	}
		if (totalAnimais < 200) {
			listaAnimais[totalAnimais] = a;
			totalAnimais++;
		}
	}

void clinica::removerAnimal(string codigo) {

	for (int i = 0; i < totalAnimais; i++) {
		if (listaAnimais[i]->getCodigo() == codigo) {
			for (int j = i; j < totalAnimais - 1; j++) { // move tudo para tras
				listaAnimais[j] = listaAnimais[j + 1];
			}
			listaAnimais[totalAnimais - 1] = nullptr;
			totalAnimais--;
			return;
		}
	}
}


const animal* clinica::getAnimal(string codigo) const {
    for (int i = 0; i < totalAnimais; i++) {
        if (listaAnimais[i]->getCodigo() == codigo) {
            return listaAnimais[i];  
        }
    }
    return nullptr; 
}

string clinica::getDescricaoAnimal(string codigo) const {
	for (int i = 0; i < totalAnimais; i++) {
		if (listaAnimais[i]->getCodigo() == codigo) {
			return listaAnimais[i]->getDescricao();
		}
	}
		return ""; 
}

string clinica::getListaCompleta() const {


	ostringstream oss;
	for (int i = 0; i < totalAnimais; i++) {
		oss << listaAnimais[i]->getDescricao() << "\n";
	}
	return oss.str();

}


void clinica::alimentarTodos() {
	for (int i = 0; i < totalAnimais; i++) {
		cout << listaAnimais[i]->comer() << endl;
	}
}

void clinica::exercitarTodos() {
	for (int i = 0; i < totalAnimais; i++) {
		cout << listaAnimais[i]->exercitar() << endl;
	}
}
