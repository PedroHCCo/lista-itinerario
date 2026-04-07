#include <iostream>
#include <string>
#include "include/RotaOnibus.hpp"

using namespace std;

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
