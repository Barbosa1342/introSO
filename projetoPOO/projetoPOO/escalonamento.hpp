#ifndef ESCALONAMENTO_HPP
#define ESCALONAMENTO_HPP

#include "processo.hpp"
#include "includes.hpp"

class Escalonamento {
private:
    float tempoMedioExe;
    float tempoMedioEspera;
public:
    Escalonamento();
    virtual vector<Processo> ordenaVetor(vector<Processo> processos) = 0;
    virtual void calculaTempo(vector<Processo> processos) = 0;

    void setTempoMedioExe(float tempoMedioExe);
    float getTempoMedioExe();

    void setTempoMedioEspera(float tempoMedioEspera);
    float getTempoMedioEspera();
};

#endif