#include <iostream>
#include <string>

using namespace std;

struct Parada {
    string nome;
    Parada* proximo;
    Parada* anterior;
    
    Parada(string n) : nome(n), proximo(nullptr), anterior(nullptr) {}
};

class RotaOnibus {
private:
    Parada* cabeca;
    Parada* cauda;
    int total;

public:
    RotaOnibus() : cabeca(nullptr), cauda(nullptr), total(0) {}

    ~RotaOnibus() {
        while (cabeca != nullptr) {
            removerPrimeira();
        }
    }

    void inserirInicio(string nome) {
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

    void inserirFim(string nome) {
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

    void inserirPorPosicao(string nome, int posicao) {
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

    void removerPrimeira() {
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

    void removerUltima() {
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

    void buscarPorNome(string busca) {
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

    void listarIda() {
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

    void listarVolta() {
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

    void mostrarTotal() {
        cout << "Total de paradas: " << total << "\n";
    }
};

int main() {
    RotaOnibus rota;
    int op;
    string nome;
    int pos;

    do {
        cout << "\n1. Inserir inicio\n2. Inserir fim\n3. Inserir por posicao\n";
        cout << "4. Remover primeira\n5. Remover ultima\n6. Buscar por nome\n";
        cout << "7. Listar ida\n8. Listar volta\n9. Contar paradas\n0. Sair\nOpcao: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1:
                getline(cin, nome);
                rota.inserirInicio(nome);
                break;
            case 2:
                getline(cin, nome);
                rota.inserirFim(nome);
                break;
            case 3:
                getline(cin, nome);
                cin >> pos;
                rota.inserirPorPosicao(nome, pos);
                break;
            case 4:
                rota.removerPrimeira();
                break;
            case 5:
                rota.removerUltima();
                break;
            case 6:
                getline(cin, nome);
                rota.buscarPorNome(nome);
                break;
            case 7:
                rota.listarIda();
                break;
            case 8:
                rota.listarVolta();
                break;
            case 9:
                rota.mostrarTotal();
                break;
            case 0:
                break;
            default:
                cout << "Invalido.\n";
        }
    } while (op != 0);

    return 0;
}
