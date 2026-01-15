#pragma once
#include "animal.h"
#include <string>
using namespace std;


class clinica
{

	animal* listaAnimais[200];
	int totalAnimais;

public:
	clinica();

    void registarAnimal(animal* a);
    void removerAnimal(string codigo);

    const animal* getAnimal(string codigo) const;
    
    string getDescricaoAnimal(string codigo) const;
    string getListaCompleta() const;
    
    void alimentarTodos();
    void exercitarTodos();

};

