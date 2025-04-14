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
    // Tenta alocar memória para um novo nó
    // Se a alocação falhar, a árvore está cheia
    // Se a alocação for bem-sucedida, libera a memória e retorna falso
    try {
        No* novoNo = new No;
        delete novoNo;
        return false; // A árvore não está cheia
    } catch (bad_alloc exception) {
        return true; // A árvore está cheia
    }
}

void ArvoreBinariadeBusca::inserir(Aluno aluno) {

    // Verifica se a árvore está cheia
    if(estaCheia()) {
        //Se estiver cheia, retorna uma mensagem de erro
        cout << "A árvore está cheia. Não é possível inserir o aluno." << endl;
        return;
    } else {

        //Se não, cria um novo nó e atribui a esse nov, caracteristicas de aluno passado pela função, e inicia seus ponteiros filho como NULL
        No* novoNo = new No;
        novoNo->aluno = aluno;
        novoNo->filhoesquerda = NULL;
        novoNo->filhodireita = NULL;

        //Verifica se a raiz está vazia, se estiver, atribui o novo nó a raiz
        if (raiz == NULL) {
            raiz = novoNo;
        } else {

            //Se a raiz não estiver vazia, percorre a árvore para encontrar a posição correta para inserir o novo nó
            No* temp = raiz; //Aloca um nó temporário qque começa na raiz, para percorrer a árvore
            while(temp != NULL) {

                //Se o novo nó for menor que a matricula do aluno, então vai pra esquerda, porém tem que verificar se existe um nó la.
                //se não tiver, então atribui o novo nó a esquerda do nó temporário
                //Se tiver, então tem que percorrer pra próxima posição a esquerda
                if (aluno.getMatricula() < temp->aluno.getMatricula()) {
                    if (temp->filhoesquerda == NULL) {
                        temp->filhoesquerda = novoNo;
                        break;
                    } else {
                        temp = temp->filhoesquerda;
                    }
                } else {
                    //Se o novo nó for maior, então vai pra direita, novamente deve veriricar se existe, se não existir, basta atribuir
                    //Caso exista, então deve percorrer o filho a direita.
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
    //Deleta o nó que contém o aluno
    removerBusca(aluno, raiz);
}

void ArvoreBinariadeBusca::removerBusca(Aluno aluno, No* noAtual) {

    //Para deletar um nó, precisa-se primeiro achar o nó que contém o aluno, para isso usa a função removerBusca
    //Esta é uma função recursiva que percorre a árvore, comparando a matricula do aluno com a matricula do nó atual
    if (aluno.getMatricula() < noAtual->aluno.getMatricula()) {
        //Se o a matrícula do nó atual for menor que a do aluno, então chama novamete a função para ir pra esquerda
        removerBusca(aluno, noAtual->filhoesquerda);
    } else if (aluno.getMatricula() > noAtual->aluno.getMatricula()) {
        //Se o a matrícula do nó atual for maior que a do aluno, então chama novamete a função para ir pra direita
        removerBusca(aluno, noAtual->filhodireita);
    } else {
        //Se não for pra esquerda nem pra direita, então achou o nó que contém o aluno buscado
        //Então chama a função para deletar o nó
        removerNo(noAtual);
    }
}



void ArvoreBinariadeBusca::removerNo(No*& noAtual) {
    No* temp = noAtual;

    //Existem 3 possíveis casos de remoção de um nó:
    //1- O nó atual não tem filhos (é uma folha)
    //2- O nó atual tem apenas um filho (esquerdo ou direito)
    //3- O nó atual tem dois filhos
    if (noAtual->filhoesquerda == NULL) {
        //Se o nó atual não tem filhos, então apenas deleta o nó atual
        //Se o nó atual tem apenas um filho, então ele pega o ponteiro atual e aponta para o filho e deleta o nó temporario
        noAtual = noAtual->filhodireita;
        delete temp;
    } else if (noAtual->filhodireita == NULL) {
        //Se o nó atual não tem filhos, então apenas deleta o nó atual
        //Se o nó atual tem apenas um filho, então ele pega o ponteiro atual e aponta para o filho e deleta o nó temporario
        noAtual = noAtual->filhoesquerda;
        delete temp;
    } else {
        //Se o nó atual tem dois filhos, então precisa encontrar o sucessor do nó atual
        //O sucessor é o nó com o menor valor na subárvore direita do nó atual
        //A função obterSucessor é chamada para encontrar o sucessor
        //O sucessor é armazenado em um nó temporário
        //O nó atual é atualizado com o sucessor
        //O nó temporário é atualizado com o filho direito do nó atual
        //E a função removerBusca é chamada para remover o sucessor da subárvore direita
        Aluno alunoSucessor;
        obterSucessor(alunoSucessor, noAtual->filhodireita);
        noAtual->aluno = alunoSucessor;
        removerBusca(alunoSucessor, noAtual->filhodireita);
    }   
}

void ArvoreBinariadeBusca::obterSucessor(Aluno& alunoSucessor, No* temp) {
    //Devido a escolha do método de busca do sucessor, então o primeiro passo é pra direita e o resto é pra esquerda até chegar no NULL
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL) {
        temp = temp->filhoesquerda;
    }

    //Quando chegar no NULL, então o nó temporário é o sucessor
    //Então o aluno sucessor é atribuído ao nó temporário
    alunoSucessor = temp->aluno;
}

void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& encontrado) {


    //Encotnrado inicializa com false e cria-se um nó temporário que começa na raiz
    encontrado = false;
    No* temp = raiz;

    //Faz o nó temporário percorrer a árvore, verificando se o nó temporário é nulo
    while(temp != NULL) {

        //Se o nó temporário for menor que a matricula do aluno, então vai pra esquerda
        if (aluno.getMatricula() < temp->aluno.getMatricula()) {
            temp = temp->filhoesquerda;

        //Se o nó temporário for maior que a matricula do aluno, então vai pra direita
        } else if (aluno.getMatricula() > temp->aluno.getMatricula()) {
            temp = temp->filhodireita;

        //Se n for nenhum dos casos anteriores, então é o nó que estamos procurando
        //Então retorna-se True e o aluno recebe o nó temporário
        } else {
            encontrado = true;
            aluno = temp->aluno;
            break;
        }
    }

}

void ArvoreBinariadeBusca::imprimirEmOrdem(No* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPreOrdem(No* noAtual) {
    
}

void ArvoreBinariadeBusca::imprimirPosOrdem(No* noAtual) {
    
}