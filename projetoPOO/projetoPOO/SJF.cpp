#include "sjf.hpp"

SJF::SJF() {

}


vector<Processo> merge(vector<Processo> processos, int inicio, int meio, int fim) {
    int i1, i2;
    int k = 0;

    float* temp = (float*)malloc((fim - inicio + 1) * sizeof(float));

    i1 = inicio;
    i2 = meio + 1;

    while (i1 <= meio && i2 <= fim) {
        if (processos[i1].getTempoProc() <= processos[i2].getTempoProc()) {
            temp[k++] = processos[i1++].getTempoProc();
        }
        else {
            temp[k++] = processos[i2++].getTempoProc();
        }
    }

    while (i1 <= meio) {
        temp[k++] = processos[i1++].getTempoProc();
    }

    while (i2 <= fim) {
        temp[k++] = processos[i2++].getTempoProc();
    }

    for (int i = inicio; i <= fim; i++) {
        processos[i].setTempoProc(temp[i - inicio]);
    }

    free(temp);
    return processos;
}

vector<Processo> mergeSort(vector<Processo> processos, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        processos = mergeSort(processos, inicio, meio);
        processos = mergeSort(processos, meio + 1, fim);

        processos = merge(processos, inicio, meio, fim);
    }
    return processos;
}

vector<Processo> SJF::ordenaVetor(vector<Processo> processos) {
    int tamanho = processos.size();

    vector<Processo> vetorOrdenado = mergeSort(processos, 0, tamanho - 1);

    return vetorOrdenado;
}

void SJF::calculaTempo(vector<Processo> processos) {
    vector<Processo> vetorOrdenado = ordenaVetor(processos);

    float tempoEsperaTotal = 0.0;
    float tempoProcTotal = 0.0;
    float tempoExecTotal = 0.0;

    int tamanho = vetorOrdenado.size();

    cout << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << " Processo " << i + 1 << " Tipo: " << vetorOrdenado[i].getTipo() << " Tempo: " << vetorOrdenado[i].getTempoProc() << " ms" << endl;
    }
    cout << endl;

    
    for (int i = 0; i < tamanho; i++) {
        if (i > 0) {
            tempoEsperaTotal += tempoProcTotal;
        }
        tempoProcTotal += vetorOrdenado[i].getTempoProc();

        cout << "Tempo de Espera: " << tempoEsperaTotal << " ms" << endl;
        cout << "Tempo de Processamento: " << tempoProcTotal << " ms" << endl;
    }
    tempoExecTotal = tempoEsperaTotal + tempoProcTotal;

    this->setTempoMedioExe(tempoExecTotal / tamanho);
    this->setTempoMedioEspera(tempoEsperaTotal / tamanho);

    cout << endl;
    //cout << "Tempo de Espera Medio: " << this->getTempoMedioEspera() << " ms" << endl;
    //cout << "Tempo de Execucao Medio: " << this->getTempoMedioExe() << " ms" << endl;
    //cout << endl;
}