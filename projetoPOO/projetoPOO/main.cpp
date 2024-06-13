#include "gerenciador.hpp"

void encerramento() {
	cout << endl;
	cout << "Obrigado por utizar nossa maquina virtual." << endl;
	cout << "Creditos: " << endl;
	cout << "- Denis Magri GitHub: DenisMagri" << endl << "- Gabriel Barbosa GitHub: Barbosa1342" << endl << endl;
	cout << "https://github.com/Barbosa1342/introSO" << endl;
	cout << " -=- Fundacao Herminio Ometto -=- " << endl;
}

int menuEscalonamento(Gerenciador &gerenciador) {
	int opcao = 0;

	cout << "1 - Metodo SJF" << endl;
	cout << "2 - Metodo FIFO" << endl;
	cout << "3 - Sair" << endl;
	cin >> opcao;

	system("cls");

	if (opcao == 1) {
		gerenciador.calculaSjf();
		return 1;
	}
	else if (opcao == 2) {
		gerenciador.calculaFifo();
		return 2;
	}
	else if (opcao == 3) {
		cout << "Nenhum Sistema foi escolhido!" << endl;
		return 3;
	}
	else {
		cout << "Opcao Invalida. Tente Novamente" << endl;
		menuEscalonamento(gerenciador);
	}
}

int menu(Gerenciador &gerenciador) {
	int opcao = 0;

	cout << "--------------------------Menu--------------------------" << endl;
	cout << "Insira a seguir o numero referente a opcao desejada: " << endl;
	cout << "1 - Abrir Navegador" << endl;
	cout << "2 - Abrir Discord" << endl;
	cout << "3 - Abrir Visual studio" << endl;
	cout << "4 - Outros Aplicativos" << endl;
	cout << "5 - Sair" << endl;
	cin >> opcao;

	if (opcao < 1 || opcao > 5) {
		cout << "Opcao Invalida. Tente Novamente." << endl;
	}
	else {
		if (opcao == 1) {
			gerenciador.geraProcessos(15);
		}
		else if (opcao == 2) {
			gerenciador.geraProcessos(10);
		}
		else if (opcao == 3) {
			gerenciador.geraProcessos(13);
		}
		else if (opcao == 4) {
			gerenciador.geraProcessos();
		}
		else if (opcao == 5) {
			return NULL;
		}
		system("cls");

		cout << "Selecione o Sistema de Escalonamento: " << endl;
		opcao = menuEscalonamento(gerenciador);

		if (opcao == 3) {
			return NULL;
		}

		int temp = 0;
		cout << "Testar outro Sistema de Escalonamento?" << endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		cin >> temp;

		

		if (temp == 1) {
			if (opcao == 1) {
				gerenciador.calculaFifo();
				gerenciador.imprimeFifo();
			}
			else if (opcao == 2) {
				gerenciador.calculaSjf();
				gerenciador.imprimeSjf();
			}
		}
		if (opcao == 1) {
			gerenciador.imprimeSjf();
		}
		else if (opcao == 2) {
			gerenciador.imprimeFifo();
		}
		


		system("pause");
		system("cls");
	}
	menu(gerenciador);
}

void intro() {
	cout << "================================================" << endl;
	cout << "	Seja bem vindo a Maquina Virtual!!!		" << endl;
	cout << "================================================" << endl;
	cout << endl;
}

int main() {
	srand(time(NULL)); // evita a repeticao dos numeros pseudoaleatorios

	Gerenciador gerenciador;

	intro();
	menu(gerenciador);

	cout << "Teste Concluido com Sucesso" << endl;
	encerramento();
	return 0;
}

	/*
	cout << "Ensinando C++ para o Denis..." << endl;
	*/

