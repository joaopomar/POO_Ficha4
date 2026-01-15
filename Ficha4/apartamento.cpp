#include "apartamento.h"
#include "imoveis.h"
#include <sstream>

using namespace std;

apartamentos::apartamentos(float area, int andar, int nrAssoalhadas) : imoveis("apartamento", area, 10.0f) {
    this->andar = andar;
    this->nrAssoalhadas = nrAssoalhadas;

}


string apartamentos::getDescricao() const {
    string descricaoBase = imoveis::getDescricao();  
    ostringstream oss;
    oss << descricaoBase << " | Andar: " << andar << " | Assoalhadas: T" << nrAssoalhadas;
    return oss.str();
}

void apartamentos::aumentaPreco()  {

    float novoPreco = getPreco() * (1.0f + nrAssoalhadas / 100.0f);
    setPreco(novoPreco);


}