#include <iostream>

typedef class listaSequencial{
    private:
        int lista[100];
        int tamanhoAtual;
        int tamanhoMaximo;

    public:
        listaSequencial();
        ~listaSequencial();
        void criarLista();
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

