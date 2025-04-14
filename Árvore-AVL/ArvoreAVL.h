#include <iostream>
#include <string>
#include <cstdlib>
#include "Aluno.h"
using namespace std;

struct No {
    Aluno aluno;
    struct No* filhoesquerda;
    struct No* filhodireita;

    int fatorBalanceamento;
};

class ArvoreAVL {
    private:
        No* raiz;
    
    public:
        ArvoreAVL();
        ~ArvoreAVL();
        void deletarArvore(No* noAtual);
        No* obterRaiz();
        bool estaVazia();
        bool estaCheia();
        void inserir(Aluno aluno);
        void remover(Aluno aluno);
        void removerBusca(Aluno aluno, No* noAtual, bool& diminuiu);
        void removerNo(No*& noAtual, bool& diminuiu);
        void obterSucessor(Aluno& aluno, No* temp);
        void buscar(Aluno& aluno, bool& encontrado);
        void imprimirEmOrdem(No* noAtual);
        void imprimirPreOrdem(No* noAtual);
        void imprimirPosOrdem(No* noAtual);

        void rotacionarDireita(No*& pai);
        void rotacionarEsquerda(No*& pai);
        void rotacionarEsquerdaDireita(No*& pai);
        void rotacionarDireitaEsquerda(No*& pai);
        void realizaRotacao(No*& pai);
        void insercaoRecursiva(No*& noAtual, Aluno aluno, bool& cresceu);
};