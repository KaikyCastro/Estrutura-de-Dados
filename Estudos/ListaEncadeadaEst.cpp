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

class ListaEncadeada{
    private:
        No *cabeca = NULL;
        int tamanho = 0;
        void insereInicio(int dado);
        void insereFim(int dado);
        void insereMeio(int pos, int dado);
        void removeInicio();
        void removeNaLista(int pos);

    public:
        ListaEncadeada() {
            this->cabeca = NULL;
        }
        int vazia();
        int tamanhoLista();
        void inserirElemento(int pos, int dado);
        void removerElemento(int pos);
        int obterElemento(int pos);
        void modificarElemento(int pos, int dado);
};

void ListaEncadeada::insereInicio(int dado) {
    No *novo = new No();
    novo->setDado(dado);
    novo->setProx(cabeca);
    this->cabeca = novo;
    this->tamanho++;
}

void ListaEncadeada::insereMeio(int pos, int dado) {
    No *novo = new No();
    novo->setDado(dado);

    int cont = 1;

    No *aux = cabeca;
    while((cont < pos-1) && (aux != NULL)) {
        aux = aux->getProx();
        cont++;
    }

    novo->setProx(aux->getProx());
    aux->setProx(novo);
    this->tamanho++;
}

void ListaEncadeada::insereFim(int dado) {
    No *novo = new No();
    novo->setDado(dado);

    No *aux = cabeca;
    while(aux->getProx() != NULL) {
        aux = aux->getProx();
    }
    novo->setProx(NULL);
    aux->setProx(novo);
    this->tamanho++;
}

void ListaEncadeada::removeInicio() {
    No *aux = cabeca;
    cabeca = cabeca->getProx();
    delete aux;
    this->tamanho--;
}

void ListaEncadeada::removeNaLista(int pos) {
    No *atual = NULL, *Antecessor = NULL;
    int cont = 1;

    atual = cabeca;
    while((cont < pos) && (atual != NULL)) {
        Antecessor = atual;
        atual = atual->getProx();
        cont++;
    }

    Antecessor->setProx(atual->getProx());
    delete atual;
    this->tamanho--;

}
int ListaEncadeada::vazia() {
    if(this->tamanho == 0) {
        return -1;
    } else {
        return 0;
    }
}

int ListaEncadeada::tamanhoLista() {
    return this->tamanho;
}

void ListaEncadeada::inserirElemento(int pos, int dado) {
    if (pos <=0 || pos > this->tamanho+1) {
        cout << "Erro ao inserir elemento" << endl;
    } else if (pos == 1) {
        insereInicio(dado);
    } else if (pos == this->tamanho+1) {
        insereFim(dado);
    } else {
        insereMeio(pos, dado);
    }

}

void ListaEncadeada::removerElemento(int pos) {
    if (pos <=0 || pos > this->tamanho) {
        cout << "Erro ao remover elemento" << endl;
    } else if (pos == 1) {
        removeInicio();
    } else {
        removeNaLista(pos);
    }
}

int ListaEncadeada::obterElemento(int pos) {
    if(vazia() || pos <=0 || pos > this->tamanho) {
        return -1;
    } else {
        No *aux = cabeca;
        int cont = 1;

        while(cont < pos) {
            aux = aux->getProx();
            cont++;
        }
        return aux->getDado();
    }
}

void ListaEncadeada::modificarElemento(int pos, int dado) {
    if(vazia() || pos <=0 || pos > this->tamanho) {
        cout << "Erro ao modificar elemento" << endl;
    } else {
        No *aux = cabeca;
        int cont = 1;

        while((cont < pos) && (aux->getProx() != NULL)) {
            aux = aux->getProx();
            cont++;
        }
        aux->setDado(dado);
    }
}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Modificar elemento" << endl;
    cout << "4 - Obter elemento" << endl;
    cout << "5 - Tamanho da lista" << endl;
    cout << "6 - Sair" << endl;
    cout << "Digite a opção: ";
}

int main() {

    ListaEncadeada *lista = new ListaEncadeada();
    int opcao = 0;

    while(opcao != 6) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int pos, dado;
                cout << "Digite a posição: ";
                cin >> pos;
                cout << "Digite o dado: ";
                cin >> dado;
                lista->inserirElemento(pos, dado);
                break;
            }
            case 2: {
                int pos;
                cout << "Digite a posição: ";
                cin >> pos;
                lista->removerElemento(pos);
                break;
            }
            case 3: {
                int pos, dado;
                cout << "Digite a posição: ";
                cin >> pos;
                cout << "Digite o dado: ";
                cin >> dado;
                lista->modificarElemento(pos, dado);
                break;
            }
            case 4: {
                int pos;
                cout << "Digite a posição: ";
                cin >> pos;
                int dado = lista->obterElemento(pos);
                if(dado == -1) {
                    cout << "Erro ao obter elemento" << endl;
                } else {
                    cout << "Elemento obtido: " << dado << endl;
                }
                break;
            }
            case 5: {
                cout << "Tamanho da lista: " << lista->tamanhoLista() << endl;
                break;
            }
        }
    }

    delete lista;
    

    return 0;
} 