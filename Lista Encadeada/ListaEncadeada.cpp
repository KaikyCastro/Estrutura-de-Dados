#include "ListaEncadeada.h"

void hud() {
    std::cout << "1 - Verificar se a lista esta vazia" << std::endl;
    std::cout << "2 - Obter tamanho da lista" << std::endl;
    std::cout << "3 - Obter elemento de uma determinada posicao" << std::endl;
    std::cout << "4 - Modificar elemento de uma determinada posicao" << std::endl;
    std::cout << "5 - Inserir elemento" << std::endl;
    std::cout << "6 - Remover elemento" << std::endl;
    std::cout << "7 - Imprimir lista" << std::endl;
    std::cout << "8 - Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    listaEncadeada lista;
    int opcao;


    while(opcao != 8) {
        hud();
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                if (lista.vazia()) {
                    std::cout << "A lista esta vazia\n" << std::endl;
                } else {
                    std::cout << "A lista nao esta vazia\n" << std::endl;
                }
                break;
            case 2:
                std::cout << "Tamanho da lista: " << lista.getTamanho() << "\n" << std::endl;
                break;
            case 3:
                std::cout << "Digite a posicao: ";
                int pos;
                std::cin >> pos;
                std::cout << "Elemento da posicao " << pos << ": " << lista.obterValor(pos) << "\n"<< std::endl;
                break;
            case 4:
                std::cout << "Digite a posicao: ";
                int posicao;
                std::cin >> posicao;
                std::cout << "Digite o valor: ";
                int valor;
                std::cin >> valor;
                if (lista.modificarValor(posicao, valor)) {
                    std::cout << "Elemento modificado com sucesso\n" << std::endl;
                } else {
                    std::cout << "Erro ao modificar elemento\n" << std::endl;
                }
                break;
            case 5:
                std::cout << "Digite a posicao: ";
                int posicaoInserir;
                std::cin >> posicaoInserir;
                std::cout << "Digite o valor: ";
                int valorInserir;
                std::cin >> valorInserir;
                if (lista.inserirElemento(posicaoInserir, valorInserir)) {
                    std::cout << "Elemento inserido com sucesso\n" << std::endl;
                } else {
                    std::cout << "Erro ao inserir elemento\n" << std::endl;
                }
                break;
            case 6:
                std::cout << "Digite a posicao: ";
                int posicaoRemover;
                std::cin >> posicaoRemover;
                if (lista.retirarElemento(posicaoRemover)) {
                    std::cout << "Elemento removido com sucesso\n" << std::endl;
                } else {
                    std::cout << "Erro ao remover elemento\n" << std::endl;
                }
                break;
            case 7:
                lista.imprimirLista();
                break;
            case 8:
                std::cout << "Saindo...\n" << std::endl;
                break;
            default:
                std::cout << "Opcao invalida\n" << std::endl;
                break;
            
        }
        


    }
    return 0;
}