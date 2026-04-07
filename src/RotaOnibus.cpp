#include "../include/RotaOnibus.hpp"
#include <iostream>

using namespace std;

Parada::Parada(string n) : nome(n), proximo(nullptr), anterior(nullptr) {}

RotaOnibus::RotaOnibus() : cabeca(nullptr), cauda(nullptr), total(0) {}

RotaOnibus::~RotaOnibus() {
    while (cabeca != nullptr) {
        removerPrimeira();
    }
}

void RotaOnibus::inserirInicio(string nome) {
    Parada* novo = new Parada(nome);
    if (cabeca == nullptr) {
        cabeca = cauda = novo;
    } else {
        novo->proximo = cabeca;
        cabeca->anterior = novo;
        cabeca = novo;
    }
    total++;
    cout << "Parada inserida no inicio.\n";
}

void RotaOnibus::inserirFim(string nome) {
    Parada* novo = new Parada(nome);
    if (cauda == nullptr) {
        cabeca = cauda = novo;
    } else {
        cauda->proximo = novo;
        novo->anterior = cauda;
        cauda = novo;
    }
    total++;
    cout << "Parada inserida no fim.\n";
}

void RotaOnibus::inserirPorPosicao(string nome, int posicao) {
    if (posicao <= 1) {
        inserirInicio(nome);
        return;
    }
    if (posicao > total) {
        inserirFim(nome);
        return;
    }

    Parada* atual = cabeca;
    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    Parada* novo = new Parada(nome);
    novo->proximo = atual->proximo;
    novo->anterior = atual;
    
    atual->proximo->anterior = novo;
    atual->proximo = novo;
    
    total++;
    cout << "Parada inserida na posicao " << posicao << ".\n";
}

void RotaOnibus::removerPrimeira() {
    if (cabeca == nullptr) {
        cout << "Rota vazia.\n";
        return;
    }
    Parada* temp = cabeca;
    cabeca = cabeca->proximo;
    
    if (cabeca != nullptr) {
        cabeca->anterior = nullptr;
    } else {
        cauda = nullptr;
    }
    
    cout << "Parada removida.\n";
    delete temp;
    total--;
}

void RotaOnibus::removerUltima() {
    if (cauda == nullptr) {
        cout << "Rota vazia.\n";
        return;
    }
    Parada* temp = cauda;
    cauda = cauda->anterior;
    
    if (cauda != nullptr) {
        cauda->proximo = nullptr;
    } else {
        cabeca = nullptr;
    }
    
    cout << "Parada removida.\n";
    delete temp;
    total--;
}

void RotaOnibus::buscarPorNome(string busca) {
    if (cabeca == nullptr) {
        cout << "Rota vazia.\n";
        return;
    }
    
    Parada* atual = cabeca;
    int pos = 1;
    bool achou = false;
    
    while (atual != nullptr) {
        if (atual->nome.find(busca) != string::npos) {
            cout << "Posicao " << pos << ": " << atual->nome << "\n";
            achou = true;
        }
        atual = atual->proximo;
        pos++;
    }
    
    if (!achou) {
        cout << "Nao encontrada.\n";
    }
}

void RotaOnibus::listarIda() {
    if (cabeca == nullptr) {
        cout << "Rota vazia.\n";
        return;
    }
    Parada* atual = cabeca;
    while (atual != nullptr) {
        cout << "[" << atual->nome << "] ";
        if (atual->proximo != nullptr) cout << "-> ";
        atual = atual->proximo;
    }
    cout << "\n";
}

void RotaOnibus::listarVolta() {
    if (cauda == nullptr) {
        cout << "Rota vazia.\n";
        return;
    }
    Parada* atual = cauda;
    while (atual != nullptr) {
        cout << "[" << atual->nome << "] ";
        if (atual->anterior != nullptr) cout << "-> ";
        atual = atual->anterior;
    }
    cout << "\n";
}

void RotaOnibus::mostrarTotal() {
    cout << "Total de paradas: " << total << "\n";
}
