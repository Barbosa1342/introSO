#include "gerenciador.hpp"


int main() {

	Gerenciador G1;

	while (true) {
		int opcao = 0;

		cout << "	================================================" << endl;
		cout << "	   Seja bem vindo a nossa Maquina virtual!!!" << endl;
		cout << "	================================================" << endl;

		cout << "--------------------------Menu--------------------------" << endl;
		cout << "Insira a seguir o numero referente a opcao desejada" << endl;

		cout << "1 - Abrir Navegador" << endl;
		cout << "2 - Abrir Discord" << endl;
		cout << "3 - Abrir Visual studio" << endl;
		cout << "4 - Outros Aplicativos" << endl;
		cin >> opcao;

		if (opcao == 1) {
			cout << "Gera vetor de tamanho 15" << endl;
			G1.geraProcessos(15);
		}
		else if(opcao == 2) {
			cout << "Gera vetor de tamanho 10" << endl;
			G1.geraProcessos(10);
		}
		else if (opcao == 3) {
			cout << "Gera vetor de tamanho 13" << endl;
			G1.geraProcessos(13);
		}
		else if (opcao == 4) {
			cout << "Gera vetor aleatorio" << endl;
			G1.geraProcessos(0);
		}
		else {
			cout << "Opcao invalida por favor verifique as op�oes e tente novamente" << endl;
			main();
		}
		system("pause");

		cout << "Selecione um sistema de escalonamento:" << endl;
		cout << "1 - Metodo SJF" << endl;
		cout << "2 - Metodo FIFO" << endl;
		if (opcao == 1) {
			G1.calculaSjf();
		}
		else if (opcao == 2) {
			G1.calculaFifo();
		}
		else if (opcao == 3) {
			main();
		}
		else {
			cout<< "Opcao invalida por favor verifique as op�oes e tente novamente" << endl;
			main();
		}

		cout << "Deseja testa outro sistema de escalonamento: " << endl;
		cout << "1 - Metodo SJF" << endl;
		cout << "2 - Metodo FIFO" << endl;
		cout << "3 - retorna para o menu" << endl;
		if (opcao == 1) {
			G1.calculaSjf();
		}
		else if (opcao == 2) {
			G1.calculaFifo();
		}
		else if (opcao == 3) {
			main();
		}
		else {
			cout << "Opcao invalida por favor verifique as op�oes e tente novamente" << endl;
			main();
		}
		
		cout << "Teste efetuados com sucesso" << endl;
		cout << "Selecione a opcao desejada: " << endl;
		cout << "1 - Retornar ao menu" << endl;
		cout << "2 - Finalizar maquina Virtual" << endl;
		if (opcao == 1) {
			system("cls");
			main();
		}
		else if (opcao == 2) {
			cout << "Obrigado por utizar nossa maquina virtual" << endl;
			cout << "Autores: Denis Magri" << endl << "Gabriel Barbosa" << endl;
			cout << "Fundacao Herminio Ometto" << endl;
		}
		system("pause");
		return 0;
	}

	/*
	srand(time(NULL)); // evita a repeticao dos numeros pseudoaleatorios
	cout << "Ensinando C++ para o Denis..." << endl;
	
	// sera decidido pelo usuario
	int numProcessos = 10;

	Gerenciador teste;

	teste.geraProcessos(numProcessos);
	teste.imprimeProcessos();

	cout << endl;

	teste.calculaFifo();
	*/
}

