#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)
    : JogoTabuleiro(jogador1, jogador2, 8) {

    int meio = 8 / 2;
    tabuleiro[meio - 1][meio - 1] = 'O';
    tabuleiro[meio - 1][meio] = 'X';
    tabuleiro[meio][meio - 1] = 'X';
    tabuleiro[meio][meio] = 'O';
}

void Reversi::leJogada(char linha, int coluna) {
    if (isJogadaValida(linha, coluna)) {
        char pecaAtual = jogadorAtual ? 'X' : 'O';
        tabuleiro[linha - 'A'][coluna - 1] = pecaAtual;
        virarPecas(linha, coluna);
        jogadorAtual = !jogadorAtual; // Alternar jogador
    } else {
        std::cout << "ERRO: Jogada Inválida" << std::endl;
    }
}

bool Reversi::isJogadaValida(char linha, int coluna) {
    if (!JogoTabuleiro::isJogadaValida(linha, coluna)) {
        return false;
    }

    char pecaAtual = jogadorAtual ? 'X' : 'O';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                if (verificaDirecao(linha - 'A', coluna - 1, dx, dy, pecaAtual)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Reversi::printaTabuleiro() const {
    JogoTabuleiro::printaTabuleiro();
}

bool Reversi::isVitoria() {
    int countX = 0, countO = 0;
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            if (celula == 'X') ++countX;
            else if (celula == 'O') ++countO;
        }
    }
    if (countX == 0 || countO == 0 || (countX + countO == dimensaoTabuleiro * dimensaoTabuleiro)) {
        std::cout << "Fim de jogo! ";
        if (countX > countO) std::cout << "X venceu!";
        else if (countO > countX) std::cout << "O venceu!";
        else std::cout << "Empate!";
        std::cout << std::endl;
        return true;
    }
    return false;
}

bool Reversi::isEmpate() const {

    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            if (celula == '-') { 
                return false; 
            }
        }
    }
    return true; 
}


void Reversi::virarPecas(char linha, int coluna) {
    char pecaAtual = jogadorAtual ? 'X' : 'O';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if ((dx != 0 || dy != 0) && verificaDirecao(linha - 'A', coluna - 1, dx, dy, pecaAtual)) {
                int x = linha - 'A' + dx;
                int y = coluna - 1 + dy;
                while (tabuleiro[x][y] != pecaAtual) {
                    tabuleiro[x][y] = pecaAtual;
                    x += dx;
                    y += dy;
                }
            }
        }
    }
}

bool Reversi::verificaDirecao(int x, int y, int dx, int dy, char pecaAtual) {
    char pecaOponente = pecaAtual == 'X' ? 'O' : 'X';
    x += dx;
    y += dy;
    bool encontrouOponente = false;

    while (x >= 0 && x < dimensaoTabuleiro && y >= 0 && y < dimensaoTabuleiro) {
        if (tabuleiro[x][y] == pecaOponente) {
            encontrouOponente = true;
        } else if (tabuleiro[x][y] == pecaAtual) {
            return encontrouOponente;
        } else {
            break;
        }
        x += dx;
        y += dy;
    }
    return false;
}
