#ifndef LIG4_HPP
#define LIG4_HPP

#include "JogoTabuleiro.hpp"
#include <memory>
#include <vector>

class Lig4 : public JogoTabuleiro {
public:

    Lig4(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n);

    void leJogada(char linha, int coluna) override;
    bool isJogadaValida(char linha, int coluna) override;
    void printaTabuleiro() const override;

    bool isVitoria() override;
    bool isEmpate() const;

private:
    std::vector<std::vector<char>> tabuleiro;
    int ultimaLinha = -1;
    int ultimaColuna = -1;
};

#endif
