#include <iostream>
#include <string>
#include <cstdlib>
#include "ArvoreBinariadeBusca.h"
using namespace std;

ArvoreBinariadeBusca::ArvoreBinariadeBusca() {
    raiz = NULL;
}

ArvoreBinariadeBusca::~ArvoreBinariadeBusca() {
    
}

void ArvoreBinariadeBusca:: deletarArvore(No* noAtual) {

}

No* ArvoreBinariadeBusca::obterRaiz() {
    return raiz;
}

bool ArvoreBinariadeBusca::estaVazia() {
    return (raiz == NULL);
}

bool ArvoreBinariadeBusca::estaCheia() {
    try {
        No* novoNo = new No;
        delete novoNo;
        return false; // A árvore não está cheia
    } catch (bad_alloc exception) {
        return true; // A árvore está cheia
    }
}

void ArvoreBinariadeBusca::inserir(Aluno aluno) {
    
    if(estaCheia()) {
        cout << "A árvore está cheia. Não é possível inserir o aluno." << endl;
        return;
    } else {
        No* novoNo = new No;
        novoNo->aluno = aluno;
        novoNo->filhoesquerda = NULL;
        novoNo->filhodireita = NULL;

        if (raiz == NULL) {
            raiz = novoNo;
        } else {
            No* temp = raiz;
            while(temp != NULL) {
                if (aluno.getMatricula() < temp->aluno.getMatricula()) {
                    if (temp->filhoesquerda == NULL) {
                        temp->filhoesquerda = novoNo;
                        break;
                    } else {
                        temp = temp->filhoesquerda;
                    }
                } else {
                    if (temp->filhodireita == NULL) {
                        temp->filhodireita = novoNo;
                        break;
                    } else {
                        temp = temp->filhodireita;
                    }
                }
            }
        }
    }
}

void ArvoreBinariadeBusca::remover(Aluno aluno) {

}

void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& encontrado) {

}

void ArvoreBinariadeBusca::imprimirEmOrdem(No* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPreOrdem(No* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPosOrdem(No* noAtual) {
    
}