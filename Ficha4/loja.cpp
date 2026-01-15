#include "loja.h"
#include <sstream>
using namespace std;

loja::loja(float area) : imoveis("loja", area, 15.0f) {}

void loja::aumentaPreco() {
    float precoAtual = getPreco();
    float novoPreco = precoAtual * 1.01f;
    setPreco(novoPreco);
}

string loja::getDescricao() const {
    string descricaoBase = imoveis::getDescricao();
    ostringstream oss;
    oss << descricaoBase << " | Tipo: Loja (Res-do-chao)";
    return oss.str();
}
