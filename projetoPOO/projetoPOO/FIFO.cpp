#include "FIFO.hpp"

FIFO::FIFO() {
	//CONSTRUTOR PADRÃO
}

vector<Processo> FIFO::ordenaVetor(vector<Processo> processos) {
    return processos;
}

void FIFO::calculaTempo(vector<Processo> processos) {
    float tempoEsperaTotal = 0.0f;
    float tempoProcTotal = 0.0f;
    float tempoExecTotal = 0.0f;

    int tamanho = processos.size();

    cout << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << " Processo " << i + 1 << " Tipo: " << processos[i].getTipo() << " Tempo: " << processos[i].getTempoProc() << " ms" << endl;
    }
    cout << endl;

    for (int i = 0; i < tamanho; i++) {
        if (i > 0) {
            tempoEsperaTotal += tempoProcTotal;
        }
        tempoProcTotal += processos[i].getTempoProc();

        cout << "Tempo de Espera: " << tempoEsperaTotal << " ms" << endl;
        cout << "Tempo de Execucao: " << tempoProcTotal << " ms" << endl;
    }

    tempoExecTotal = tempoEsperaTotal + tempoProcTotal;

    this->setTempoMedioExe(tempoExecTotal / tamanho);
    this->setTempoMedioEspera(tempoEsperaTotal / tamanho);

    cout << endl;
    //cout << "Tempo de Espera Medio: " << this->getTempoMedioEspera() << " ms" << endl;
    //cout << "Tempo de Execucao Medio: " << this->getTempoMedioExe() << " ms" << endl;
    //cout << endl;
}