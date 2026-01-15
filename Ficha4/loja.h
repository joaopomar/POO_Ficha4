#ifndef LOJA_H
#define LOJA_H

#include "imoveis.h"

class loja : public imoveis {
public:

    loja(float area);

    std::string getDescricao() const override;
    void aumentaPreco() override;
};

#endif


