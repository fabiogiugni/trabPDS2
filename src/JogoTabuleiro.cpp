#include "JogoTabuleiro.hpp"

JogoTabuleiro::JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)
    : jogador1(jogador1), jogador2(jogador2), dimensaoTabuleiro(n), jogadorAtual(true) {
    if (n <= 0) {
        throw DimensaoInvalidaException("A dimensão do tabuleiro deve ser maior que zero.");
    }

    tabuleiro = std::vector<std::vector<char>>(n, std::vector<char>(n, '-'));
}

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

bool JogoTabuleiro::isVitoria() {
    // Este método seria implementado de acordo com as regras do jogo específico.
    return false;
}
