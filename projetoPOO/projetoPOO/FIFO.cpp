#include "FIFO.hpp"

FIFO::FIFO() {
	//CONSTRUTOR PADRÃO
}

vector<Processo> FIFO::ordenaVetor(vector<Processo> processos) {
    return processos;
}

void FIFO::calculaTempo(vector<Processo> processos) {
    float tempoEsperaTotal = 0.0f;
    float tempoExecTotal = 0.0f;
    float tempoTotal = 0.0f;
    float tempoMedio = 0.0f;
    float tempoMedioEspera = 0.0f;

    int tamanho = processos.size();
    for (int i = 0; i < tamanho; i++) {
        cout << processos[i].getTempoExe() << endl;
    }

    cout << endl;

    for (int i = 0; i < tamanho; i++) {
        if (i > 0) {
            tempoEsperaTotal += tempoExecTotal;
        }
        tempoExecTotal += processos[i].getTempoExe();

        cout << "Tempo de Espera: " << tempoEsperaTotal << endl;
        cout << "Tempo de Execucao: " << tempoExecTotal << endl;
    }

    tempoTotal = tempoEsperaTotal + tempoExecTotal;
    tempoMedio = tempoTotal / tamanho;
    tempoMedioEspera = tempoEsperaTotal / tamanho;

    cout << "Tempo total: " << tempoTotal << endl;
    cout << "Tempo medio de espera : " << tempoMedioEspera << endl;
}