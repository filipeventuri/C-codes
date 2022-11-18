#include "geladeira.hpp"

geladeira::geladeira(int _capacidade, int _portas): capacidade(_capacidade), portas(_portas){}
int geladeira::getCapacidade(){return capacidade;}
int geladeira::getPortas(){return portas;}