#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include "Includes.hpp"

class Processo {
private:
    string tipo;
    int id;
    int dados;
    string texto;
    float tempoExe;
public:
    Processo();

    void setTipo(string tipo);
    void setId(int id);
    void setDados(int dados);
    void setTexto(string texto);
    void setTempoExe(float tempoExe);

    string getTipo();
    int getId();
    int getDado();
    string getTexto();
    float getTempoExe();
};


#endif