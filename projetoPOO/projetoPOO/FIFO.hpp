#ifndef FIFO_HPP
#define FIFO_HPP

#include"escalonamento.hpp"
#include "processo.hpp"

class FIFO : public Escalonamento {
private:

public:
	FIFO();
	void calculaTempo(vector<Processo> processos);
};

#endif // !FIFO_HPP
