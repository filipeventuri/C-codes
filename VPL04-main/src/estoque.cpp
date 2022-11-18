#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"
#include <iostream>
#include <vector>

Estoque::Estoque()=default;

void Estoque::armazena_geladeira(int capacidade, int portas){
  geladeiras.push_back(geladeira(capacidade, portas));
  x++;
  
  }

void Estoque::vende_geladeira(int capacidade, int portas){
  for(int i=0; i < x ;i++){
    if(capacidade==geladeiras[i].getCapacidade() && portas==geladeiras[i].getPortas()){
      geladeiras.erase(geladeiras.begin()+i);
      x--;
    }
  }
}

void Estoque::armazena_fogao(int queimadores, int capacidade){
  fogaos.push_back(fogao(queimadores,capacidade));
  y++;
}

void Estoque::vende_fogao(int queimadores, int capacidade){
  for(int i=0; i < y; i++){
    if(queimadores==fogaos[i].getQueimadores() && capacidade==fogaos[i].getCapacidade()){
      fogaos.erase(fogaos.begin()+i);
      y--;
    }  
  }
}

void Estoque::exibe_geladeiras(){
  for(int i=0; i < x;i++){
    std::cout << "G " << geladeiras[i].getCapacidade() << " ";
    std::cout << geladeiras[i].getPortas() << std::endl;
  }
  }

void Estoque::exibe_fogoes(){
  for (int i = 0; i < y; i++) {
    std::cout << "F " << fogaos[i].getQueimadores() << " ";
    std::cout << fogaos[i].getCapacidade() << std::endl;
  }
}

int Estoque::quantidade_geladeiras(){
  return geladeiras.size();
}

int Estoque::quantidade_fogoes(){
  return fogaos.size();
}
