#ifndef ESCALONAMENTO_HPP
#define ESCALONAMENTO_HPP

#include "processo.hpp"
#include "includes.hpp"

class Escalonamento {
private:
    float tempoExe;
public:
    Escalonamento();
    virtual vector<Processo> ordenaVetor(vector<Processo> processos) = 0;
    virtual void calculaTempo(vector<Processo> processos) = 0;

    void setTempoExe(float tempoExe);
    float getTempoExe();
};

#endif