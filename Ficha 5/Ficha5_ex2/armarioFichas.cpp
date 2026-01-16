#include "armarioFichas.h"

armarioFichas::armarioFichas() {
	nrClientes = 0;
	clientes = nullptr; 
}


armarioFichas::~armarioFichas() {
	for (int i = 0; i < nrClientes; i++) {
		delete clientes[i];
	}
	delete[] clientes;
	clientes = nullptr;
}

armarioFichas::armarioFichas(const armarioFichas& outro) {


}