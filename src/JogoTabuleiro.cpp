#include "JogoTabuleiro.hpp"


bool JogoTabuleiro::isJogadaValida(char linha, int coluna) {
    if (linha < 'A' || linha >= 'A' + dimensaoTabuleiro || coluna < 1 || coluna > dimensaoTabuleiro) {
        throw JogadaInvalidaException("Coordenadas fora dos limites do tabuleiro.");
    }

    if (tabuleiro[linha - 'A'][coluna - 1] != '-') {
        throw JogadaInvalidaException("A posição escolhida já está ocupada.");
    }

    return true;
}

void JogoTabuleiro::leJogada(char linha, int coluna) {
    try {
        if (isJogadaValida(linha, coluna)) {
            char simbolo = jogadorAtual ? 'X' : 'O';
            tabuleiro[linha - 'A'][coluna - 1] = simbolo;
            jogadorAtual = !jogadorAtual;
        }
    } catch (const JogadaInvalidaException& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void JogoTabuleiro::printaTabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (const auto& celula : linha) {
            std::cout << celula << " ";
        }
        std::cout << "\n";
    }
}

