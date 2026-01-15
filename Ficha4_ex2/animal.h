#pragma once
#include <string>
using namespace std;


class animal
{
	string codigo;
	string nome;
	string dataNascimento;
	float peso;

	static int nrAnimais;

public:

	animal(string especie, string nome, string dataNascimento, float peso);
	virtual ~animal() {}

	virtual string comer() = 0;
	virtual string getDescricao() const;
	virtual string exercitar() = 0;


	string getCodigo() const { return codigo; }
	string getNome() const { return nome; }
	float getPeso() const { return peso; }
	string getDataNascimento() const { return dataNascimento; }

	float setPeso(float novoPeso) { peso = novoPeso; return peso; };

};