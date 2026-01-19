#include "Ingredientes.h"




Ingredientes::Ingredientes() : nome(), valor(0){}

Ingredientes::Ingredientes(const string& nome, int valor) {
	this->nome = nome;
	this->valor = valor;
}

