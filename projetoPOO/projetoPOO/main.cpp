#include "gerenciador.hpp"

int main() {
	srand(time(NULL)); // evita a repeticao dos numeros pseudoaleatorios
	cout << "Ensinando C++ para o Denis..." << endl;

	// sera decidido pelo usuario
	int numProcessos = 10;

	Gerenciador teste;

	teste.geraProcessos(numProcessos);
	teste.imprimeProcessos();

	cout << endl;

	teste.calculaFifo();
}

