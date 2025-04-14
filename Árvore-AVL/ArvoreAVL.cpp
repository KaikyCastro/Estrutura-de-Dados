#include <iostream>
#include <string>
#include <cstdlib>
#include "ArvoreAVL.h"
using namespace std;

ArvoreAVL::ArvoreAVL() {
    raiz = NULL;
}

ArvoreAVL::~ArvoreAVL() {
    deletarArvore(raiz);
}

void ArvoreAVL:: deletarArvore(No* noAtual) {
    if (noAtual != NULL) {
        //Primeiro deleta o filho a esquerda
        deletarArvore(noAtual->filhoesquerda);
        
        //Depois deleta o filho a direita
        deletarArvore(noAtual->filhodireita);
        
        //Por último deleta o nó atual
        delete noAtual;
    }
}

No* ArvoreAVL::obterRaiz() {
    return raiz;
}

bool ArvoreAVL::estaVazia() {
    return (raiz == NULL);
}

bool ArvoreAVL::estaCheia() {
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

void ArvoreAVL::inserir(Aluno aluno) {

    bool cresceu;
    insercaoRecursiva(raiz, aluno, cresceu);

}

void ArvoreAVL::insercaoRecursiva(No*& noAtual, Aluno aluno, bool& cresceu) {
    if (noAtual == NULL) {
        noAtual = new No;
        noAtual->aluno = aluno;
        noAtual->filhoesquerda = NULL;
        noAtual->filhodireita = NULL;
        noAtual->fatorBalanceamento = 0;
        cresceu = true;
        return;
    }
    if (aluno.getMatricula() < noAtual->aluno.getMatricula()) {
        insercaoRecursiva(noAtual->filhoesquerda, aluno, cresceu);
        if (cresceu) {
            noAtual->fatorBalanceamento -= 1;
        }
    } else {
        insercaoRecursiva(noAtual->filhodireita, aluno, cresceu);
        if (cresceu) {
            noAtual->fatorBalanceamento += 1;
        }
    }
    realizaRotacao(noAtual);

    if (cresceu && noAtual->fatorBalanceamento == 0) {
        cresceu = false;
    }
}


void ArvoreAVL::remover(Aluno aluno) {
    //Deleta o nó que contém o aluno
    bool diminuiu;
    removerBusca(aluno, raiz, diminuiu);
}

void ArvoreAVL::removerBusca(Aluno aluno, No* noAtual, bool& diminuiu) {

    //Para deletar um nó, precisa-se primeiro achar o nó que contém o aluno, para isso usa a função removerBusca
    //Esta é uma função recursiva que percorre a árvore, comparando a matricula do aluno com a matricula do nó atual
    if (aluno.getMatricula() < noAtual->aluno.getMatricula()) {
        //Se o a matrícula do nó atual for menor que a do aluno, então chama novamete a função para ir pra esquerda
        removerBusca(aluno, noAtual->filhoesquerda, diminuiu);
        if (diminuiu) {
            noAtual->fatorBalanceamento += 1;
        }
    } else if (aluno.getMatricula() > noAtual->aluno.getMatricula()) {
        //Se o a matrícula do nó atual for maior que a do aluno, então chama novamete a função para ir pra direita
        removerBusca(aluno, noAtual->filhodireita, diminuiu);
        if (diminuiu) {
            noAtual->fatorBalanceamento -= 1;
        }
    } else {
        //Se não for pra esquerda nem pra direita, então achou o nó que contém o aluno buscado
        //Então chama a função para deletar o nó
        removerNo(noAtual, diminuiu);
    }

    if (noAtual != NULL) {
        realizaRotacao(noAtual);
        if (diminuiu && noAtual->fatorBalanceamento == 0) {
            diminuiu = false;
        }
    }
}



void ArvoreAVL::removerNo(No*& noAtual, bool& diminuiu) {
    No* temp = noAtual;

    //Existem 3 possíveis casos de remoção de um nó:
    //1- O nó atual não tem filhos (é uma folha)
    //2- O nó atual tem apenas um filho (esquerdo ou direito)
    //3- O nó atual tem dois filhos
    if (noAtual->filhoesquerda == NULL) {
        //Se o nó atual não tem filhos, então apenas deleta o nó atual
        //Se o nó atual tem apenas um filho, então ele pega o ponteiro atual e aponta para o filho e deleta o nó temporario
        noAtual = noAtual->filhodireita;
        diminuiu = true;
        delete temp;
    } else if (noAtual->filhodireita == NULL) {
        //Se o nó atual não tem filhos, então apenas deleta o nó atual
        //Se o nó atual tem apenas um filho, então ele pega o ponteiro atual e aponta para o filho e deleta o nó temporario
        noAtual = noAtual->filhoesquerda;
        diminuiu = true;
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
        removerBusca(alunoSucessor, noAtual->filhodireita, diminuiu);
        if (diminuiu) {
            noAtual->fatorBalanceamento -= 1;
        }
    }   
}

void ArvoreAVL::obterSucessor(Aluno& alunoSucessor, No* temp) {
    //Devido a escolha do método de busca do sucessor, então o primeiro passo é pra direita e o resto é pra esquerda até chegar no NULL
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL) {
        temp = temp->filhoesquerda;
    }

    //Quando chegar no NULL, então o nó temporário é o sucessor
    //Então o aluno sucessor é atribuído ao nó temporário
    alunoSucessor = temp->aluno;
}

