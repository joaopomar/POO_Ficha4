#pragma once
#include <string>
using namespace std;

class armarioFichas
{

private:
    class Cliente {
        string nome;
        int nif;
        int numConsultas;
    public:
        Cliente(string _nome, int _nif);
        string obtemNome() const;
        int obtemNIF() const;
        int obtemNumConsultas() const;
        void novaConsulta();
        string obtemDesc() const;
    };

    int nrClientes;
    Cliente** clientes;

public:
    class InfoCliente {
        string nome;
        int numConsultas;
    public:
        InfoCliente(string _nome, int _numConsultas);
        string obtemNome() const;
        int obtemNumConsultas() const;
    };

    armarioFichas();
    ~armarioFichas();
    armarioFichas(const armarioFichas& outro);
    armarioFichas& operator=(const armarioFichas& outro);

    bool adicionaCliente(string nome, int nif);
    bool apagaCliente(int nif);
    bool registaConsulta(int nif);
    InfoCliente obtemInfoCliente(int nif) const;
    void copiaConteudoDe(const armarioFichas& outro);
    bool operator==(const armarioFichas& outro) const;
    void esvazia();
    string obtemListagem() const;

};  // ← SÓ ESTA CHAVE! Remove a outra!