#include "venda.hpp"
#include <iomanip>
void Venda::adicionaPedido(Pedido* p){
    _pedidos.push_back(p);
    total+= p->calculaTotal();
}

void Venda::imprimeRelatorio()const{  
int count=1;
for(auto ptr = _pedidos.begin(); ptr!=_pedidos.end(); ptr++){
    std::cout<<"Pedido "<< count << std::endl;
    std::cout<< (*ptr)->resumo();
    count++;
}

std::cout<< "Relatorio de Vendas" << std::endl;
std::cout<< "Total de vendas: R$" << std::fixed << std::setprecision(2) << total << std::endl;
std::cout<< "Total de pedidos: "<< _pedidos.size();
count=1;

}

Venda::~Venda(){
    for(auto ptr = _pedidos.begin(); ptr!=_pedidos.end(); ptr++){ delete *ptr;}
}