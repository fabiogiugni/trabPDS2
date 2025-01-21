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
    Jogador(const std::string& nome, const std::string& apelido); //Construtor mais completo
    ~Jogador();
    //Getters
    std::string getApelido() const { return apelido; }
    std::string getNome() const { return nome; }
    int getVitoriasReversi() const { return vitoriasReversi; }
    int getVitoriasLig4() const { return vitoriasLig4; }
    int getVitoriasVelha() const { return vitoriasVelha; }
    int getDerrotasReversi() const { return derrotasReversi; }
    int getDerrotasLig4() const { return derrotasLig4; }
    int getDerrotasVelha() const { return derrotasVelha; }
    //Printar Jogador
    void printaJogador() const;
    //Setters (no caso somente incrementam)
    void incrementarVitoriaReversi();
    void incrementarVitoriaLig4();
    void incrementarVitoriaVelha();
    void incrementarDerrotaReversi();
    void incrementarDerrotaLig4();
    void incrementarDerrotaVelha();
};

#endif