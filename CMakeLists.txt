cmake_minimum_required(VERSION 3.5)
project(Snaze VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "Snaze", adiciona neste executável os arquivos src/Snaze.cpp src/SnakeGame.cpp src/Level.cpp src/PLayer.cpp
add_executable( Snaze
                src/Snaze.cpp
                src/SnakeGame.cpp 
                src/Level.cpp 
                src/Player.cpp
)

# The end
