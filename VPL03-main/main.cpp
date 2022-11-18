#include <iostream>
#include <iterator>
#include <map>
#include <set>

using namespace std;

class Fatura {
  char tipo;
  double valor;
  string codigo;

public:
  Fatura() = default;
  Fatura(char _tipo, double _valor, string _codigo)
      : codigo(_codigo), tipo(_tipo), valor(_valor) {}

  void imprimir() const {
    cout << tipo << " " << valor << " " << codigo << endl;
  }

  double getValor() const { return this->valor; }

  char getTipo() const { return this->tipo; }
};
struct ordenar {
  bool operator()(Fatura a1, Fatura a2) {
    return a1.getValor() < a2.getValor();
  }
};

class Colecao {
  multiset<Fatura, ordenar> tudo;
  map<char, int> tipo;

public:
  Colecao() {
    tipo.insert(pair<char, int>('p', 0));
    tipo.insert(pair<char, int>('b', 0));
    tipo.insert(pair<char, int>('g', 0));
  }

  void adicionar(Fatura f) {
    tudo.insert(f);
    if (f.getTipo() == 'p')
      tipo['p']++;
    if (f.getTipo() == 'b')
      tipo['b']++;
    if (f.getTipo() == 'g')
      tipo['g']++;
  };

  void proxima() {
    if (!tudo.empty()) {
      Fatura aux = *tudo.rbegin();
      aux.imprimir();
      tudo.erase(*tudo.rbegin());
      tipo[aux.getTipo()]--;
    }
  }

  void imprimir() {
    for (auto ut = tudo.begin(); ut != tudo.end(); ut++) {
      ut->imprimir();
    }
  }

  void status() {

    for (map<char, int>::iterator it = tipo.begin(); it != tipo.end(); it++) {
      cout << it->first << " " << it->second << endl;
    }
  }
};

int main() {
  Fatura fatura;
  Colecao *tudo = new Colecao();
  char x = 0;
  while (cin >> x) {
    switch (x) {

    case 'f': {
      char tipo;
      double valor;
      string codigo;
      cin >> tipo;
      cin >> valor;
      cin >> codigo;

      Fatura fatura = Fatura(tipo, valor, codigo);
      tudo->adicionar(fatura);

    }

    break;
    case 'r': {

      tudo->proxima();

    }

    break;

    case 'p': {

      tudo->imprimir();

    }

    break;

    case 's': {
      tudo->status();
    }

    break;

    case 'e': {
      exit(0);
    }

    break;
    }
  }
}