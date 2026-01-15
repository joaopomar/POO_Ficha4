#include <iostream>
#include "clinica.h"
#include "cao.h"
#include "gato.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // Inicializar gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    cout << "=== SISTEMA DE GESTAO DA CLINICA VETERINARIA ===" << endl << endl;

    // 1. CRIAR CLINICA
    clinica minhaClinica;

    // 2. CRIAR ALGUNS ANIMAIS
    cout << "--- Criando animais ---" << endl;
    cao* c1 = new cao("Rex", 15.0f, "01-01-2020");
    cao* c2 = new cao("Bobby", 8.5f, "15-06-2021");
    cao* c3 = new cao("Max", 12.0f, "10-03-2019");

    gato* g1 = new gato("Mimi", 4.0f, "20-04-2022");
    gato* g2 = new gato("Felix", 5.5f, "05-09-2021");
    gato* g3 = new gato("Luna", 3.2f, "12-12-2023");

    cout << "Animais criados com sucesso!" << endl << endl;

    // 3. REGISTAR NA CLINICA
    cout << "--- Registrando animais na clinica ---" << endl;
    minhaClinica.registarAnimal(c1);
    minhaClinica.registarAnimal(c2);
    minhaClinica.registarAnimal(c3);
    minhaClinica.registarAnimal(g1);
    minhaClinica.registarAnimal(g2);
    minhaClinica.registarAnimal(g3);
    cout << "Animais registrados!" << endl << endl;

    // 4. LISTAR TODOS
    cout << "=== LISTA COMPLETA DE ANIMAIS ===" << endl;
    cout << minhaClinica.getListaCompleta() << endl;

    // 5. TESTAR getDescricaoAnimal por codigo
    cout << "=== PROCURAR ANIMAL ESPECIFICO (1001-Cao) ===" << endl;
    cout << minhaClinica.getDescricaoAnimal("1001-Cao") << endl << endl;

    // 6. TESTAR getAnimal (ponteiro so leitura)
    cout << "=== OBTER ANIMAL (1004-Gato) ===" << endl;
    const animal* a = minhaClinica.getAnimal("1004-Gato");
    if (a != nullptr) {
        cout << "Encontrado: " << a->getNome() << " com peso " << a->getPeso() << "kg" << endl << endl;
    }

    // 7. ALIMENTAR TODOS
    cout << "=== ALIMENTANDO TODOS OS ANIMAIS ===" << endl;
    minhaClinica.alimentarTodos();
    cout << endl;

    // 8. VER PESOS APOS ALIMENTACAO
    cout << "=== LISTA APOS ALIMENTACAO ===" << endl;
    cout << minhaClinica.getListaCompleta() << endl;

    // 9. EXERCITAR TODOS
    cout << "=== EXERCITANDO TODOS OS ANIMAIS ===" << endl;
    minhaClinica.exercitarTodos();
    cout << endl;

    // 10. VER PESOS APOS EXERCICIO
    cout << "=== LISTA APOS EXERCICIO ===" << endl;
    cout << minhaClinica.getListaCompleta() << endl;

    // 11. REMOVER UM ANIMAL
    cout << "=== REMOVENDO ANIMAL (1002-Cao - Bobby) ===" << endl;
    minhaClinica.removerAnimal("1002-Cao");
    cout << "Animal removido!" << endl << endl;

    // 12. LISTAR NOVAMENTE
    cout << "=== LISTA APOS REMOCAO ===" << endl;
    cout << minhaClinica.getListaCompleta() << endl;

    // 13. TESTAR ALIMENTAR E EXERCITAR NOVAMENTE
    cout << "=== SEGUNDA RODADA: ALIMENTAR ===" << endl;
    minhaClinica.alimentarTodos();
    cout << endl;

    cout << "=== SEGUNDA RODADA: EXERCITAR ===" << endl;
    minhaClinica.exercitarTodos();
    cout << endl;

    // 14. LIMPAR MEMORIA
    delete c1;
    delete c2;
    delete c3;
    delete g1;
    delete g2;
    delete g3;

    cout << "Memoria libertada. Programa terminado." << endl;

    return 0;
}