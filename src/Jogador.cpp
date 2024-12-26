#include "Jogador.hpp"

Jogador::Jogador():nome(""),apelido(""), vitoriasLig4(0), vitoriasReversi(0), vitoriasVelha(0), derrotasLig4(0), derrotasReversi(0), derrotasVelha(0) {}

Jogador::Jogador(const std::string& nome, const std::string& apelido)
    : nome(nome), apelido(apelido), vitoriasLig4(0), vitoriasReversi(0), vitoriasVelha(0), derrotasLig4(0), derrotasReversi(0), derrotasVelha(0) {}

Jogador::~Jogador(){}

void Jogador::incrementarVitoriaReversi() { vitoriasReversi++; }
void Jogador::incrementarVitoriaLig4() { vitoriasLig4++; }
void Jogador::incrementarVitoriaVelha() { vitoriasVelha++; }
void Jogador::incrementarDerrotaReversi() { derrotasReversi++; }
void Jogador::incrementarDerrotaLig4() { derrotasLig4++; }
void Jogador::incrementarDerrotaVelha() { derrotasVelha++; }

std::string Jogador::getApelido() const { return apelido; }
std::string Jogador::getNome() const { return nome; }

int Jogador::getVitoriasReversi() const { return vitoriasReversi; }
int Jogador::getVitoriasLig4() const { return vitoriasLig4; }
int Jogador::getVitoriasVelha() const { return vitoriasVelha; }

void Jogador::printaJogador() const {
    std::cout << apelido << " " << nome << std:: endl;
    std::cout << "REVERSI - V: " << vitoriasReversi<< " D: " << derrotasReversi << std::endl;
    std::cout << "LIG4    - V: " << vitoriasLig4   << " D: " << derrotasLig4    << std::endl;
    std::cout << "VELHA   - V: " << vitoriasVelha  << " D: " << derrotasVelha   << std::endl;
}
