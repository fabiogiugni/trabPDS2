# Compilador
CXX = g++
# Flags do compilador
CXXFLAGS = -std=c++17 -Wall -Iinclude
# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data
BIN_DIR = bin
# Nome do executável
TARGET = $(BIN_DIR)/main

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Arquivos objeto
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Regra padrão: compilar tudo
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para compilar arquivos .cpp em .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(BIN_DIR)

# Rodar o programa
run: all
	./$(TARGET)

.PHONY: all clean run