void ArvoreAVL::buscar(Aluno& aluno, bool& encontrado) {


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

void ArvoreAVL::imprimirEmOrdem(No* noAtual) {
    if (noAtual != NULL) {
        //Primeiro imprime o filho a esquerda
        imprimirEmOrdem(noAtual->filhoesquerda);
        
        //Depois imprime o nó atual
        cout << noAtual->aluno.getNome() << ": " << noAtual->aluno.getMatricula() << endl;
        
        //Por último imprime o filho a direita
        imprimirEmOrdem(noAtual->filhodireita);
    }
}

void ArvoreAVL::imprimirPreOrdem(No* noAtual) {
    if (noAtual != NULL) {
        //Primeiro imprime o nó atual
        cout << noAtual->aluno.getNome() << ": " << noAtual->aluno.getMatricula() << endl;
        
        //Depois imprime o filho a esquerda
        imprimirPreOrdem(noAtual->filhoesquerda);
        
        //Por último imprime o filho a direita
        imprimirPreOrdem(noAtual->filhodireita);
    }
}

void ArvoreAVL::imprimirPosOrdem(No* noAtual) {
    if (noAtual != NULL) {
        //Primeiro imprime o filho a esquerda
        imprimirPosOrdem(noAtual->filhoesquerda);
        
        //Depois imprime o filho a direita
        imprimirPosOrdem(noAtual->filhodireita);
        
        //Por último imprime o nó atual
        cout << noAtual->aluno.getNome() << ": " << noAtual->aluno.getMatricula() << endl;
    }
    
}

void ArvoreAVL::rotacionarDireita(No*& pai) {
    No* novoPai = pai->filhoesquerda;
    pai->filhoesquerda = novoPai->filhodireita;
    novoPai->filhodireita = pai;
    pai = novoPai;
}

void ArvoreAVL::rotacionarEsquerda(No*& pai) {
    No* novoPai = pai->filhodireita;
    pai->filhodireita = novoPai->filhoesquerda;
    novoPai->filhoesquerda = pai;
    pai = novoPai;
}

void ArvoreAVL::rotacionarEsquerdaDireita(No*& pai) {
    No* filho = pai->filhoesquerda;
    rotacionarEsquerda(filho);
    pai->filhoesquerda = filho;
    rotacionarDireita(pai);
}

void ArvoreAVL::rotacionarDireitaEsquerda(No*& pai) {
    No* filho = pai->filhodireita;
    rotacionarDireita(filho);
    pai->filhodireita = filho;
    rotacionarEsquerda(pai);
}

void ArvoreAVL::realizaRotacao(No*& pai) {
    No* filho;
    No* neto;

    if (pai->fatorBalanceamento =-2) {
        filho = pai->filhoesquerda;
        
        if (filho->fatorBalanceamento == -1) {
            pai->fatorBalanceamento = 0;
            filho->fatorBalanceamento = 0;
            rotacionarDireita(pai);
        } else if (filho->fatorBalanceamento == 0) {
            pai->fatorBalanceamento = -1;
            filho->fatorBalanceamento = 1;
            rotacionarDireita(pai);
        } else if (filho->fatorBalanceamento = 1) {
            neto = filho->filhodireita;
            if (neto->fatorBalanceamento == -1) {
                pai->fatorBalanceamento = 1;
                filho->fatorBalanceamento = 0;
            } else if (neto->fatorBalanceamento == 0) {
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = 0;
            } else if (neto->fatorBalanceamento == 1) {
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = -1;
            }
            neto->fatorBalanceamento = 0;
            rotacionarEsquerdaDireita(pai);

        }
    } else if (pai->fatorBalanceamento == 2){
        filho = pai->filhodireita;

        if (filho->fatorBalanceamento == -1) {
            pai->fatorBalanceamento = 0;
            filho->fatorBalanceamento = 0;
            rotacionarEsquerda(pai);
        } else if (filho->fatorBalanceamento == 0) {
            pai->fatorBalanceamento = 1;
            filho->fatorBalanceamento = -1;
            rotacionarEsquerda(pai);
        } else if (filho->fatorBalanceamento == 1) {
            neto = filho->filhoesquerda;

            if (neto->fatorBalanceamento == -1) {
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = 1;
            } else if (neto->fatorBalanceamento == 0) {
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = 0;
            } else if (neto->fatorBalanceamento == 1) {
                pai->fatorBalanceamento = -1;
                filho->fatorBalanceamento = 0;
            }
            neto->fatorBalanceamento = 0;
            rotacionarDireitaEsquerda(pai);
        }
    }

}