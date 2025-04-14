#include <iostream>
#include <string>
#include <cstdlib>
#include "Aluno.h"
using namespace std;

struct No {
    Aluno aluno;
    struct No* filhoesquerda;
    struct No* filhodireita;
};

class ArvoreBinariadeBusca {
    private:
        No* raiz;
    
    public:
        ArvoreBinariadeBusca();
        ~ArvoreBinariadeBusca();
        void deletarArvore(No* noAtual);
        No* obterRaiz();
        bool estaVazia();
        bool estaCheia();
        void inserir(Aluno aluno);
        void remover(Aluno aluno);
        void removerBusca(Aluno aluno, No* noAtual);
        void removerNo(No*& noAtual);
        void obterSucessor(Aluno& aluno, No* temp);
        void buscar(Aluno& aluno, bool& encontrado);
        void imprimirEmOrdem(No* noAtual);
        void imprimirPreOrdem(No* noAtual);
        void imprimirPosOrdem(No* noAtual);
};