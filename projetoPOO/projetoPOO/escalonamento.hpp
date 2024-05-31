#ifndef ESCALONAMENTO.HPP
#define ESCALONAMENTO.HPP

#include "processo.hpp"
#include "includes.hpp"

class Escalonamento {
private:
    float tempoExe;
public:
    Escalonamento();
    virtual void ordenaVetor(vector<Processo> processos) = 0;
    virtual void calculaTempo(vector<Processo> processos) = 0;

    void setTempoExe(float tempoExe);
    float getTempoExe();
};

#endif