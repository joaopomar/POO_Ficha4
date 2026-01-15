
#ifndef IMOVEIS_H
#define IMOVEIS_H

#include <string>

using namespace std;

class imoveis {

    string codigo;
    float area;
    float preco;
    string tipo;

    static int totalImoveis;

public:
    imoveis(string tipo, float area, float precoBase);
    virtual ~imoveis() {}

    // Métodos Virtuais
    virtual string getDescricao() const;
    virtual void aumentaPreco() = 0;

    // GETTERS (Para ler)
    string getCodigo() const { return codigo; }
    float getPreco() const { return preco; }
    float getArea() const { return area; }
    string getTipo() const { return tipo; }
    virtual int getAndar() const {return 0;}
    // SETTERS (Para escrever)
    // Precisamos deste porque o preço vai mudar nas classes filhas
    void setPreco(float novoPreco) { preco = novoPreco; }

};

#endif


