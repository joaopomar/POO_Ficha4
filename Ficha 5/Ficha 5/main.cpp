#include "MyString.h"
#include <iostream>
using namespace std;

int main() {

    cout << "=== Teste da Classe MyString ===" << endl << endl;

    // Teste do construtor padrão
    cout << "1. Construtor Padrao:" << endl;
    MyString s1;
    cout << "   s1: \"" << s1.obtemCString() << "\"" << endl << endl;

    // Teste do construtor com parâmetros
    cout << "2. Construtor com Parametros:" << endl;
    MyString s2("Ola Mundo");
    cout << "   s2: \"" << s2.obtemCString() << "\"" << endl << endl;

    // Teste do construtor por cópia
    cout << "3. Construtor por Copia:" << endl;
    MyString s3(s2);
    cout << "   s3 (copia de s2): \"" << s3.obtemCString() << "\"" << endl << endl;

    // Teste do operador de atribuição
    cout << "4. Operador de Atribuicao:" << endl;
    MyString s4;
    s4 = s2;
    cout << "   s4 = s2: \"" << s4.obtemCString() << "\"" << endl << endl;

    // Teste do método acrescenta
    cout << "5. Metodo acrescenta():" << endl;
    MyString s5("Programacao");
    cout << "   Antes: \"" << s5.obtemCString() << "\"" << endl;
    s5.acrescenta(" Orientada");
    cout << "   Acrescentou ' Orientada': \"" << s5.obtemCString() << "\"" << endl;
    s5.acrescenta(" a Objetos");
    cout << "   Acrescentou ' a Objetos': \"" << s5.obtemCString() << "\"" << endl << endl;

    // Teste do método mudaCharAt
    cout << "6. Metodo mudaCharAt():" << endl;
    MyString s6("Hello");
    cout << "   Antes: \"" << s6.obtemCString() << "\"" << endl;
    if (s6.mudaCharAt(0, 'h')) {
        cout << "   Mudou indice 0 para 'h': \"" << s6.obtemCString() << "\"" << endl;
    }
    if (!s6.mudaCharAt(10, 'X')) {
        cout << "   Tentativa de mudar indice 10 (invalido): Falhou corretamente" << endl;
    }
    cout << endl;

    // Teste do método removeDeAte
    cout << "7. Metodo removeDeAte():" << endl;
    MyString s7("Programacao");
    cout << "   Antes: \"" << s7.obtemCString() << "\"" << endl;
    if (s7.removeDeAte(0, 2)) {
        cout << "   Removeu de 0 a 2: \"" << s7.obtemCString() << "\"" << endl;
    }
    MyString s8("0123456789");
    cout << "   Antes: \"" << s8.obtemCString() << "\"" << endl;
    if (s8.removeDeAte(3, 6)) {
        cout << "   Removeu de 3 a 6: \"" << s8.obtemCString() << "\"" << endl;
    }
    if (!s8.removeDeAte(10, 20)) {
        cout << "   Tentativa de remover indices invalidos: Falhou corretamente" << endl;
    }
    cout << endl;

    // Teste de auto-atribuição
    cout << "8. Auto-atribuicao:" << endl;
    MyString s9("Teste");
    s9 = s9;
    cout << "   s9 = s9: \"" << s9.obtemCString() << "\"" << endl << endl;

    cout << "=== Todos os testes concluidos ===" << endl;

    return 0;
}