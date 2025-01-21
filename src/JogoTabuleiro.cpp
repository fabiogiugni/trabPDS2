#include "JogoTabuleiro.hpp"

JogoTabuleiro::JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)
    : jogador1(jogador1), jogador2(jogador2), tabuleiro(n, std::vector<char>(n, '-')), dimensaoTabuleiro(n), jogadorAtual(true) {}


bool JogoTabuleiro::isJogadaValida(char linha, int coluna) {
    if (linha >= 'A' && linha < 'A' + dimensaoTabuleiro &&
        coluna >= 1 && coluna <= dimensaoTabuleiro &&
        tabuleiro[linha - 'A'][coluna - 1] == '-') {
        return true;
    }
    return false;
}

void JogoTabuleiro::leJogada(char linha, int coluna) {
    if (isJogadaValida(linha, coluna)) {
        // Definir o símbolo do jogador atual
        char simbolo = jogadorAtual ? 'X' : 'O';
        tabuleiro[linha - 'A'][coluna - 1] = simbolo;

        // Alternar o jogador
        jogadorAtual = !jogadorAtual;
    } else {
        std::cout << "ERRO: Jogada Inválida" << std::endl;
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
