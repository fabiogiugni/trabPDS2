#ifndef REVERSI_H
#define REVERSI_H

#include "JogoTabuleiro.hpp"
#include <iostream>
#include <vector>

class Reversi : public JogoTabuleiro {
private:
    std::vector<std::vector<char>> tabuleiro; // Tabuleiro dinâmico

public:
    // Construtores
    Reversi();
    Reversi(const Jogador& jogador1, const Jogador& jogador2);

    // Métodos
    void leJogada(char linha, int coluna) override; 
    bool isJogadaValida() override; 
    void printaTabuleiro() const override; 
    bool isVitoria() override; 

    // Métodos específicos de Reversi
    void inicializaTabuleiro(); 
    void atualizaTabuleiro(int linha, int coluna, char jogador); 
    bool podeVirarPecas(int linha, int coluna, char jogador); 
};

#endif 