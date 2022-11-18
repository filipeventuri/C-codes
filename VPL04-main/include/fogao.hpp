#ifndef FOGAO_HPP
#define FOGAO_HPP



class fogao {
    private:
    int queimadores;
    int capacidade;

    public:
    fogao(int _queimadores, int _capacidade);
    int getQueimadores();
    int getCapacidade();
};

#endif