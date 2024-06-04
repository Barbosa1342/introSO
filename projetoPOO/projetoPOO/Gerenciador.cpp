#include "gerenciador.hpp"

int randomInt(int min = 0, int max = 100) {
	// min e max inclusos
	int random = (rand() % (max - min + 1)) + min;

	return random;
}

string randomStr(int tamanho = 10) {
	const char alfanumericos[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	string temp;

	int tam = sizeof(alfanumericos) / sizeof(alfanumericos[0]);
	for (int i = 0; i < tamanho; i++) {
		temp += alfanumericos[randomInt(0, tam)];
	}

	return temp;
}

Gerenciador::Gerenciador() {

}

void Gerenciador::geraProcessos() {
	int numeroRandom = randomInt(5, 10);

	for (int i = 0; i < numeroRandom; i++) {
		int classe = randomInt(1, 5);

		Processo* temp{};

		if (classe == 1) {
			temp = new Interativa;
		}
		else if (classe == 2) {
			temp = new IO;
		}
		else if (classe == 3) {
			temp = new Lote;
		}
		else if (classe == 4) {
			temp = new Processamento;
		}
		else if (classe == 5) {
			temp = new TempoReal;
		}

		temp->setDados(randomInt());
		temp->setId(i);
		temp->setTexto(randomStr());
		calculaTempoExe(temp);

		this->processos.push_back(*temp);
	}
}

void Gerenciador::calculaSjf() {
	SJF escaSJF;
	escaSJF.calculaTempo(processos);
}

void Gerenciador::imprimeProcessos() {
	for (int i = 0; i < this->processos.size(); i++) {
		cout << this->processos[i].getTipo() << " Tempo: " << this->processos[i].getTempoExe() << endl;
	}
}

void Gerenciador::calculaTempoExe(Processo *processo) {
	float tempDado = processo->getDado() * 5;
	float tempTexto = processo->getTexto().length() * 7.5;
	processo->setTempoExe(tempDado + tempTexto);
}