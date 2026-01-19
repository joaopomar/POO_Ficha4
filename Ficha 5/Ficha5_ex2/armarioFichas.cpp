#include "armarioFichas.h"

armarioFichas::armarioFichas() {
	nrClientes = 0;
	clientes = nullptr; 
}


armarioFichas::~armarioFichas() {
	for (int i = 0; i < nrClientes; i++) {
		delete clientes[i];
	}
	delete[] clientes;
	clientes = nullptr;
}

armarioFichas::armarioFichas(const armarioFichas& outro) {

	nrClientes = outro.nrClientes;
	if (nrClientes == 0) {
		clientes = nullptr;
		return;
	}
	clientes = new Cliente * [nrClientes];
	for (int i = 0; i < outro.nrClientes; i++) {
		clientes[i] = new Cliente(outro.clientes[i]->obtemNome(), outro.clientes[i]->obtemNIF());
	}
}

armarioFichas& armarioFichas::operator=(const armarioFichas& outro) {

    //verifica autoatribuicao
    if (this == &outro) {
        return *this;
    }
    
    // Liberta memória antiga
    for (int i = 0; i < nrClientes; i++) {
        delete clientes[i];
    }
    delete[] clientes;
    
    // Copia do outro
    nrClientes = outro.nrClientes;
    
    if (nrClientes == 0) {
        clientes = nullptr;
    } else {
        clientes = new Cliente*[nrClientes];
        for (int i = 0; i < nrClientes; i++) {
            clientes[i] = new Cliente(
                outro.clientes[i]->obtemNome(),
                outro.clientes[i]->obtemNIF()
            );
        }
    }
    
    return *this;
}

bool armarioFichas::adicionaCliente(string nome, int nif) {
    
    // 1. Verificar se JÁ EXISTE (loop completo primeiro)
    for (int i = 0; i < nrClientes; i++) {
        if (clientes[i]->obtemNIF() == nif) {
            return false;  // Já existe, sai da função!
        }
    }
    
    // 2. Se chegou aqui, NÃO existe! Pode adicionar
    
    // 3. Criar NOVO array (tamanho atual + 1)
    Cliente** novo = new Cliente*[nrClientes + 1];
    
    // 4. Copiar ponteiros ANTIGOS para o novo array
    for (int i = 0; i < nrClientes; i++) {
        novo[i] = clientes[i];  // Copia os ponteiros!
    }
    
    // 5. Adicionar NOVO cliente na última posição
    novo[nrClientes] = new Cliente(nome, nif);
    
    // 6. Libertar array antigo(só o array, não os clientes)
    delete[] clientes;
    
    // 7. Atualizar ponteiro
    clientes = novo;
    
    // 8. Incrementar contador
    nrClientes++;
    
    // 9. Sucesso!
    return true;
}


bool armarioFichas::apagaCliente(int nif) {
    
    // 1. Procurar o cliente
    int indice = -1;
    for (int i = 0; i < nrClientes; i++) {
        if (clientes[i]->obtemNIF() == nif) {
            indice = i;
            break;
        }
    }
    
    // 2. Se não encontrou
    if (indice == -1) {
        return false;
    }
    
    // 3. Apagar o objeto Cliente
    delete clientes[indice];
    
    // 4. Caso especial: era o último cliente?
    if (nrClientes == 1) {
        delete[] clientes;
        clientes = nullptr;
        nrClientes = 0;
        return true;
    }
    
    // 5. Criar novo array menor
    Cliente** novo = new Cliente*[nrClientes - 1];
    
    // 6. Copiar ponteiros (saltando o apagado)
    int pos = 0;
    for (int i = 0; i < nrClientes; i++) {
        if (i != indice) {  // Salta o índice apagado
            novo[pos] = clientes[i];
            pos++;
        }
    }
    
    // 7. Libertar array antigo
    delete[] clientes;
    
    // 8. Atualizar
    clientes = novo;
    nrClientes--;
    
    // 9. Sucesso!
    return true;
}

