#include "JogoTabuleiro.hpp"

JogoTabuleiro::JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n) :
    jogador1(jogador1), jogador2(jogador2), dimensaoTabuleiro(n), tabuleiro(n, std::vector<char>(n, '-')) {}

bool JogoTabuleiro::isJogadaValida(char linha, int coluna) {
    if(tabuleiro[linha - 65][coluna - 1] == '-') {
        return true;
    } else {
        return false;
    }
}

void JogoTabuleiro::leJogada(char linha, int coluna) {
    if(isJogadaValida(linha, coluna)) {
        tabuleiro[linha - 65][coluna - 1] = 'X ou O'; // como fazer pra definir qual jogador tá jogando??
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