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


class Gerenciador{
private:
	vector<Processo> processos;
	SJF sjf;
public:
	Gerenciador();

	void geraProcessos();
	void calculaSjf();
	void imprimeProcessos();
	void calculaTempoExe(Processo *processo);
};

#endif // !GERENCIADOR_HPP
