#pragma once
#include "Equipamento.h"
#include <initializer_list>
using namespace std;
class Inventario
{

	Equipamento equipamentos[100];  
	int equipamentosInventario;

public:
	Inventario();
	Inventario(Equipamento arr[], int tamanho); 

	void adicionaEquipamento(const string& nome, int preco);
	void adicionaEquipamento(const Equipamento& e);
	void removeEquipamento(int id);
	string representacaoTextual() const;


	Inventario& operator+=(const Equipamento& e);
	Inventario& operator-=(int id);
	Inventario& operator<<(const Equipamento& e);
	operator int() const;
};

