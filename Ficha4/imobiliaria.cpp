#include "imobiliaria.h"
#include <sstream>
#include <iostream> 

imobiliaria::imobiliaria() : totalImoveis(0) {
	
	for (int i = 0; i < 100; i++)  {
		listaImoveis[i] = nullptr;
	}
}

void imobiliaria::adicionaImovel(imoveis* c) {

	
		if (c == nullptr) {
			return;
		}

		for (int i = 0; i < totalImoveis; i++) {

			if ((listaImoveis[i]->getCodigo()) == (c->getCodigo())) {
				return;
			}
		}

		if (totalImoveis < 100) {
			listaImoveis[totalImoveis] = c;
			totalImoveis++;

		}
	}

void imobiliaria::getImovel(string codigo) const {
	for (int i = 0; i < totalImoveis; i++) {
		if (listaImoveis[i]->getCodigo() == codigo) {
			listaImoveis[i]->getDescricao(); 
			cout << listaImoveis[i]->getDescricao();
		}

	}
}

string imobiliaria::getListaImoveis() const {

	ostringstream oss;
	for (int i = 0; i < totalImoveis; i++) {
		oss << listaImoveis[i]->getDescricao() << "\n";
	}
	return oss.str();

}

string imobiliaria::getListagemAndar(int andar) const {
    ostringstream oss;
    
    for (int i = 0; i < totalImoveis; i++) {
        if (listaImoveis[i]->getAndar() == andar) {
            oss << listaImoveis[i]->getDescricao() << "\n";
        }
    }
    
    return oss.str();
}

void imobiliaria::aumentaPrecos() const {
	for (int i = 0; i < totalImoveis; i++) {
		listaImoveis[i]->aumentaPreco();  
	}
}