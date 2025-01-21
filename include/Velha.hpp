#ifndef VELHA_H
#define VELHA_H

#include "JogoTabuleiro.hpp"

class Velha : public JogoTabuleiro {
public:
    // Construtor
    Velha(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2);

    // Sobrescrever métodos virtuais da classe base
    bool isJogadaValida(char linha, int coluna) override;
    void leJogada(char linha, int coluna) override;
    bool isVitoria() override;
};

#endif