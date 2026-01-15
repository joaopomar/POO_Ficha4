#pragma once
#include "animal.h"

class cao : public animal
{

public: 
	cao(string nome, float peso, string dataNascimento);


	string comer() override;
	string exercitar() override;

	string getDescricao() const override;



	

};

