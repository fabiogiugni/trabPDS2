#include "Velha.hpp"
#include <iostream>

// construtor
Velha::Velha(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2)
    : JogoTabuleiro(jogador1, jogador2, 3) {} // tabuleiro fixo 3x3

bool Velha::isJogadaValida(char linha, int coluna) {
    // reutiliza a validação da classe base
    return JogoTabuleiro::isJogadaValida(linha, coluna);
}

void Velha::leJogada(char linha, int coluna) {
    // Reutiliza a lógica de jogada da classe base
    JogoTabuleiro::leJogada(linha, coluna);

    // Verifica vitória após cada jogada
    if (isVitoria()) {
        std::cout << "Vitória do jogador " << (jogadorAtual ? "2" : "1") << "!" << std::endl;
        if (jogadorAtual) {
            jogador2->incrementarVitoriaVelha(); // Jogador 2 venceu
            jogador1->incrementarDerrotaVelha(); // Jogador 1 perdeu
        } else {
            jogador1->incrementarVitoriaVelha(); // Jogador 1 venceu
            jogador2->incrementarDerrotaVelha(); // Jogador 2 perdeu
        }
        printaTabuleiro();
        return; // Termina o programa
    }
}

bool Velha::isVitoria() {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] != '-' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return true;

        if (tabuleiro[0][i] != '-' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return true;
    }

    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return true;

    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return true;

    return false;
}

bool Velha::isEmpate() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

