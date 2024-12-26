#include "GerenciaJogadores.hpp"

GerenciaJogadores::GerenciaJogadores(const std::string& arquivo = "jogadores.txt"): arquivoDados(arquivo) { carregarDados(); }

GerenciaJogadores::~GerenciaJogadores() { salvarDados(); } // Salvar ao sair do programa 