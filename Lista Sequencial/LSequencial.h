#ifndef LSEQUENCIAL_H
#define LSEQUENCIAL_H
#include <iostream>

class listaSequencial{
    private:
        int lista[100];
        int tamanhoAtual;
        int tamanhoMaximo;

    public:
        listaSequencial();
        ~listaSequencial();
        bool listaVazia();
        bool listaCheia();
        int tamanhoLista();
        int elementoLista(int posicao);
        void modificarElemento(int posicao, int valor);
        void inserirElemento(int posicao, int valor);
        int removerElemento(int posicao);
};

listaSequencial::listaSequencial(){
    tamanhoAtual = 0;
    tamanhoMaximo = 100;
}

listaSequencial::~listaSequencial(){
    tamanhoAtual = 0;
    tamanhoMaximo = 0;
}

bool listaSequencial::listaVazia(){
    if (tamanhoAtual == 0){
        return true;
    }
    else{
        return false;
    }
}

bool listaSequencial::listaCheia(){
    if (tamanhoAtual == tamanhoMaximo){
        return true;
    }
    else{
        return false;
    }
}

int listaSequencial::tamanhoLista(){
    return tamanhoAtual;
}

int listaSequencial::elementoLista(int posicao){
    if (posicao >= 0 && posicao <= tamanhoAtual){
        return lista[posicao];
    }
    else{
        return -1;
    }
}

void listaSequencial::modificarElemento(int posicao, int valor){
    if (posicao >= 0 && posicao <= tamanhoAtual){
        lista[posicao] = valor;
    }
}

void listaSequencial::inserirElemento(int posicao, int valor){
    if (posicao >= 0 && posicao <= tamanhoAtual){
        if (tamanhoAtual < tamanhoMaximo){
            for (int i = tamanhoAtual; i >= posicao; i--){
                lista[(i+1)] = lista[i];
            }
            lista[(posicao+1)] = valor;
            tamanhoAtual++;
        }
    }
}

int listaSequencial::removerElemento(int posicao){
    if (posicao >= 0 && posicao <= tamanhoAtual){
        int valor = lista[posicao];
        for (int i = posicao; i < tamanhoAtual; i++){
            lista[i] = lista[(i+1)];
        }
        tamanhoAtual--;
        return valor;
    }
    else{
        return -1;
    }
}

void setListaVazia(){
    
}


#endif