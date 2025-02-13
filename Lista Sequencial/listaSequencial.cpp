#include "LSequencial.h"

void hud() {

    std::cout << "Escolha uma opcao: " << std::endl;
    std::cout << "1 - Verificar se a lista esta vazia" << std::endl;
    std::cout << "2 - Verificar se a lista esta cheia" << std::endl;
    std::cout << "3 - Obter o tamanho da lista" << std::endl;
    std::cout << "4 - Obter um elemento da lista" << std::endl;
    std::cout << "5 - Modificar um elemento da lista" << std::endl;
    std::cout << "6 - Inserir um elemento na lista" << std::endl;
    std::cout << "7 - Remover um elemento da lista" << std::endl;
    std::cout << "8 - Sair" << std::endl;
}

int main(){

    listaSequencial lista = listaSequencial();
    int opcao = 0, posicao = 0, valor = 0;
    
    while(opcao != 8){
        
        hud();
        std::cin >> opcao;
        if(opcao == 8) {
            break;
        }
        switch(opcao){
            case 1:
                if (lista.listaVazia()){
                    std::cout << "A lista esta vazia\n" << std::endl;
                }
                else{
                    std::cout << "A lista não esta vazia\n" << std::endl;
                }
                break;
            case 2:
                if (lista.listaCheia()){
                    std::cout << "A lista esta cheia\n" << std::endl;
                }
                else{
                    std::cout << "A lista nao esta cheia\n" << std::endl;
                }
                break;
            case 3:
                std::cout << "O tamanho da lista e: \n" << lista.tamanhoLista() << std::endl;
                break;
            case 4:
                std::cout << "Digite a posicao do elemento que deseja obter: \n" << std::endl;
                std::cin >> posicao;
                std::cout << "O elemento da posicao " << posicao << " e: \n" << lista.elementoLista(posicao) << std::endl;
                break;
            case 5:
                std::cout << "Digite a posicao do elemento que deseja modificar: \n" << std::endl;
                std::cin >> posicao;
                std::cout << "Digite o valor que deseja atribuir ao elemento: \n" << std::endl;
                std::cin >> valor;
                lista.modificarElemento(posicao, valor);
                break;
            case 6:
                std::cout << "Digite a posicao em que deseja inserir o elemento: \n" << std::endl;
                std::cin >> posicao;
                std::cout << "Digite o valor que deseja inserir: \n" << std::endl;
                std::cin >> valor;
                lista.inserirElemento(posicao, valor);
                break;
            case 7:
                std::cout << "Digite a posicao do elemento que deseja remover: \n" << std::endl;
                std::cin >> posicao;
                std::cout << "O elemento removido foi: \n" << lista.removerElemento(posicao) << std::endl;
                break;
            default:
                std::cout << "Opcao invalida\n" << std::endl;
                break;
        }

    }
    return 0;
}
