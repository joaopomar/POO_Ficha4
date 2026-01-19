#include "Inventario.h"
#include "Equipamento.h"
#include <sstream>
using namespace std;


Inventario::Inventario() {
    equipamentosInventario = 0;
}

// 2. Construtor com lista
Inventario::Inventario(Equipamento arr[], int tamanho) {
    equipamentosInventario = 0;

    for (int i = 0; i < tamanho && i < 100; i++) {
        adicionaEquipamento(arr[i]);
    }
}

// 3. Adicionar (versão 1)
void Inventario::adicionaEquipamento(const string& nome, int preco) {
    if (equipamentosInventario >= 100) {
        return;
    }
    equipamentos[equipamentosInventario] = Equipamento(nome, preco);
    equipamentosInventario++;
}

void Inventario::adicionaEquipamento(const Equipamento& e) {
    if (equipamentosInventario >= 100) {
        return;
    }

    for(int i = 0; i < equipamentosInventario; i++){
        if (equipamentos[i].getID() == e.getID()) {
            return;
        }
    }
    equipamentos[equipamentosInventario] = e;
    equipamentosInventario++;
}

// 5. Remover
void Inventario::removeEquipamento(int id) {
    
    for (int i = 0; i < equipamentosInventario; i++) {
        if (equipamentos[i].getID() == id) {
            equipamentos[i] = equipamentos[equipamentosInventario - 1];
            equipamentosInventario--;
            return;
        }
    }
}

// 6. Representação textual
string Inventario::representacaoTextual() const {
    ostringstream oss;
    
    // percorrer só os equipamentos que existem (não os 100!)
    for (int i = 0; i < equipamentosInventario; i++) {
        oss << equipamentos[i].representacaoTextual() << "\n";  // chama o método de cada equipamento
    }
    
    return oss.str();
}

Inventario& Inventario::operator+=(const Equipamento& e) {
    adicionaEquipamento(e);  // reutiliza o método!
    return *this;  // retorna referência para o próprio objeto
}

Inventario& Inventario::operator-=(int id) {
    removeEquipamento(id);
    return *this;
}

Inventario& Inventario::operator<<(const Equipamento& e) {
    adicionaEquipamento(e);  // reutiliza o método!
    return *this;  // permite fazer: i << e1 << e2
}

Inventario::operator int() const {
    return equipamentosInventario;  // retorna a quantidade
}

























































































































































































































































