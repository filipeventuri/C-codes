#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <vector>
#include <string>

class Produto {
 public:
  int getQtd() const;
  float getValor() const;
  virtual std::string descricao() const = 0;
  virtual float calcPreco() = 0;
  virtual ~Produto() = default;

 protected:
  int _quantidade;
  float _valor_unitario;
};
#endif