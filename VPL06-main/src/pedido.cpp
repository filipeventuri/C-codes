#include "pedido.hpp"

void Pedido::adicionaProduto(Produto* p){
    _produtos.push_back(p);
}

float Pedido::calculaTotal() const{
    float precoTotal = 0;
    for(auto ptr = _produtos.begin(); ptr!=_produtos.end(); ptr++){
        precoTotal += (*ptr)->calcPreco();
    }
    return precoTotal;
}

std::string Pedido::resumo() const{
std::string str;
for(auto ptr = _produtos.begin(); ptr!=_produtos.end(); ptr++){
    str+=(*ptr)->descricao();
}
str+="Endereço: "+ _endereco + '\n';
return str;
}

Pedido::~Pedido(){
    for(auto ptr = _produtos.begin(); ptr!=_produtos.end(); ptr++){
        delete *ptr;
    }
}

void Pedido::setEndereco(const std::string& endereco){
    _endereco =endereco;
}