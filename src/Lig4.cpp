#include "Lig4.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

Lig4::Lig4(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)
    : JogoTabuleiro(jogador1, jogador2, n) {
    tabuleiro.resize(n, std::vector<char>(n, ' '));
}


void Lig4::leJogada(char linha, int coluna) {
    coluna--; // Ajusta a coluna para índice baseado em 0
    for (int i = tabuleiro.size() - 1; i >= 0; --i) { 
        if (tabuleiro[i][coluna] == ' ') {
            char pecaAtual = jogadorAtual ? jogador1->getPeca() : jogador2->getPeca();
            tabuleiro[i][coluna] = pecaAtual; 
            ultimaLinha = i;
            ultimaColuna = coluna;
               }
    std::cout << "ERRO: Coluna cheia!" << std::endl;
}


bool Lig4::isJogadaValida(char linha, int coluna) {
    if (!JogoTabuleiro::isJogadaValida(linha, coluna)) {
        return false;
    }
    coluna--;
    return tabuleiro[0][coluna] == ' '; 
}


bool Lig4::isEmpate() const {
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            if (celula == ' ') {
                return false;
            }
        }
    }
    return true; 
}


bool Lig4::isVitoria() {
    char pecaAtual = tabuleiro[ultimaLinha][ultimaColuna];
    const int direcoes[8][2] = {
        {0, 1},  {1, 0},  {1, 1},  {1, -1}, 
        {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}
    };

    for (int i = 0; i < 4; ++i) { 
        int cont = 1; // Conta a peça atual
        for (int d = 0; d < 2; ++d) { 
            int dx = direcoes[i * 2 + d][0];
            int dy = direcoes[i * 2 + d][1];
            int x = ultimaLinha + dx;
            int y = ultimaColuna + dy;

            while (x >= 0 && x < tabuleiro.size() && y >= 0 && y < tabuleiro.size() && tabuleiro[x][y] == pecaAtual) {
                cont++;
                x += dx;
                y += dy;
            }
        }
        if (cont >= 4)
            return true;
        }
    }

    return false;
}

void Lig4::printaTabuleiro() const {
    JogoTabuleiro::printaTabuleiro();
}
