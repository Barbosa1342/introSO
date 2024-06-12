#include "gerenciador.hpp"

int randomInt(int min = 0, int max = 100) {
	// min e max inclusos

	// rand() % numero retorna de 0 a numero-1
	// a subtracao e posterior soma por min, e a soma por 1
	// fazem um deslocamento do resultado
	// de modo a incluir min e max
	int random = (rand() % (max - min + 1)) + min;

	return random;
}

string randomStr(int tamanho = 10) {
	const char alfanumericos[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	string temp;

	// conjunto dividido por elemento, retorna o numero de elementos
	int tam = sizeof(alfanumericos) / sizeof(alfanumericos[0]);

	// seleciona um caractere aleatorio do array de caracteres
	// e concatena em uma string
	for (int i = 0; i < tamanho; i++) {
		temp += alfanumericos[randomInt(0, tam-1)];
	}

	return temp;
}

Gerenciador::Gerenciador() {

}

void Gerenciador::geraProcessos(int numProcessos) {
	this->processos.clear();

	if (numProcessos == 0) {
		// numero aleatorio de processos a serem gerados
		numProcessos = randomInt(5, 15);
	}

	for (int i = 0; i < numProcessos; i++) {
		// definimos um tipo aleatoriamente
		int tipo = randomInt(1, 5);

		// Inicializamos um ponteiro para um
		// objeto do tipo Processo
		Processo* temp = NULL;

		// Por trabalharmos com herança conseguimos instanciar
		// um ponteiro de processo e converter para um ponteiro de classe derivada
		if (tipo == 1) {
			temp = new Interativa;
		}
		else if (tipo == 2) {
			temp = new IO;
		}
		else if (tipo == 3) {
			temp = new Lote;
		}
		else if (tipo == 4) {
			temp = new Processamento;
		}
		else if (tipo == 5) {
			temp = new TempoReal;
		}

		// definição dos dados de modo aleatorio
		temp->setDados(randomInt());
		temp->setId(i);
		temp->setTexto(randomStr(randomInt(5, 10)));
		calculaTempoProc(temp);

		
		if (temp != NULL) {
			// adiciona ao vetor de processos
			this->processos.push_back(*temp);
			// libera memoria
			free(temp); 
		}
		else {
			cout << "Erro ao Gerar Processo. Valor Invalido.";
		}
		
	}
}

void Gerenciador::calculaSjf() {
	// nao altera o vetor original,
	// apenas calcula e imprime
	this->sjf.calculaTempo(this->processos);
}

void Gerenciador::calculaFifo() {
	// nao altera o vetor original,
	// apenas calcula e imprime
	this->fifo.calculaTempo(this->processos);
}

void Gerenciador::imprimeProcessos() {
	for (int i = 0; i < this->processos.size(); i++) {
		cout << this->processos[i].getTipo() << " Tempo: " << this->processos[i].getTempoProc() << endl;
	}
}

void Gerenciador::imprimeSjf() {
	// Acessa os atributos do objeto SJF
	// Inacessiveis pela main
	cout << "SJF: " << endl;

	cout << "Tempo de Espera Medio: " << this->sjf.getTempoMedioEspera() << " ms" << endl;
	cout << "Tempo de Execucao Medio: " << this->sjf.getTempoMedioExe() << " ms" << endl;
}

void Gerenciador::imprimeFifo() {
	// Acessa os atributos do objeto FIFO
	// Inacessiveis pela main
	cout << "FIFO: " << endl;

	cout << "Tempo de Espera Medio: " << this->fifo.getTempoMedioEspera() << " ms" << endl;
	cout << "Tempo de Execucao Medio: " << this->fifo.getTempoMedioExe() << " ms" << endl;
}

void Gerenciador::calculaTempoProc(Processo *processo) {
	// calcula tempo de processamento
	float tempDado = processo->getDado() * 5;
	float tempTexto = processo->getTexto().length() * 7.5;
	processo->setTempoProc(tempDado + tempTexto);
}