#include "pizza.hpp"

Pizza::Pizza(const std::string& sabor,
        int pedacos,
        bool borda_recheada,
        int qtd){
 _sabor = sabor;
 _pedacos=pedacos;
 _borda_recheada=borda_recheada;
 _quantidade=qtd;
        }

float Pizza::calcPreco(){
    std::string str ("especial");
    std::size_t found = _sabor.find(str);
    
    _valor_unitario = 5.00 * (_pedacos);
    if(found!=std::string::npos){ _valor_unitario += 8.00;}
    if(_borda_recheada){ _valor_unitario += 10.00;}
    
    return (_quantidade*_valor_unitario);
}

std::string Pizza::descricao() const {
 std::string str;
 std::string str1;
 if(_borda_recheada){ str1 = " e borda recheada.";}else{str1=" sem borda recheada.";}
 str= std::to_string(_quantidade) + "X pizza " +_sabor+", "+ std::to_string(_pedacos)+" pedaços" + str1 + '\n';

return str;

}