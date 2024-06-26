#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "includes.hpp"

#include "Processo.hpp"
#include "Interativa.hpp"
#include "IO.hpp"
#include "Lote.hpp"
#include "Processamento.hpp"
#include "TempoReal.hpp"

#include "sjf.hpp"
#include "FIFO.hpp"

class Gerenciador{
private:
	vector<Processo> processos;
	SJF sjf;
	FIFO fifo;
public:
	Gerenciador();

	void geraProcessos(int numProcessos = 0);
	void calculaSjf();
	void calculaFifo();
	void imprimeProcessos();
	void imprimeSjf();
	void imprimeFifo();
	void calculaTempoProc(Processo *processo);
};

#endif // !GERENCIADOR_HPP
