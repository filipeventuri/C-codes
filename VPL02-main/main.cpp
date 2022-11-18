#include<iostream>

using namespace std;

class Categoria{
    int Codigo;
    double ValorCaixa;
    float Porcento;
    public:
    Categoria() = default;
    Categoria(int Codigo_Categoria, double Valor_Caixa, float Porcento_Categoria):
    Codigo(Codigo_Categoria), ValorCaixa(Valor_Caixa), Porcento(Porcento_Categoria){}
    
    int getCodigo(){
        return Codigo;
    }
    
    double getValorCaixa(){
        return ValorCaixa;
    }
    
    void adicionaCaixa(double Valor){
        ValorCaixa += Valor;
    }
    
    void gastaCaixa(double Valor){
        ValorCaixa -= Valor;
    }
    
};



class Orcamento {
    Categoria categoria[5];
    public:
    Orcamento(double impostos) {
        
        for(int i=0; i<=4;i++){
            if(i==0 || i==1 || i==4) categoria[i] = Categoria(0,(impostos*0.15),15);
            if(i==2) categoria[i] = Categoria(0,(impostos*0.20),20);
            if(i==3) categoria[i] = Categoria(0,(impostos*0.35),35);
            }
        
       
    }
    
    
    
    void gastoCategoria(int codigo_categoria, double valor) {
    categoria[codigo_categoria].gastaCaixa(valor);
    }
    
    
    double getSaldo(int codigo_categoria) {
    return categoria[codigo_categoria].getValorCaixa();
    }
    
   
    Categoria* getCategoria(int codigo_categoria) {
    return &categoria[codigo_categoria];
    }
    
   
};



int main() {
  Orcamento *orcamento;

  char test = 0;
  while(cin >> test) {
      switch (test) {
        case 'o': { 
          double valor = 0;
          cin >> valor;
          orcamento = new Orcamento(valor);
          
        }
        break;
        case 'g': { 
          int categoria = 0;
          double valor = 0;
          cin >> categoria >> valor;
          
          orcamento->gastoCategoria(categoria, valor);
          
          cout << categoria << ": " << orcamento->getSaldo(categoria) << endl;
        }
        break;
        case 'p': { 
          for (int categoria = 0; categoria < 5; categoria++) {
            cout << categoria << ": " << orcamento->getSaldo(categoria) << endl;
          }
        }
        break;
        default: {
          cout << "----------" << endl;
        } break;
      }
  }
  return 0;
}