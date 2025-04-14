#include <iostream>
#include <string>
#include <cstdlib>
#include "Aluno.h"
using namespace std;

typedef struct {
    Aluno aluno;
    struct No* esquerda;
    struct No* direita;
} tNo;

class ArvoreBinariadeBusca {
    private:
        tNo* raiz;
    
    public:
        ArvoreBinariadeBusca();
        ~ArvoreBinariadeBusca();
        void deletarArvore(tNo* noAtual);
        tNo* obterRaiz();
        bool estaVazia();
        bool estaCheia();
        void inserir(Aluno aluno);
        void remover(Aluno aluno);
        void buscar(Aluno& aluno, bool& encontrado);
        void imprimirEmOrdem(tNo* noAtual);
        void imprimirPreOrdem(tNo* noAtual);
        void imprimirPosOrdem(tNo* noAtual);
};