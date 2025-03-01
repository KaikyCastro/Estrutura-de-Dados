#include <iostream>

using namespace std;

class ListaSeq {
    private:
        int tamMax = 0;  // tamanho máximo da lista
        int tamAtual = 0; // tamanho atual da lista
        int *lista; // ponteiro para o vetor que armazena os elementos da lista
    public:
        ListaSeq() {
            this->tamMax = 100;
            this->lista = new int[this->tamMax];
        }
        int vazia();
        int cheia();
        int tamanhoLista();
        int obterElemento(int pos);
        int modificarElemento(int pos, int dado);
        int inserirElemento(int pos, int dado);
        int removerElemento(int pos);
};

int ListaSeq::vazia() {
    if (this->tamAtual == 0) {
        return -1;
    } else {
        return 0;
    }
}

int ListaSeq::cheia() {
    if (this->tamAtual == this->tamMax) {
        return -1;
    } else {
        return 0;
    }
}

int ListaSeq::tamanhoLista() {
    return this->tamAtual;
}

int ListaSeq::obterElemento(int pos) {
    if(vazia() || pos <=0 || pos > (this->tamAtual+1)) {
        return -1;
    } else {
        return this->lista[pos-1];
    }
}

int ListaSeq::modificarElemento(int pos, int dado) {
    if(vazia() || pos <=0 || pos > (this->tamAtual+1)) {
        return -1;
    } else {
        this->lista[pos-1] = dado;
        return 0;
    }
}

int ListaSeq::inserirElemento(int pos, int dado) {
    if(cheia() || pos <=0 || pos > this->tamAtual+1) {
        return -1;
    } else {
        for (int i = tamAtual; i >= pos; i--) {
            this->lista[i] = this->lista[i-1];
        }
        this->lista[pos-1] = dado;
        this->tamAtual++;
        return 0;
    }        
}

int ListaSeq::removerElemento(int pos) {
    if(vazia() || pos <=0 || pos > this->tamAtual) {
        return -1;
    } else {
        for(int i = pos-1; i < this->tamAtual; i++) {
            this->lista[i] = this->lista[i+1];
        }
    }
    this->tamAtual--;
    return 0;

}
void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Modificar elemento" << endl;
    cout << "4 - Obter elemento" << endl;
    cout << "5 - Tamanho da lista" << endl;
    cout << "6 - Esta vazia?" << endl;
    cout << "7 - Esta cheia?" << endl;
    cout << "8 - Sair" << endl;
    cout << "Digite a opção desejada: ";
}

int main() {
    ListaSeq *lista = new ListaSeq();
    int opcao = 0;

    while(opcao != 8) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int pos, dado;
                cout << "Digite a posição: ";
                cin >> pos;
                cout << "Digite o dado: ";
                cin >> dado;
                if(lista->inserirElemento(pos, dado) == -1) {
                    cout << "Erro ao inserir elemento" << endl;
                } else {
                    cout << "Elemento inserido com sucesso" << endl;
                }
                break;
            }
            case 2: {
                int pos;
                cout << "Digite a posição: ";
                cin >> pos;
                if(lista->removerElemento(pos) == -1) {
                    cout << "Erro ao remover elemento" << endl;
                } else {
                    cout << "Elemento removido com sucesso" << endl;
                }
                break;
            }
            case 3: {
                int pos, dado;
                cout << "Digite a posição: ";
                cin >> pos;
                cout << "Digite o dado: ";
                cin >> dado;
                if(lista->modificarElemento(pos, dado) == -1) {
                    cout << "Erro ao modificar elemento" << endl;
                } else {
                    cout << "Elemento modificado com sucesso" << endl;
                }
                break;
            }
            case 4: {
                int pos;
                cout << "Digite a posição: ";
                cin >> pos;
                int dado = lista->obterElemento(pos);
                if(dado == -1) {
                    cout << "Erro ao obter elemento" << endl;
                } else {
                    cout << "Elemento obtido: " << dado << endl;
                }
                break;
            }
            case 5: {
                cout << "Tamanho da lista: " << lista->tamanhoLista() << endl;
                break;
            }
            case 6: {
                if(lista->vazia() == -1) {
                    cout << "A lista está vazia" << endl;
                } else {
                    cout << "A lista não está vazia" << endl;
                }
                break;
            }
            case 7: {
                if(lista->cheia() == -1) {
                    cout << "A lista está cheia" << endl;
                } else {
                    cout << "A lista não está cheia" << endl;
                }
                break;
            }
            case 8: {
                cout << "Saindo..." << endl;
                break;
            
            }
        }
    }
    delete lista;
    return 0;
}