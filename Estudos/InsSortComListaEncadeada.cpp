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

class ListaEncadeada2 {
    private:
        No *cabeca = NULL;
        int tamanho = 0;
        void insereInicio(int dado);
        void insereFim(int dado);
        void insereMeio(int pos, int dado);
        void removeInicio();
        void removeNaLista(int pos);

    public:
        ListaEncadeada2() {
            this->cabeca = NULL;
        }
        int vazia();
        int tamanhoLista();
        void inserirElemento(int pos, int dado);
        void removerElemento(int pos);
        int obterElemento(int pos);
        void modificarElemento(int pos, int dado);
        void insertionSort();
};

void ListaEncadeada2::insereInicio(int dado) {
    No *novo = new No();
    novo->setDado(dado);
    novo->setProx(cabeca);
    cabeca = novo;
    tamanho++;
}

void ListaEncadeada2::insereFim(int dado) {
    No *novo = new No();
    novo->setDado(dado);

    if(vazia()) {
        cabeca = novo;
    } else {
        No *aux = cabeca;
        while(aux->getProx() != NULL) {
            aux = aux->getProx();
        }
        aux->setProx(novo);
    }
    tamanho++;
}

void ListaEncadeada2::insereMeio(int pos, int dado) {
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
    tamanho++;
}

void ListaEncadeada2::removeInicio() {
    No *aux = cabeca;
    cabeca = aux->getProx();
    delete aux;
    tamanho--;
}

void ListaEncadeada2::removeNaLista(int pos) {
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
    tamanho--;

}

int ListaEncadeada2::vazia() {
    if(this->cabeca == NULL) {
        return -1;
    } else {
        return 0;
    }
}

int ListaEncadeada2::tamanhoLista() {
    return this->tamanho;
}

void ListaEncadeada2::inserirElemento(int pos, int dado) {
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

void ListaEncadeada2::removerElemento(int pos) {
    if (pos <=0 || pos > this->tamanho) {
        cout << "Erro ao remover elemento" << endl;
    } else if (pos == 1) {
        removeInicio();
    } else {
        removeNaLista(pos);
    }
}

void ListaEncadeada2::modificarElemento(int pos, int dado) {
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

void ListaEncadeada2::insertionSort() {
    for(int i = 1; i < this->tamanho; i++) {
        int j = i;
        while(j > 0 && obterElemento(j) < obterElemento(j-1)) {
            int aux = obterElemento(j);
            modificarElemento(j, obterElemento(j-1));
            modificarElemento(j-1, aux);
            j--;
        }
    }

}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Obter elemento" << endl;
    cout << "4 - Modificar elemento" << endl;
    cout << "5 - Tamanho da lista" << endl;
    cout << "6 - Ordenar lista" << endl;
    cout << "7 - Sair" << endl;
    cout << "Digite a opção: ";
}

int main() {
    ListaEncadeada2 *lista = new ListaEncadeada2();
    int opcao = 0;

    while(opcao != 7) {
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
            case 4: {
                int pos, dado;
                cout << "Digite a posição: ";
                cin >> pos;
                cout << "Digite o dado: ";
                cin >> dado;
                lista->modificarElemento(pos, dado);
                break;
            }
            case 5: {
                cout << "Tamanho da lista: " << lista->tamanhoLista() << endl;
                break;
            }
            case 6: {
                lista->insertionSort();
                break;
            }
        }
    }

    return 0;
}