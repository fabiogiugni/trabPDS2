# trabPDS2
Jogador: 

A classe Jogador representa um jogador e armazena suas informações básicas, como nome, apelido e estatísticas de vitórias e derrotas.
Atributos
std::string nome → Nome do jogador.
std::string apelido → Apelido único do jogador.
int vitoriasReversi, vitoriasLig4, vitoriasVelha → Contadores de vitórias em cada jogo.
int derrotasReversi, derrotasLig4, derrotasVelha → Contadores de derrotas em cada jogo.
Métodos
Jogador(const std::string& nome, const std::string& apelido) → Construtor mais completo, que recebe nome e apelido.
void printaJogador() const → Exibe as informações do jogador.
char getPeca() const → Retorna 'X' ou 'O', dependendo do apelido, para representar sua peça no tabuleiro.
Além de uma variedade de métodos getters e setters sobre os atributos. Foi escolhido no setter de vitórias e derrotas um método chamado de incrementa vitoria/derrota pela praticidade em aumentar em uma unidade o número de vitórias ou derrotas, ao invés de recorrer a um set. 


Gerencia jogadores:
A classe GerenciaJogadores gerencia um conjunto de jogadores, permitindo cadastrar, remover e listar jogadores.

Atributos
std::map<std::string, std::shared_ptr<Jogador>> jogadores → Mapeia apelidos a objetos Jogador.
std::string arquivoDados → Nome do arquivo onde os jogadores são salvos.
Métodos
GerenciaJogadores(const std::string& arquivo = "jogadores.txt") → Construtor que carrega os jogadores do arquivo.
~GerenciaJogadores() → Destrutor que salva os jogadores no arquivo ao encerrar.
void cadastrarJogador(const std::string& nome, const std::string& apelido) → Adiciona um novo jogador, se o apelido for único.
void removerJogador(const std::string& apelido) → Remove um jogador pelo apelido.
void printarJogadores() const → Exibe a lista de jogadores cadastrados.
void salvarDados(const std::string& arquivo) const → Salva os jogadores no arquivo.
void carregarDados() → Carrega os jogadores do arquivo para a memória.
std::shared_ptr<Jogador> buscarJogador(const std::string& apelido) → Retorna um jogador pelo apelido, se existir.

A escolha de fazer um mapa de ponteiros para jogadores é ideal porque o apelido de cada jogador deve ser único podendo, então, ser a chave do mapa. Além disso, a escolha de ponteiros inteligentes sharedptr, haja vista que são utilizados por outras classes, com escopos diferentes.


JogoTabuleiro

A classe JogoTabuleiro é a classe base para os jogos de tabuleiro, como Velha, Lig4 e Reversi.

Atributos
std::shared_ptr<Jogador> jogador1, jogador2 → Ponteiros para os dois jogadores.
std::vector<std::vector<char>> tabuleiro → Representação da matriz do tabuleiro.
int dimensaoTabuleiro → Tamanho do tabuleiro (ex: 3x3 para Velha, 7x7 para Lig4).
bool jogadorAtual → true para jogador1 e false para jogador2.
Métodos
JogoTabuleiro(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n) → Construtor que inicializa o tabuleiro.
virtual ~JogoTabuleiro() → Destrutor virtual.
virtual void leJogada(char linha, int coluna) → Processa a jogada no tabuleiro.
virtual bool isJogadaValida(char linha, int coluna) → Verifica se uma jogada é válida.
virtual void printaTabuleiro() const → Exibe o tabuleiro no console.
virtual bool isVitoria() → Verifica se há um vencedor.
Exceções:
class JogadaInvalidaException : public std::runtime_error → Exceção para jogadas inválidas.
class DimensaoInvalidaException : public std::invalid_argument → Exceção para dimensões de tabuleiro inválidas.

A modelagem de cara cada tabuleiro segue o padrão da classe abstrata JogoTabuleiro, com uma matriz de char. Como essa classe é a classe pai de 3 Jogos de tabuleiro, sua condição de vitória não é definida, já que ele não é um jogo de fato.

Velha:
A classe Velha implementa o Jogo da Velha, sobrescrevendo os métodos da classe base.

Métodos
Velha(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2) → Construtor que inicializa um tabuleiro 3x3.
bool isJogadaValida(char linha, int coluna) override → Valida se uma jogada é possível.
void leJogada(char linha, int coluna) override → Registra uma jogada e alterna o jogador.
bool isVitoria() override → Verifica se há um vencedor.
Lig4
A classe Lig4 implementa o jogo Lig4, sendo derivada da classe base JogoTabuleiro. Ela sobrescreve métodos essenciais para gerenciar jogadas, validar movimentos e determinar o fim do jogo.

Atributos
std::vector<std::vector<char>> tabuleiro → Representação da matriz do tabuleiro.
int ultimaLinha → Guarda a linha da última jogada realizada.
int ultimaColuna → Guarda a coluna da última jogada realizada.
Métodos
Lig4(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n) → Construtor que inicializa o tabuleiro com o tamanho adequado e configura os jogadores.
void leJogada(char linha, int coluna) override → Processa a jogada no tabuleiro e alterna o jogador da vez.
bool isJogadaValida(char linha, int coluna) override → Verifica se um movimento é permitido pelas regras do jogo.
void printaTabuleiro() const override → Exibe o tabuleiro no console.
bool isVitoria() override → Verifica se há um vencedor no jogo.
bool isEmpate() const → Verifica se o jogo terminou empatado.
Modelagem e Decisões de Implementação
A classe Lig4 segue a estrutura definida pela classe base JogoTabuleiro, garantindo reutilização de código e flexibilidade para implementação das regras específicas do jogo. A matriz de caracteres representa o tabuleiro, e os atributos ultimaLinha e ultimaColuna auxiliam na verificação da última jogada feita.                                                        A implementação da classe Lig4 define o comportamento do jogo Lig4, incluindo a leitura de jogadas, verificação de vitória e empate, e a exibição do tabuleiro.

