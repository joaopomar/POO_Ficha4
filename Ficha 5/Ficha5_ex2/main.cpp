#include <iostream>
#include "armarioFichas.h"
using namespace std;

int main() {

    cout << "=== TESTE DA CLASSE armarioFichas ===" << endl << endl;

    // 1. TESTE: Criar armário vazio
    cout << "1. Criar armario vazio:" << endl;
    armarioFichas armario1;
    cout << "   Listagem (vazio): \"" << armario1.obtemListagem() << "\"" << endl << endl;

    // 2. TESTE: Adicionar clientes
    cout << "2. Adicionar clientes:" << endl;
    cout << "   Adicionar Joao (123456789): " << (armario1.adicionaCliente("Joao", 123456789) ? "OK" : "FALHOU") << endl;
    cout << "   Adicionar Maria (987654321): " << (armario1.adicionaCliente("Maria", 987654321) ? "OK" : "FALHOU") << endl;
    cout << "   Adicionar Ana (555555555): " << (armario1.adicionaCliente("Ana", 555555555) ? "OK" : "FALHOU") << endl;
    cout << "   Adicionar Joao novamente (123456789): " << (armario1.adicionaCliente("Joao", 123456789) ? "OK" : "FALHOU (esperado)") << endl;
    cout << endl;

    // 3. TESTE: Listagem
    cout << "3. Listagem de clientes:" << endl;
    cout << armario1.obtemListagem() << endl << endl;

    // 4. TESTE: Registar consultas
    cout << "4. Registar consultas:" << endl;
    cout << "   Consulta para Joao (123456789): " << (armario1.registaConsulta(123456789) ? "OK" : "FALHOU") << endl;
    cout << "   Consulta para Joao (123456789): " << (armario1.registaConsulta(123456789) ? "OK" : "FALHOU") << endl;
    cout << "   Consulta para Maria (987654321): " << (armario1.registaConsulta(987654321) ? "OK" : "FALHOU") << endl;
    cout << "   Consulta para NIF inexistente (111111111): " << (armario1.registaConsulta(111111111) ? "OK" : "FALHOU (esperado)") << endl;
    cout << endl;

    // 5. TESTE: Listagem após consultas
    cout << "5. Listagem apos consultas:" << endl;
    cout << armario1.obtemListagem() << endl << endl;

    // 6. TESTE: Obter info de cliente
    cout << "6. Obter info de cliente:" << endl;
    armarioFichas::InfoCliente info1 = armario1.obtemInfoCliente(123456789);
    cout << "   Info de Joao: " << info1.obtemNome() << " - " << info1.obtemNumConsultas() << " consultas" << endl;
    armarioFichas::InfoCliente info2 = armario1.obtemInfoCliente(555555555);
    cout << "   Info de Ana: " << info2.obtemNome() << " - " << info2.obtemNumConsultas() << " consultas" << endl;
    cout << endl;

    // 7. TESTE: Apagar cliente
    cout << "7. Apagar clientes:" << endl;
    cout << "   Apagar Maria (987654321): " << (armario1.apagaCliente(987654321) ? "OK" : "FALHOU") << endl;
    cout << "   Apagar NIF inexistente (111111111): " << (armario1.apagaCliente(111111111) ? "OK" : "FALHOU (esperado)") << endl;
    cout << "   Listagem apos apagar:" << endl;
    cout << armario1.obtemListagem() << endl << endl;

    // 8. TESTE: Construtor por cópia
    cout << "8. Construtor por copia:" << endl;
    armarioFichas armario2(armario1);
    cout << "   armario2 (copia de armario1):" << endl;
    cout << armario2.obtemListagem() << endl;
    cout << "   Adicionar Pedro (777777777) ao armario2:" << endl;
    armario2.adicionaCliente("Pedro", 777777777);
    cout << "   armario1 (original - nao deve ter Pedro):" << endl;
    cout << armario1.obtemListagem() << endl;
    cout << "   armario2 (copia - deve ter Pedro):" << endl;
    cout << armario2.obtemListagem() << endl << endl;

    // 9. TESTE: Operador de atribuição
    cout << "9. Operador de atribuicao:" << endl;
    armarioFichas armario3;
    armario3.adicionaCliente("Carlos", 888888888);
    cout << "   armario3 antes de atribuicao:" << endl;
    cout << armario3.obtemListagem() << endl;
    armario3 = armario1;
    cout << "   armario3 apos atribuicao (armario3 = armario1):" << endl;
    cout << armario3.obtemListagem() << endl << endl;

    // 10. TESTE: copiaConteudoDe
    cout << "10. copiaConteudoDe:" << endl;
    armarioFichas armario4;
    armario4.adicionaCliente("Luis", 999999999);
    cout << "   armario4 antes de copiar:" << endl;
    cout << armario4.obtemListagem() << endl;
    armario4.copiaConteudoDe(armario1);
    cout << "   armario4 apos copiar de armario1 (sem duplicados):" << endl;
    cout << armario4.obtemListagem() << endl << endl;

    // 11. TESTE: Operador ==
    cout << "11. Operador == (comparacao):" << endl;
    armarioFichas armario5;
    armario5.adicionaCliente("Joao", 123456789);
    armario5.adicionaCliente("Ana", 555555555);
    cout << "   armario1 == armario5: " << (armario1 == armario5 ? "Iguais" : "Diferentes") << endl;
    armario5.adicionaCliente("Pedro", 777777777);
    cout << "   armario1 == armario5 (apos adicionar Pedro): " << (armario1 == armario5 ? "Iguais" : "Diferentes (esperado)") << endl;
    cout << endl;

    // 12. TESTE: esvazia
    cout << "12. Esvaziar armario:" << endl;
    cout << "   armario5 antes de esvaziar:" << endl;
    cout << armario5.obtemListagem() << endl;
    armario5.esvazia();
    cout << "   armario5 apos esvaziar: \"" << armario5.obtemListagem() << "\"" << endl;
    cout << endl;

    cout << "=== TODOS OS TESTES CONCLUIDOS ===" << endl;

    return 0;
}