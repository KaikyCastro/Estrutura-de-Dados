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

class FilaEncadeada {
    private:
        No *inicio;
        No *fim;
        int nElementos;
    public:
        FilaEncadeada() {
            this->inicio = NULL;
            this->fim = NULL;
            this->nElementos = 0;
        }
        int vazia();
        void inserirElemento(int dado);
        int obterTamanho();
        int removerElemento();
        int obterInicio();
        int obterFim();
};

int FilaEncadeada::vazia() {
    if(this->inicio == NULL) {
        return -1;
    } else {
        return 0;
    }
}

int FilaEncadeada::obterTamanho() {
    return this->nElementos;
}

int FilaEncadeada::obterInicio() {
    if(vazia() == -1) {
        return -1;
    } else {
        return this->inicio->getDado();
    }
}

int FilaEncadeada::obterFim() {
    if(vazia() == -1) {
        return -1;
    } else {
        return this->fim->getDado();
    }
}

void FilaEncadeada::inserirElemento(int dado) {
    No *novo = new No();
    novo->setDado(dado);
    novo->setProx(NULL);

    if (vazia()) {
        this->inicio = novo;
        this->fim = novo;
    } else {
        this->fim->setProx(novo);
        this->fim = novo;
    }
    this->nElementos++;
}

int FilaEncadeada::removerElemento() {
    if(vazia() == -1) {
        return -1;
    } else {
        int valor = obterInicio();
        if(this->inicio == this->fim) {
            this->fim = NULL;
        }

        No *aux = this->inicio;
        this->inicio = aux->getProx();
        nElementos--;

        delete aux;
        return valor;
    }
}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Obter início" << endl;
    cout << "4 - Obter fim" << endl;
    cout << "5 - Sair" << endl;
    cout << "Digite a opção: ";
}

int main() {
    
    FilaEncadeada *fila = new FilaEncadeada();
    int opcao = 0;

    while(opcao != 5) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int dado;
                cout << "Digite o dado: ";
                cin >> dado;
                fila->inserirElemento(dado);
                break;
            }
            case 2: {
                int valor = fila->removerElemento();
                if(valor == -1) {
                    cout << "Erro ao remover elemento" << endl;
                } else {
                    cout << "Elemento removido: " << valor << endl;
                }
                break;
            }
            case 3: {
                int valor = fila->obterInicio();
                if(valor == -1) {
                    cout << "Erro ao obter início" << endl;
                } else {
                    cout << "Início: " << valor << endl;
                }
                break;
            }
            case 4: {
                int valor = fila->obterFim();
                if(valor == -1) {
                    cout << "Erro ao obter fim" << endl;
                } else {
                    cout << "Fim: " << valor << endl;
                }
                break;
            }
        }
    }
    
    
    return 0;
}