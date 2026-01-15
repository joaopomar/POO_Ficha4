#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "imoveis.h"

class apartamentos : public imoveis {
  int andar, nrAssoalhadas;


public:

    apartamentos(float area, int andar, int nrAssoalhadas);

    int getAndar() const { return andar; };

    string getDescricao() const override;
    void aumentaPreco() override;
};

#endif





