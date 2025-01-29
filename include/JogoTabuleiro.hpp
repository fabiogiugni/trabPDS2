#ifndef JOGOTABULEIRO_H
#define JOGOTABULEIRO_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept> // Para exceções

class JogoTabuleiro {
protected:
    std::shared_ptr<Jogador> jogador1, jogador2;
    std::vector<std::vector<char>> tabuleiro;
    int dimensaoTabuleiro;
    bool jogadorAtual; // true para jogador1, false para jogador2

public:
    JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n); // Construtor
    virtual ~JogoTabuleiro() = default;

    // Leitura Jogada
    virtual void leJogada(char linha, int coluna);

    // Validação Jogada
    virtual bool isJogadaValida(char linha, int coluna);

    // Printar Tabuleiro
    virtual void printaTabuleiro() const;

    // Testa Condição de Vitória
    virtual bool isVitoria();

    // Testa Condição de Empate
    virtual bool isEmpate() const = 0;

    // Exceções Específicas
    class JogadaInvalidaException : public std::runtime_error {
    public:
        explicit JogadaInvalidaException(const std::string& mensagem) : std::runtime_error(mensagem) {}
    };

    class DimensaoInvalidaException : public std::invalid_argument {
    public:
        explicit DimensaoInvalidaException(const std::string& mensagem) : std::invalid_argument(mensagem) {}
    };
};

#endif
