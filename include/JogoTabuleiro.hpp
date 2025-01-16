#ifndef JOGOTABULEIRO_H
#define JOGOTABULEIRO_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <memory>

class JogoTabuleiro {
private:
    std::shared_ptr<Jogador> jogador1, jogador2;
    std::vector<std::vector<char>> tabuleiro;
    int dimensaoTabuleiro;

public:
    JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n); // Construtor mais completo
    ~JogoTabuleiro(){};

    // Leitura Jogada
    virtual void leJogada(char linha, int coluna);

    // Validação Jogada
    virtual bool isJogadaValida(char linha, int coluna);

    // Printar Jogador
    virtual void printaTabuleiro() const;

    // Testa Condição de Vitória
    virtual bool isVitoria();
};

#endif
