#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

class Jogador
{
private:
    std::string nome;
    std::string apelido;
    int vitoriasReversi;
    int vitoriasLig4;
    int vitoriasVelha;
    int derrotasReversi;
    int derrotasLig4;
    int derrotasVelha;

public:
    Jogador(); //Construtor padrão
    Jogador(const std::string& nome, const std::string& apelido){} //Construtor mais completo
    ~Jogador();
    //Getters
    std::string getApelido() const {}
    std::string getNome() const {}
    int getVitoriasReversi() const {}
    int getVitoriasLig4() const {}
    int getVitoriasVelha() const {}
    int getDerrotasReversi() const {}
    int getDerrotasLig4() const {}
    int getDerrotasVelha() const {}
    //Printar Jogador
    void printaJogador() const {}
    //Setters (no caso somente incrementam)
    void incrementarVitoriaReversi() {}
    void incrementarVitoriaLig4() {}
    void incrementarVitoriaVelha() {}
    void incrementarDerrotaReversi() {}
    void incrementarDerrotaLig4() {}
    void incrementarDerrotaVelha() {}
};

#endif