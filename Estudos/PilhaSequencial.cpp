#include <iostream>

using namespace std;

class Pilha {
    private:
        int topo;
        int *pilha;
        int tamanhoMax;
    public:
        Pilha() {
            this->topo = -1;
            this->tamanhoMax = 100;
            this->pilha = new int[this->tamanhoMax];
        }
        int vazia();
        int cheia();
        int tamanhoPilha();
        int obterTopo();
        int push(int dado);
        int pop();
};

int Pilha::vazia() {
    if(this->topo == -1) {
        return -1;
    } else {
        return 0;
    }
}

int Pilha::cheia() {
    if(this->topo == this->tamanhoMax-1) {
        return -1;
    } else {
        return 0;
    }
}

int Pilha::tamanhoPilha() {
    return this->topo+1;
}

int Pilha::obterTopo() {
    if(vazia() == -1) {
        return -1;
    } else {
        return this->pilha[this->topo];
    }
}

int Pilha::push(int dado) {
    if(cheia() == -1) {
        return -1;
    } else {
        this->topo++;
        this->pilha[this->topo] = dado;
        return 0;
    }
}

int Pilha::pop() {
    if (vazia() == -1) {
        return -1;
    } else {
        int valor = this->pilha[this->topo];
        this->topo--;
        return valor;
    }
}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Obter topo" << endl;
    cout << "4 - Tamanho da pilha" << endl;
    cout << "5 - Sair" << endl;
    cout << "Digite a opção desejada: ";
}

int main() {
    Pilha *pilha = new Pilha();
    int opcao = 0;

    while(opcao != 5) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int dado;
                cout << "Digite o dado: ";
                cin >> dado;
                if(pilha->push(dado) == -1) {
                    cout << "Erro ao inserir elemento" << endl;
                } else {
                    cout << "Elemento inserido com sucesso" << endl;
                }
                break;
            }
            case 2: {
                int dado = pilha->pop();
                if(dado == -1) {
                    cout << "Erro ao remover elemento" << endl;
                } else {
                    cout << "Elemento removido: " << dado << endl;
                }
                break;
            }
            case 3: {
                int topo = pilha->obterTopo();
                if(topo == -1) {
                    cout << "Erro ao obter topo" << endl;
                } else {
                    cout << "Topo: " << topo << endl;
                }
                break;
            }
            case 4: {
                cout << "Tamanho da pilha: " << pilha->tamanhoPilha() << endl;
                break;
            }
        }
    }
    return 0;
}