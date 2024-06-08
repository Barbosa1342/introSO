#include "Processo.hpp"

Processo::Processo() {

}

void Processo::setTipo(string tipo) {
	this->tipo = tipo;
}

void Processo::setId(int id) {
	this->id = id;
}

void Processo::setDados(int dados) {
	this->dados = dados;
}

void Processo::setTexto(string texto) {
	this->texto = texto;
}

void Processo::setTempoProc(float tempoProc) {
	this->tempoProc = tempoProc;
}

string Processo::getTipo() {
	return this->tipo;
}

int Processo::getId() {
	return this->id;
}

int Processo::getDado() {
	return this->dados;
}

string Processo::getTexto() {
	return this->texto;
}

float Processo::getTempoProc() {
	return this->tempoProc;
}