// 6. REGISTA CONSULTA
bool armarioFichas::registaConsulta(int nif) {
    for (int i = 0; i < nrClientes; i++) {
        if (clientes[i]->obtemNIF() == nif) {
            clientes[i]->novaConsulta();
            return true;
        }
    }
    return false;  // Cliente não encontrado
}


// 7. OBTEM INFO CLIENTE
armarioFichas::InfoCliente armarioFichas::obtemInfoCliente(int nif) const {
    for (int i = 0; i < nrClientes; i++) {
        if (clientes[i]->obtemNIF() == nif) {
            return InfoCliente(
                clientes[i]->obtemNome(),
                clientes[i]->obtemNumConsultas()
            );
        }
    }
    // Cliente não encontrado - retorna InfoCliente vazio
    return InfoCliente("", 0);
}


// 8. COPIA CONTEUDO DE
void armarioFichas::copiaConteudoDe(const armarioFichas& outro) {
    for (int i = 0; i < outro.nrClientes; i++) {
        // Adiciona se não existir (adicionaCliente já verifica duplicados)
        adicionaCliente(
            outro.clientes[i]->obtemNome(),
            outro.clientes[i]->obtemNIF()
        );
    }
}


// 9. OPERADOR == (comparação)
bool armarioFichas::operator==(const armarioFichas& outro) const {
    // Se têm tamanhos diferentes, não são iguais
    if (nrClientes != outro.nrClientes) {
        return false;
    }

    // Verifica se cada NIF deste armário existe no outro
    for (int i = 0; i < nrClientes; i++) {
        int nif = clientes[i]->obtemNIF();
        bool encontrou = false;

        for (int j = 0; j < outro.nrClientes; j++) {
            if (outro.clientes[j]->obtemNIF() == nif) {
                encontrou = true;
                break;
            }
        }

        if (!encontrou) {
            return false;  // NIF não existe no outro
        }
    }

    return true;  // Todos os NIFs existem em ambos
}


// 10. ESVAZIA
void armarioFichas::esvazia() {
    // Apaga cada cliente
    for (int i = 0; i < nrClientes; i++) {
        delete clientes[i];
    }

    // Apaga o array
    delete[] clientes;

    // Reset
    clientes = nullptr;
    nrClientes = 0;
}


// 11. OBTEM LISTAGEM
string armarioFichas::obtemListagem() const {
    if (nrClientes == 0) {
        return "";  // Armário vazio
    }

    string resultado = "";
    for (int i = 0; i < nrClientes; i++) {
        resultado += clientes[i]->obtemDesc();
        if (i < nrClientes - 1) {  // Não adiciona \n no último
            resultado += "\n";
        }
    }

    return resultado;
}


// ============================================
// IMPLEMENTAÇÃO DA CLASSE CLIENTE (nested)
// ============================================

armarioFichas::Cliente::Cliente(string _nome, int _nif)
    : nome(_nome), nif(_nif), numConsultas(0) {
}

string armarioFichas::Cliente::obtemNome() const {
    return nome;
}

int armarioFichas::Cliente::obtemNIF() const {
    return nif;
}

int armarioFichas::Cliente::obtemNumConsultas() const {
    return numConsultas;
}

void armarioFichas::Cliente::novaConsulta() {
    numConsultas++;
}

string armarioFichas::Cliente::obtemDesc() const {
    return nome + " / " + to_string(nif) + " / " + to_string(numConsultas);
}


// ============================================
// IMPLEMENTAÇÃO DA CLASSE INFOCLIENTE (nested)
// ============================================

armarioFichas::InfoCliente::InfoCliente(string _nome, int _numConsultas)
    : nome(_nome), numConsultas(_numConsultas) {
}

string armarioFichas::InfoCliente::obtemNome() const {
    return nome;
}

int armarioFichas::InfoCliente::obtemNumConsultas() const {
    return numConsultas;
}