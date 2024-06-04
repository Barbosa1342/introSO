#include "escalonamento.hpp"

Escalonamento::Escalonamento() {
}

void Escalonamento::setTempoExe(float tempoMedioExe) {
    this->tempoMedioExe = tempoMedioExe;
}

float Escalonamento::getTempoExe() {
    return this->tempoMedioExe;
}
