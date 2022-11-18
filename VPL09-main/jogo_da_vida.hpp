#pragma once

#include <vector>
#include <stdexcept>
#include <string>


// Implementa o Jogo da Vida de John Conway.
// https://pt.wikipedia.org/wiki/Jogo_da_vida

class ExcecaoCelulaInvalida : public std::exception{
	private:
		
	int linha;
	int coluna;
	std::string str;
	
	public:
		
	ExcecaoCelulaInvalida(int _linha, int _coluna): linha(_linha), coluna(_coluna){

    str = "Célula (" + std::to_string(linha) + ", " + std::to_string(coluna) + ") não é válida. Deseja continuar e ignorá-la? (s/n)?";

    }
    
	const char* what() const noexcept override {
    
    return str.c_str();

  	}
		
	
	
};
class JogoDaVida {
 public:
  // Cria um jogo cujo torus tem l linhas e c colunas.
  // Todas as cÃ©lulas sÃ£o inicializadas como mortas.
  JogoDaVida(int l, int c);

  // Retorna o nÃºmero de linhas do torus.
  int linhas() {return vivas_.size();};

  // Retorna o nÃºmero de colunas do torus.
  int colunas() {return vivas_[0].size();};

  // Retorna o estado da cÃ©lula [i, j].
  bool viva(int i, int j);

  // Alteram o estado cÃ©lula [i, j].
  void Matar(int i, int j);
  void Reviver(int i, int j);

  // Executa a prÃ³xima iteraÃ§Ã£o do jogo da vida.
  void ExecutarProximaIteracao();

  // Executa n iteraÃ§Ãµes do jogo da vida.
  void Executar(int n);
 private:
  // Conta o nÃºmero de vizinhas vivas da cÃ©lula [x, y].
  int NumeroDeVizinhasVivas(int x, int y);

  // Armazena o estado das cÃ©lulas.
   std::vector<std::vector<bool> > vivas_;  
};