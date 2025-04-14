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

void ArvoreBinariadeBusca:: deletarArvore(tNo* noAtual) {

}

tNo* ArvoreBinariadeBusca::obterRaiz() {
    return raiz;
}

bool ArvoreBinariadeBusca::estaVazia() {
    return (raiz == NULL);
}

bool ArvoreBinariadeBusca::estaCheia() {
    try {
        tNo* novoNo = new tNo;
        delete novoNo;
        return false; // A árvore não está cheia
    } catch (bad_alloc exception) {
        return true; // A árvore está cheia
    }
}

void ArvoreBinariadeBusca::inserir(Aluno aluno) {

}

void ArvoreBinariadeBusca::remover(Aluno aluno) {

}

void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& encontrado) {

}

void ArvoreBinariadeBusca::imprimirEmOrdem(tNo* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPreOrdem(tNo* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPosOrdem(tNo* noAtual) {
    
}