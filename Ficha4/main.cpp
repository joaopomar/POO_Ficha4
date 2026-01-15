#include <iostream>
#include "imobiliaria.h"
#include "loja.h"
#include "apartamento.h"

using namespace std;

int main() {

    // 1. CRIAR IMOBILIÁRIA
    imobiliaria minhaImobiliaria;
    
    cout << "=== SISTEMA DE GESTAO DE IMOVEIS ===" << endl << endl;

    // 2. CRIAR ALGUNS IMÓVEIS (lojas e apartamentos)
    loja* l1 = new loja(50.0f);
    loja* l2 = new loja(75.0f);
    loja* l3 = new loja(100.0f);
    
    apartamentos* a1 = new apartamentos(80.0f, 2, 2);  // T2 no 2º andar
    apartamentos* a2 = new apartamentos(120.0f, 3, 3); // T3 no 3º andar
    apartamentos* a3 = new apartamentos(90.0f, 2, 1);  // T1 no 2º andar

    // 3. ADICIONAR À IMOBILIÁRIA
    cout << "--- Adicionando imoveis ---" << endl;
    minhaImobiliaria.adicionaImovel(l1);
    minhaImobiliaria.adicionaImovel(l2);
    minhaImobiliaria.adicionaImovel(l3);
    minhaImobiliaria.adicionaImovel(a1);
    minhaImobiliaria.adicionaImovel(a2);
    minhaImobiliaria.adicionaImovel(a3);
    cout << "Imoveis adicionados com sucesso!" << endl << endl;

    // 4. TESTAR getListaImoveis()
    cout << "=== LISTA DE TODOS OS IMOVEIS ===" << endl;
    cout << minhaImobiliaria.getListaImoveis() << endl;

    // 5. TESTAR getListagemAndar()
    cout << "=== APARTAMENTOS NO 2º ANDAR ===" << endl;
    cout << minhaImobiliaria.getListagemAndar(2) << endl;

    // 6. TESTAR getImovel()
    cout << "=== PROCURAR IMOVEL ESPECIFICO (loja1) ===" << endl;
    minhaImobiliaria.getImovel("loja1");
    cout << endl << endl;

    // 7. TESTAR aumentaPrecos()
    cout << "=== AUMENTANDO TODOS OS PRECOS ===" << endl;
    minhaImobiliaria.aumentaPrecos();
    cout << "Precos aumentados!" << endl << endl;
    
    cout << "=== LISTA APOS AUMENTO ===" << endl;
    cout << minhaImobiliaria.getListaImoveis() << endl;

    // 8. LIMPAR MEMÓRIA
    delete l1;
    delete l2;
    delete l3;
    delete a1;
    delete a2;
    delete a3;
    
    cout << "Memoria libertada. Programa terminado." << endl;

    return 0;
}