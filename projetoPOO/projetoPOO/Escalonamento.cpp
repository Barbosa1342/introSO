#include "escalonamento.hpp"

Escalonamento::Escalonamento() {
}

void Escalonamento::setTempoMedioExe(float tempoMedioExe) {
    this->tempoMedioExe = tempoMedioExe;
}

float Escalonamento::getTempoMedioExe() {
    return this->tempoMedioExe;
}

void Escalonamento::setTempoMedioEspera(float tempoMedioEspera) {
    this->tempoMedioEspera = tempoMedioEspera;
}

float Escalonamento::getTempoMedioEspera() {
    return this->tempoMedioEspera;
}