#ifndef GERENCIAJOGADORES_H
#define GERENCIAJOGADORES_H

#include <iostream>
#include <map>
#include <fstream>
#include <memory>
#include <sstream>
#include "Jogador.hpp"

class GerenciaJogadores {
private:
    std::map<std::string, std::shared_ptr<Jogador>> jogadores; // Mapa de jogadores (apelido como chave)
    std::string arquivoDados;

public:
    GerenciaJogadores(const std::string& arquivo = "jogadores.txt");
    ~GerenciaJogadores();

    void cadastrarJogador(const std::string& nome, const std::string& apelido);
    void removerJogador(const std::string& apelido);
    void printarJogadores() const;
    void salvarDados(const std::string& arquivo) const;
    void carregarDados();
    
    // Novo método para buscar jogador pelo apelido
    std::shared_ptr<Jogador> buscarJogador(const std::string& apelido);
};

#endif
