#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H

#include "imoveis.h"
#include <string>

using namespace std;
class imobiliaria {


	imoveis* listaImoveis[100];
	int totalImoveis;

public:

	imobiliaria();
	void adicionaImovel(imoveis* c);
	void getImovel(string codigo) const;
	
	string getListagemAndar(int andar) const;
	string getListaImoveis() const;

	void aumentaPrecos() const;
};

#endif


