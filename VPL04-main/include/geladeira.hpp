#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP


class geladeira {
    private:
    int capacidade;
    int portas;

    public:
    geladeira(int _capacidade, int _portas);
    int getCapacidade();
    int getPortas();

};

#endif