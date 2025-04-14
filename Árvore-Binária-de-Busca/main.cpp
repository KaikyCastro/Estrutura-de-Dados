#include <iostream>
#include "ArvoreBinariadeBusca.h"

using namespace std;

int main() {
    ArvoreBinariadeBusca arvore;
    Aluno aluno1(123, "João");
    Aluno aluno2(456, "Maria");
    Aluno aluno3(789, "Pedro");

    arvore.inserir(aluno1);
    arvore.inserir(aluno2);
    arvore.inserir(aluno3);

    cout << "Imprimindo em ordem:" << endl;
    arvore.imprimirEmOrdem(arvore.obterRaiz());

    cout << "Imprimindo pré-ordem:" << endl;
    arvore.imprimirPreOrdem(arvore.obterRaiz());

    cout << "Imprimindo pós-ordem:" << endl;
    arvore.imprimirPosOrdem(arvore.obterRaiz());

    return 0;
}