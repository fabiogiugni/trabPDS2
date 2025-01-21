#include "GerenciaJogadores.hpp"

GerenciaJogadores::GerenciaJogadores(const std::string& arquivo) : arquivoDados(arquivo) { carregarDados(); }

GerenciaJogadores::~GerenciaJogadores() { salvarDados(arquivoDados); } // Salvar ao sair do programa

void GerenciaJogadores::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    auto jogador = std::make_unique<Jogador>(nome, apelido);
    auto it = jogadores.find(apelido);
    if (it != jogadores.end()) {
        std::cout << "Erro: Apelido já cadastrado!" << std::endl;
        return;
    }
    jogadores[apelido] = std::move(jogador);
}

void GerenciaJogadores::salvarDados(const std::string& arquivo) const {
    std::ofstream out(arquivo);
    if (!out) {
        std::cerr << "ERRO: arquivo não foi aberto para a escrita!" << std::endl;
        return;
    }

    for (const auto& jogadorPair : jogadores) {
        out << jogadorPair.second->getNome() << ";"
            << jogadorPair.second->getApelido() << ";"
            << jogadorPair.second->getVitoriasReversi() << ";"
            << jogadorPair.second->getDerrotasReversi() << ";"
            << jogadorPair.second->getVitoriasLig4() << ";"
            << jogadorPair.second->getDerrotasLig4() << ";"
            << jogadorPair.second->getVitoriasVelha() << ";"
            << jogadorPair.second->getDerrotasVelha() << "\n";
    }
    out.close();
    std::cout << "Dados salvos em .txt" << std::endl;
}

 void GerenciaJogadores::carregarDados() {
        std::ifstream arquivo(arquivoDados);
        if (!arquivo.is_open()) {
            std::cout << "Arquivo de dados não encontrado. Um novo será criado ao salvar." << std::endl;
            return;
        }

        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            std::string nome, apelido;
            int vitoriasReversi, derrotasReversi, vitoriasLig4, derrotasLig4, vitoriasVelha, derrotasVelha;

            //leitura de dados

            std::getline(iss, nome, ';');
            std::getline(iss, apelido, ';');
            iss >> vitoriasReversi;
            iss.ignore(1, ';');
            iss >> derrotasReversi;
            iss.ignore(1, ';');
            iss >> vitoriasLig4;
            iss.ignore(1, ';');
            iss >> derrotasLig4;
            iss.ignore(1, ';');
            iss >> vitoriasVelha;
            iss.ignore(1, ';');
            iss >> derrotasVelha;

            //seta vitorias e derrotas

            auto jogador = std::make_shared<Jogador>(nome, apelido);
            for (int i = 0; i < vitoriasReversi; ++i) jogador->incrementarVitoriaReversi();
            for (int i = 0; i < derrotasReversi; ++i) jogador->incrementarDerrotaReversi();
            for (int i = 0; i < vitoriasLig4; ++i) jogador->incrementarVitoriaLig4();
            for (int i = 0; i < derrotasLig4; ++i) jogador->incrementarDerrotaLig4();
            for (int i = 0; i < vitoriasVelha; ++i) jogador->incrementarVitoriaVelha();
            for (int i = 0; i < derrotasVelha; ++i) jogador->incrementarDerrotaVelha();

            jogadores[apelido] = std::move(jogador); //adiciona jogador ao mapa
        }

        arquivo.close();
        std::cout << "Dados carregados com sucesso." << std::endl;
    }

    void GerenciaJogadores::printarJogadores() const {
        for(const auto& jogadorPair : jogadores){
            jogadorPair.second->printaJogador();
        }
    }

    void GerenciaJogadores::removerJogador(const std::string& apelido) {
        auto it = jogadores.find(apelido);
        if(it == jogadores.end()){
            std::cout<<"Erro: Apelido não cadastrado!"<<std::endl;
            return;
        }
        jogadores.erase(it);
    }