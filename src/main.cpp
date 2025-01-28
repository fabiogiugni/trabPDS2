#include <iostream>
#include <memory>
#include "GerenciaJogadores.hpp"
#include "Velha.hpp"
#include "Lig4.hpp"
#include "Reversi.hpp"

void exibirMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Cadastrar jogador\n";
    std::cout << "2. Remover jogador\n";
    std::cout << "3. Listar jogadores\n";
    std::cout << "4. Iniciar jogo\n";
    std::cout << "5. Sair\n";
    std::cout << "Escolha: ";
}

void exibirMenuJogos() {
    std::cout << "\n--- ESCOLHA O JOGO ---\n";
    std::cout << "1. Jogo da Velha\n";
    std::cout << "2. Lig4\n";
    std::cout << "3. Reversi\n";
    std::cout << "4. Voltar\n";
    std::cout << "Escolha: ";
}

void iniciarJogo(std::shared_ptr<JogoTabuleiro> jogo) {
    jogo->printaTabuleiro();
    
    while (!jogo->isVitoria()) {
        char linha;
        int coluna;
        std::cout << "\nDigite a jogada (linha letra e coluna número, ex: A1): ";
        std::cin >> linha >> coluna;
        
        try {
            jogo->leJogada(linha, coluna);
            jogo->printaTabuleiro();
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
    
    std::cout << "Fim de jogo!" << std::endl;
}

int main() {
    GerenciaJogadores gerenciador;
    int escolha;

    do {
        exibirMenu();
        std::cin >> escolha;

        if (escolha == 1) {
            std::string nome, apelido;
            std::cout << "Nome do jogador: ";
            std::cin >> nome;
            std::cout << "Apelido: ";
            std::cin >> apelido;
            gerenciador.cadastrarJogador(nome, apelido);

        } else if (escolha == 2) {
            std::string apelido;
            std::cout << "Apelido do jogador a remover: ";
            std::cin >> apelido;
            gerenciador.removerJogador(apelido);

        } else if (escolha == 3) {
            gerenciador.printarJogadores();

        } else if (escolha == 4) {
            exibirMenuJogos();
            int escolhaJogo;
            std::cin >> escolhaJogo;

            if (escolhaJogo == 4) continue;

            std::string apelido1, apelido2;
            std::cout << "Apelido do Jogador 1: ";
            std::cin >> apelido1;
            std::cout << "Apelido do Jogador 2: ";
            std::cin >> apelido2;

            auto jogador1 = gerenciador.buscarJogador(apelido1);
            auto jogador2 = gerenciador.buscarJogador(apelido2);

            if (!jogador1 || !jogador2) {
                std::cout << "Erro: Um ou ambos os jogadores não existem!" << std::endl;
                continue;
            }

            std::shared_ptr<JogoTabuleiro> jogo;
            if (escolhaJogo == 1) {
                jogo = std::make_shared<Velha>(jogador1, jogador2);
            } else if (escolhaJogo == 2) {
                jogo = std::make_shared<Lig4>(jogador1, jogador2, 7);
            } else if (escolhaJogo == 3) {
                jogo = std::make_shared<Reversi>(jogador1, jogador2, 8);
            } else {
                continue;
            }

            iniciarJogo(jogo);
        }

    } while (escolha != 5);

    return 0;
}
