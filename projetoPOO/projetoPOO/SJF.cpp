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
        if (processos[i1].getTempoExe() <= processos[i2].getTempoExe()) {
            temp[k++] = processos[i1++].getTempoExe();
        }
        else {
            temp[k++] = processos[i2++].getTempoExe();
        }
    }

    while (i1 <= meio) {
        temp[k++] = processos[i1++].getTempoExe();
    }

    while (i2 <= fim) {
        temp[k++] = processos[i2++].getTempoExe();
    }

    for (int i = inicio; i <= fim; i++) {
        processos[i].setTempoExe(temp[i - inicio]);
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

    int tamanho = vetorOrdenado.size();
    for (int i = 0; i < tamanho; i++) {
        cout << vetorOrdenado[i].getTempoExe() << endl;
    }
}