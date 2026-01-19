#pragma once
#include <string>
#include <iostream>

using namespace std;

class Equipamento
{

	string nome;
	int preco;
	int id;
	static int proxID;


public:
	Equipamento();
	Equipamento(const string& nome, int preco) ;



	string getNome() const{	return nome;}
	int getID() const { return id; }
	int getPreco() const{ return preco; }
	string representacaoTextual() const;
	
	// Operadores da 1.b:
	friend ostream& operator<<(ostream& oss, const Equipamento& e);

};

