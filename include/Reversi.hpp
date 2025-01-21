#ifndef REVERSI_H
#define REVERSI_H

#include "JogoTabuleiro.hpp"

class Reversi : public JogoTabuleiro {
public:

    Reversi(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n);

    void leJogada(char linha, int coluna) override;
    bool isJogadaValida(char linha, int coluna) override;
    void printaTabuleiro() const override;

    bool isVitoria() override;

private:
    // Método para virar peças após uma jogada válida
    void virarPecas(char linha, int coluna);

    // Método para verificar se há peças para virar em uma direção
    bool verificaDirecao(int x, int y, int dx, int dy, char pecaAtual);
};
#endif