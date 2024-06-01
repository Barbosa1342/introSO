#ifndef SJF_HPP
#define SJF_HPP

#include "escalonamento.hpp"
#include "processo.hpp"

class SJF : public Escalonamento {
private:

public:
    SJF();
    vector<Processo> ordenaVetor(vector<Processo> processos);
    void calculaTempo(vector<Processo> processos);
};

#endif