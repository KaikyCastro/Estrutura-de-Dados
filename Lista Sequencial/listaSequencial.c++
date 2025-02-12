#include "LSequencial.h"

void hud() {

    std::cout << "Escolha uma opcao: " << std::endl;
    std::cout << "1 - Criar lista" << std::endl;
    std::cout << "2 - Verificar se a lista esta vazia" << std::endl;
    std::cout << "3 - Verificar se a lista esta cheia" << std::endl;
    std::cout << "4 - Verificar o tamanho da lista" << std::endl;
    std::cout << "5 - Obter um elemento da lista" << std::endl;
    std::cout << "6 - Modificar um elemento da lista" << std::endl;
    std::cout << "7 - Inserir um elemento na lista" << std::endl;
    std::cout << "8 - Remover um elemento da lista" << std::endl;
    std::cout << "9 - Sair" << std::endl;

}


int main(){

    listaSequencial lista;
    int opcao = 0, posicao = 0, valor = 0;

    hud();
    std::cin >> opcao;

    while(opcao != 9){

        if(opcao == 9) {
            break;
        }
        switch(opcao){
            case 1:
                lista = listaSequencial();
                break;
            case 2:
                if (lista.listaVazia()){
                    std::cout << "A lista esta vazia" << std::endl;
                }
                else{
                    std::cout << "A lista não esta vazia" << std::endl;
                }
                break;
            case 3:
                if (lista.listaCheia()){
                    std::cout << "A lista esta cheia" << std::endl;
                }
                else{
                    std::cout << "A lista não esta cheia" << std::endl;
                }
                break;
            case 4:
                std::cout << "O tamanho da lista e: " << lista.tamanhoLista() << std::endl;
                break;
            case 5:
                std::cout << "Digite a posicao do elemento que deseja obter: " << std::endl;
                std::cin >> posicao;
                std::cout << "O elemento da posicao " << posicao << " e: " << lista.elementoLista(posicao) << std::endl;
                break;
            case 6:
                std::cout << "Digite a posicao do elemento que deseja modificar: " << std::endl;
                std::cin >> posicao;
                std::cout << "Digite o valor que deseja atribuir ao elemento: " << std::endl;
                std::cin >> valor;
                lista.modificarElemento(posicao, valor);
                break;
            case 7:
                std::cout << "Digite a posicao em que deseja inserir o elemento: " << std::endl;
                std::cin >> posicao;
                std::cout << "Digite o valor que deseja inserir: " << std::endl;
                std::cin >> valor;
                lista.inserirElemento(posicao, valor);
                break;
            case 8:
                std::cout << "Digite a posicao do elemento que deseja remover: " << std::endl;
                std::cin >> posicao;
                std::cout << "O elemento removido foi: " << lista.removerElemento(posicao) << std::endl;
                break;
            default:
                std::cout << "Opção invalida" << std::endl;
                break;
        }

    }
    return 0;
}