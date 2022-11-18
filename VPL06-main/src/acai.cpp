#include "acai.hpp"

Acai::Acai(int tamanho, std::vector<std::string>& complementos,int qtd){
 this->_tamanho=tamanho;
 this->_complementos=complementos;
 this-> _quantidade=qtd;
 }

float Acai::calcPreco(){
    
    _valor_unitario = (_tamanho*0.02) + 2.00*_complementos.size();
    return (_quantidade*_valor_unitario);
}

std::string Acai::descricao() const {
    std::string str;
    std::string str1;

for(auto i = _complementos.begin() ; *i != _complementos.back();i++){
        str1 += *i;
        str1 += ", ";
    }
    str += std::to_string(_quantidade);
    str += "X açai " ;
    str += std::to_string(_tamanho);
    str += "ml com ";
    str += str1;
    str +=_complementos.back();
    str +='.';
    str += '\n';

    return str;
    }
