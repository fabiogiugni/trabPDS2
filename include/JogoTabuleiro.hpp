#ifndef JOGOTABULEIRO_H
#define JOGOTABULEIRO_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>

class JogoTabuleiro
{
private:
    char a1 = ' ', a2 = ' ', a3 = ' ';
    char b1 = ' ', b2 = ' ', b3 = ' ';
    char c1 = ' ', c2 = ' ', c3 = ' ';

    std::vector<std::vector<char>> tabuleiro = {
        {a1, a2, a3},
        {b1, b2, b3},
        {c1, c2, c3}
    };

public:
    JogoTabuleiro(); //Construtor padrão
    JogoTabuleiro(const Jogador jogador1,const Jogador jogador2){} //Construtor mais completo
    ~JogoTabuleiro();
    //Leitura Jogada
    virtual void leJogada (char linha, int coluna) ;
    //Validação Jogada
    virtual bool isJogadaValida();
    //Printar Jogador
    virtual void printaTabuleiro() const {}
    //Testa Condição de Vitória
    virtual bool isVitoria() {}
};

#endif