#include <iostream>
#include "ArvoreBinariadeBusca.h"

using namespace std;

int main(){
    ArvoreBinariadeBusca Arvorealunos;
    int opcao, ra, imp;
    string nome;
    bool busca = false;

    do{
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir a arvore!\n";
        cin >> opcao;

        if (opcao == 1){
            cout << "Digite o nome do aluno:\n";
            cin >> nome;
            cout << "Digite o RA do aluno:\n";
            cin >> ra;
            Aluno aluno(ra, nome);
        if (Arvorealunos.estaCheia()){
            cout << "A Árvore esta cheia!\n";
            cout << "Nao foi possivel inserir o elemento!\n";
        } else{            
            Arvorealunos.inserir(aluno);
        }
        } else if (opcao == 2){
            cout << "Digite o RA do aluno a ser removido!\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            Arvorealunos.remover(aluno);
        } else if (opcao == 3){
            cout << "Digite o RA do aluno a ser buscado!\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            Arvorealunos.buscar(aluno, busca);
            if (busca){
                cout << "Elemento encontrado!\n";
                cout << "Nome: " << aluno.getNome() << endl;
                cout << "RA: " << aluno.getMatricula() << endl;
            } else{
                cout << "Elemento nao encontrado!\n";
            }           
        } else if (opcao == 4){
            cout << "Digite 1 para fazer a impressao em pre ordem!\n";
            cout << "Digite 2 para fazer a impressao em ordem!\n";
            cout << "Digite 3 para fazer a impressao em pos ordem!\n";
            cin >> imp;
            if (imp == 1){
                Arvorealunos.imprimirPreOrdem(Arvorealunos.obterRaiz());
            } else if (imp == 2){
                Arvorealunos.imprimirEmOrdem(Arvorealunos.obterRaiz());
            } else{
                Arvorealunos.imprimirPosOrdem(Arvorealunos.obterRaiz());
            }                   
        }
    } while (opcao != 0);

    return 0;
}