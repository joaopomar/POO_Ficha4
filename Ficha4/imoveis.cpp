#include "imoveis.h"
#include <sstream>

int imoveis::totalImoveis = 0;

imoveis::imoveis(string tipo, float area, float precoBase) {

	if (area <= 0) {
		area = 1.0f;
	}

	this->area = area;
	this->preco = precoBase * area;

	totalImoveis++;

	ostringstream oss;
	oss << tipo << totalImoveis;
	this->codigo = oss.str();
}


string imoveis::getDescricao() const {
    ostringstream oss;
    oss << "Codigo: " << codigo << " | Area: " << area << " | Preco: " << preco;
    return oss.str();
}

