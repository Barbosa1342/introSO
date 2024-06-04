#include "gerenciador.hpp"

int main() {
	srand(time(NULL)); // evita a repeticao dos numeros pseudoaleatorios
	cout << "Ensinando C++ para o Denis..." << endl;


	Gerenciador teste;

	teste.geraProcessos();
	teste.imprimeProcessos();

	cout << endl;

	teste.calculaSjf();
}

