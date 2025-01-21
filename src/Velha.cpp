#include "Velha.hpp"
#include <iostream>

// Construtor
Velha::Velha(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2)
    : JogoTabuleiro(jogador1, jogador2, 3) {} // Tabuleiro fixo 3x3

// Validação de jogada
bool Velha::isJogadaValida(char linha, int coluna) {
    // Reutiliza a validação da classe base
    return JogoTabuleiro::isJogadaValida(linha, coluna);
}

// Realizar jogada
void Velha::leJogada(char linha, int coluna) {
    // Reutiliza a lógica de jogada da classe base
    JogoTabuleiro::leJogada(linha, coluna);

    // Verifica vitória após cada jogada
    if (isVitoria()) {
        std::cout << "Vitória do jogador " << (jogadorAtual ? "2" : "1") << "!" << std::endl;
        printaTabuleiro();
        exit(0); // Termina o programa
    }
}

// Verificação de vitória
bool Velha::isVitoria() {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < 3; ++i) {
        // Linha
        if (tabuleiro[i][0] != '-' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return true;

        // Coluna
        if (tabuleiro[0][i] != '-' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return true;
    }

    // Diagonal principal
    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return true;

    // Diagonal secundária
    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return true;

    return false;
}
