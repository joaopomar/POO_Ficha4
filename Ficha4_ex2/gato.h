#pragma once
#include "animal.h"

class gato : public animal
{

public:
	gato(string nome, float peso, string dataNascimento);


	string comer() override;
	string exercitar() override;

	string getDescricao() const override;





};

