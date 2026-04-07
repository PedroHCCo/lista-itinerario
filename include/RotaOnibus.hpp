#ifndef ROTAONIBUS_HPP
#define ROTAONIBUS_HPP

#include <string>

struct Parada {
    std::string nome;
    Parada* proximo;
    Parada* anterior;
    
    Parada(std::string n);
};

class RotaOnibus {
private:
    Parada* cabeca;
    Parada* cauda;
    int total;

public:
    RotaOnibus();
    ~RotaOnibus();
    void inserirInicio(std::string nome);
    void inserirFim(std::string nome);
    void inserirPorPosicao(std::string nome, int posicao);
    void removerPrimeira();
    void removerUltima();
    void buscarPorNome(std::string busca);
    void listarIda();
    void listarVolta();
    void mostrarTotal();
};

#endif
