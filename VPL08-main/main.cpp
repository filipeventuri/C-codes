#include <iostream>

class Conta {
	
protected:
	
float _saldo;

public:
	
virtual void Sacar(float valor) {
  if(valor > _saldo) {
    std::cout <<"Saldo insuficiente"<<std::endl;
    }
  else {
    _saldo -= valor;
  }
}

virtual void DepositarEmConta(float valor){
  _saldo += valor;
}
float get_saldo() const{
  return _saldo;
}
void set_saldo(float saldo) {
  _saldo = saldo;
  
}

float mostrarSaldo(){
	std::cout<<_saldo;
}

};

class Poupanca : public Conta {
	
private:
	
float _rendimento;

public:
	
float get_rendimento() const{
  return _rendimento;
}

void set_rendimento(float rendimento) {
  _rendimento = rendimento;
  
}

float CalculaRendimento(){
   return (_saldo * _rendimento);
}
};

class ContaCorrente : public Conta {
	
private:
	
float taxa_cobrada_saque;
float taxa_cobrada_deposito;

public:
	
float get_taxa_saque() const{
  return taxa_cobrada_saque;
}

void set_taxa_saque(float taxa_saque) {
  taxa_cobrada_saque = taxa_saque;
  
}

float get_taxa_deposito() const{
  return taxa_cobrada_deposito;
}
void set_taxa_deposito(float taxa_deposito) {
  taxa_cobrada_deposito = taxa_deposito;
  
}

void Sacar(float valor) override{
	
  if(valor > _saldo) {
    std::cout <<"Saldo insuficiente";
      
    }
  else {
    _saldo = _saldo - valor - taxa_cobrada_saque;
    
  }
}
void DepositarEmConta(float valor) override {
  _saldo = _saldo + valor - taxa_cobrada_deposito;
}

};

int main(){
	
	//linhas abaixo feitas para teste
	ContaCorrente* eu = new ContaCorrente();
	eu->set_taxa_deposito(10);
	eu->set_taxa_saque(50);
	eu->DepositarEmConta(1000);
	eu->mostrarSaldo();
	
	return 0;
}
