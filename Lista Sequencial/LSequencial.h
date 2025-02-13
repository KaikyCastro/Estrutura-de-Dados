#ifndef LSEQUENCIAL_H
#define LSEQUENCIAL_H
#include <iostream>

class listaSequencial{
    private:
        int lista[100] = {0};
        int tamanhoAtual;
        int tamanhoMaximo;

    public:
        listaSequencial();
        ~listaSequencial();
        bool listaVazia();
        bool listaCheia();
        int tamanhoLista();
        int elementoLista(int posicao);
        bool modificarElemento(int posicao, int valor);
        bool inserirElemento(int posicao, int valor);
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
    if((posicao > tamanhoAtual) || (posicao <= 0)){
        return -1;
    }
    else {
        return lista[posicao-1];
    }
}

bool listaSequencial::modificarElemento(int posicao, int valor){
    if((posicao > tamanhoAtual) || (posicao <= 0)){
        return false;
    }
    else {
        lista[posicao-1] = valor;
        return true;
    }
}

bool listaSequencial::inserirElemento(int posicao, int valor){
    if((tamanhoAtual == tamanhoMaximo) || (posicao <= 0) || (posicao > tamanhoAtual+1)) {
        return false;
    }
    
    for (int i = tamanhoAtual; i >= posicao; i--){
        lista[i] = lista[(i-1)];
    }
    lista[posicao - 1] = valor;
    tamanhoAtual++;
    return true;

}

int listaSequencial::removerElemento(int posicao){
    if (posicao > tamanhoAtual || posicao <= 0){
        return -1;
    }

    for (int i = (posicao-1); i < tamanhoAtual; i++){
        lista[i] = lista[i+1];
    }
    tamanhoAtual--;
    return lista[posicao-1];
}

#endif