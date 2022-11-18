#include "cachorro_quente.hpp"

CachorroQuente::CachorroQuente(int num_salsichas,
std::vector<std::string>& complementos,bool prensado,int qtd){
 this->_num_salsichas=num_salsichas;
 this->_complementos=complementos;
 this->_prensado=prensado;
 this-> _quantidade=qtd;
 }

float CachorroQuente::calcPreco(){
    _valor_unitario = 5.00 + (_num_salsichas * 1.50) + 1.00 * (_complementos.size());
    if(_prensado){ _valor_unitario += 0.50; }
    
    return (_quantidade*_valor_unitario);
}

std::string CachorroQuente:: descricao() const {


    std::string str;
    std::string str1;
    std::string str2;

    for(auto ptr = _complementos.begin(); ptr!=_complementos.end()-1; ptr++){
        str1.append(*ptr);
        str1.append(", ");
    }
    if(_prensado) str2="prensado ";
    str= std::to_string(_quantidade) + "X cachorro-quente "+ str2+ "com  "+  std::to_string(_num_salsichas)+ " salsicha(s), " + str1 +  (_complementos.back()) + "."+ '\n';
    return str;
    }
