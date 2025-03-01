#include <iostream>

using namespace std;

class No {
    private:
        int dado;
        No *prox;
    public:
        No () {
            this->prox = NULL;
        }
        int getDado();
        void setDado(int dado);
        No* getProx();
        void setProx(No *prox);
};

int No::getDado() {
    return this->dado;
}

void No::setDado(int dado) {
    this->dado = dado;
}

No* No::getProx() {
    return this->prox;
}

void No::setProx(No *prox) {
    this->prox = prox;
}

class Pilha {
    private:
        No *topo = NULL;
        int tamanho;
    public:
        Pilha() {
            this->topo = NULL;
            tamanho = 0;
        }
        int vazia();
        void push(int dado);
        void pop();
        int obterTopo();
};

int Pilha::vazia() {
    if(this->tamanho == 0) {
        return -1;
    } else {
        return 0;
    }
}

void Pilha::push(int dado) {
    No *novo = new No();
    novo->setDado(dado);

    novo->setProx(topo); //Faz apontar pro antigo topo
    topo = novo; //Faz o novo nó ser o topo
    tamanho++;

}

void Pilha::pop() {
    if(vazia() == -1) {
        cout << "Pilha vazia" << endl;
    } else {
        No *aux = topo;
        topo = topo->getProx();
        delete aux;
        tamanho--;
    }
}

int Pilha::obterTopo() {
    if(vazia() == -1) {
        return -1;
    } else {
        return topo->getDado();
    }
}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Obter topo" << endl;
    cout << "4 - Sair" << endl;
    cout << "Digite a opção: ";
}

int main() {

    Pilha *pilha = new Pilha();
    int opcao = 0;

    while(opcao != 4) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int dado;
                cout << "Digite o dado: ";
                cin >> dado;
                pilha->push(dado);
                break;
            }
            case 2: {
                pilha->pop();
                break;
            }
            case 3: {
                int topo = pilha->obterTopo();
                if(topo == -1) {
                    cout << "Pilha vazia" << endl;
                } else {
                    cout << "Topo: " << topo << endl;
                }
                break;
            }
            case 4: {
                cout << "Saindo..." << endl;
                break;
            }
            default: {
                cout << "Opção inválida" << endl;
            }
        }
    }

    return 0;
}