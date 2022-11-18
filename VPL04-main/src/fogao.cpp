#include "fogao.hpp"

fogao::fogao(int _queimadores, int _capacidade): queimadores(_queimadores), capacidade(_capacidade){}
int fogao::getCapacidade(){return capacidade;}
int fogao::getQueimadores(){return queimadores;}