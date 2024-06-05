#include "FIFO.hpp"

FIFO::FIFO() {
	//CONSTRUTOR PADRÃO
}

void FIFO::calculaTempo(vector<Processo> processos) {
    
    float tempoEsperaTotal = 0;
    float tempoExecTotal = 0;
    float tempoTotal = 0;
    float tempoMedio = 0;
    float tempoMedioEspera = 0;

    int percorreV = processos.size();
    for (int i = 0; i < percorreV; i++) {
        cout << processos[i].getTempoExe() << endl;
    }

    cout << endl;

    for (int i = 0; i < percorreV; i++) {

        if (i != 0) {

            tempoEsperaTotal += tempoExecTotal;

            tempoExecTotal += processos[i].getTempoExe();
        }

        else if (i == 0) {
            tempoEsperaTotal += 0;
            tempoExecTotal += processos[i].getTempoExe();
        }

        cout << "Tempo de Espera: " << tempoEsperaTotal << endl;
        cout << "Tempo de Execucao: " << tempoExecTotal << endl;
    }

    tempoTotal = tempoEsperaTotal + tempoExecTotal;
    tempoMedio = tempoTotal / percorreV;
    tempoMedioEspera = tempoEsperaTotal / percorreV;

    cout << "Tempo total: " << tempoTotal << endl;
    cout << "Tempo medio de espera : " << tempoMedioEspera << endl;
}