Métodos Implementados
Lig4(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)

Construtor que inicializa o tabuleiro com n x n células vazias.
void leJogada(char linha, int coluna)

Processa uma jogada na coluna informada, posicionando a peça na linha mais baixa disponível.
Alterna o jogador da vez, a menos que ocorra uma vitória ou empate.
Se a coluna estiver cheia, exibe uma mensagem de erro.
bool isJogadaValida(char linha, int coluna)

Verifica se a jogada está dentro dos limites e se a coluna não está cheia.
bool isEmpate() const

Retorna true se todas as células do tabuleiro estiverem ocupadas, indicando um empate.
bool isVitoria()

Verifica se a última peça posicionada formou uma sequência de 4 peças iguais na horizontal, vertical ou diagonal.
Utiliza um conjunto de direções predefinidas para checar conexões consecutivas.
void printaTabuleiro() const

Chama a função de exibição da classe base JogoTabuleiro.
Modelagem e Decisões de Implementação
A lógica de detecção de vitória percorre o tabuleiro verificando padrões em diferentes direções. A abordagem baseada em uma matriz de char facilita a manipulação do estado do jogo. Além disso, a implementação de isEmpate() evita verificações desnecessárias ao interromper o jogo assim que o tabuleiro estiver cheio.
Reversi
A classe Reversi implementa o jogo de tabuleiro Reversi (ou Othello), sendo derivada da classe base JogoTabuleiro. Ela sobrescreve métodos essenciais para gerenciar jogadas, validar movimentos e determinar o fim do jogo.

Atributos
A classe não define novos atributos além dos já herdados de JogoTabuleiro, pois a lógica do jogo é implementada por métodos específicos.

Métodos
Reversi(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)

Construtor que inicializa o tabuleiro com o tamanho adequado e posiciona as peças iniciais do jogo.
void leJogada(char linha, int coluna) override

Processa uma jogada no tabuleiro e alterna o jogador da vez.
Caso a jogada seja válida, chama virarPecas() para capturar peças do adversário.
bool isJogadaValida(char linha, int coluna) override

Verifica se um movimento é permitido, garantindo que existam peças do oponente para serem viradas em pelo menos uma direção.
void printaTabuleiro() const override

Exibe o estado atual do tabuleiro no console.
bool isVitoria() override

Verifica se há um vencedor com base no número de peças de cada jogador ao final do jogo.
bool isEmpate() const override

Retorna true se nenhum dos jogadores puder realizar uma jogada válida.
void virarPecas(char linha, int coluna)

Realiza a inversão das peças capturadas após uma jogada válida.
Percorre as oito direções possíveis e inverte as peças do adversário.
bool verificaDirecao(int x, int y, int dx, int dy, char pecaAtual)

Verifica se uma jogada é válida em uma direção específica, identificando se há peças do oponente a serem capturadas.
Modelagem e Decisões de Implementação
A lógica do jogo segue a estrutura definida pela classe base JogoTabuleiro, garantindo reutilização de código e flexibilidade na implementação das regras específicas do Reversi. O método verificaDirecao() auxilia na validação das jogadas, enquanto virarPecas() implementa a mecânica principal do jogo.                                                                                    A implementação da classe dita as regras do jogo de tabuleiro Reversi (ou Othello) e herda de JogoTabuleiro. Ela gerencia jogadas, valida movimentos e determina as condições de vitória e empate.

Atributos
A classe não declara novos atributos explícitos, pois reutiliza os atributos herdados de JogoTabuleiro.

Métodos
Reversi(std::shared_ptr<Jogador> jogador1, std::shared_ptr<Jogador> jogador2, int n)

Construtor que inicializa o tabuleiro com um tamanho fixo de 8x8 e posiciona as peças iniciais no centro.
void leJogada(char linha, int coluna) override

Registra uma jogada no tabuleiro se for válida.
Chama virarPecas() para inverter as peças capturadas.
Alterna o jogador da vez.
bool isJogadaValida(char linha, int coluna) override

Verifica se a jogada está dentro das regras do jogo.
Confirma se há pelo menos uma direção onde peças do adversário podem ser capturadas.
void printaTabuleiro() const override

Exibe o estado atual do tabuleiro.
bool isVitoria() override

Conta quantas peças existem de cada jogador.
O jogo termina se um jogador não tiver mais peças ou se o tabuleiro estiver completamente preenchido.
bool isEmpate() const override

Retorna true se não houver mais espaços disponíveis para jogadas.
void virarPecas(char linha, int coluna)

Percorre todas as direções e inverte as peças do oponente conforme as regras do jogo.
bool verificaDirecao(int x, int y, int dx, int dy, char pecaAtual)

Verifica se uma direção contém peças do oponente seguidas por uma peça do jogador atual.
Modelagem e Decisões de Implementação
A implementação mantém a lógica do Reversi fiel às regras oficiais, garantindo que cada jogada valide a captura de peças adversárias antes de ser registrada. A estrutura modular separa a validação, inversão e finalização do jogo, tornando o código mais organizado e reutilizável.
