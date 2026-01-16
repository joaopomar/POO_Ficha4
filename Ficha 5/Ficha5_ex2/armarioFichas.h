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


    armarioFichas(); //contrutor
    ~armarioFichas(); //destrutor
    armarioFichas(const armarioFichas& outro);


    }
    
};

