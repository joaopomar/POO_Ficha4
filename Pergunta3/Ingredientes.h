#pragma once
#include <string>
using namespace std;

class Ingredientes
{
	int valor;
	string nome;


public:

	Ingredientes();
	Ingredientes(const string& nome, int valor);

	string getNome() const { return nome; }
	int getValor() const { return valor; }
};

