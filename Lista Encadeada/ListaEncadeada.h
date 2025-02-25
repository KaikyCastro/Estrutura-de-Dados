#include <iostream>

class no {
    private:
        int valor;
        no *prox;

    public:
        no() {prox = NULL;};
        int getValor();
        void setValor(int v);
        no *getProx();
        void setProx(no *p);
};

int no::getValor() {
    return valor;
}

void no::setValor(int v) {
    valor = v;
}

no *no::getProx() {
    return prox;
}

void no::setProx(no *p) {
    prox = p;
}

class listaEncadeada {
    private: 
        no *cabeca;
        int tamanho;
    public:
        listaEncadeada() {cabeca = NULL; tamanho = 0;};
        bool vazia();
        int getTamanho();
        int obterValor (int pos);
        bool modificarValor (int pos, int valor);
        bool inserirElemento (int pos, int valor);
        bool retirarElemento(int pos);
        void imprimirLista();
        bool inserirInicio(int valor);
        bool inserirMeio(int valor, int pos);
        bool inserirFim(int valor);
        bool retirarInicio();
        bool retirarMeio(int pos);
};

bool listaEncadeada::vazia() {
    if (tamanho == 0 )
        return true;
    else
        return false;
}

int listaEncadeada::getTamanho() {
    return tamanho;
}

int listaEncadeada::obterValor (int pos) {
    int cont = 1;
    no *aux = cabeca;
    if (vazia() || pos <= 0 || pos > tamanho)
        return -1;
    
    while(cont < pos) {
        aux = aux->getProx();
        cont++;
    }
    return aux->getValor();
    delete aux;
}

bool listaEncadeada::modificarValor (int pos, int valor) {
    if (vazia() || pos <= 0 || pos > tamanho)
        return false;
    no *aux = cabeca;

    for (int i = 1; i < pos; i++)
        aux = aux->getProx();
    aux->setValor(valor);
    return true;
    delete aux;
}

bool listaEncadeada::inserirElemento (int pos, int valor) {
    if((vazia()) && (pos != 1))
        return false;

    if (pos == 1) {
        return inserirInicio(valor);
    } else if (pos == tamanho + 1) {
        return inserirFim(valor);
    } else {
        return inserirMeio(valor, pos);
    }
}

bool listaEncadeada::retirarElemento(int pos) {
    if(vazia() || pos < 1 || pos > tamanho)
        return false;

    if (pos == 1) {
        return retirarInicio();
    } else {
        return retirarMeio(pos);
    }
}

void listaEncadeada::imprimirLista() {
    no *aux = cabeca;
    if (vazia()) {
        std::cout << "Lista vazia\n";
        return;
    }
    while (aux != NULL) {
        std::cout << aux->getValor() << " ";
        aux = aux->getProx();
    }
    std::cout << std::endl;
}

bool listaEncadeada::inserirInicio(int valor) {
    no *novoNo = new no();
    novoNo->setValor(valor);
    novoNo->setProx(cabeca);
    cabeca = novoNo;
    tamanho++;
    return true;   
}

bool listaEncadeada::inserirMeio(int valor, int pos) {
    int cont = 1;
    if (pos < 1 || pos > tamanho)
        return false;

    no *novo = new no();
    novo->setValor(valor);
    
    no *aux = cabeca;
    while((cont < pos - 1) && (aux != NULL)) {
        aux = aux->getProx();
        cont++;
    }

    if (aux == NULL) return false;

    novo->setProx(aux->getProx());
    aux->setProx(novo);
    tamanho++;
    return true;
}

bool listaEncadeada::inserirFim(int valor) {
    no *novo = new no();
    novo->setValor(valor);
    novo->setProx(NULL);

    no *aux = cabeca;
    while(aux->getProx() != NULL) {
        aux = aux->getProx();
    }
    novo->setProx(aux->getProx());
    aux->setProx(novo);
    tamanho++;
    return true;
}

bool listaEncadeada::retirarInicio() {
    no *aux = cabeca;
    cabeca = aux->getProx();
    delete aux;
    tamanho--;
    return true;

}

bool listaEncadeada::retirarMeio(int pos) {
    int cont = 1;
    no *atual = NULL, *anterior = NULL;

    atual = cabeca;
    while((cont < pos) && (atual != NULL)) {
        anterior = atual;
        atual = atual->getProx();
        cont++;
    }

    if (atual == NULL) return false;

    anterior->setProx(atual->getProx());
    delete atual;
    tamanho--;
    return true;

}