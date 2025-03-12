#include <iostream>

using namespace std;

class Fila {
    private:
        int inicio;
        int fim;
        int *fila;
        int tamanhoMax;
        int nElementos;
    public:
        Fila() {
            this->inicio = 0;
            this->fim = -1;
            this->tamanhoMax = 100;
            this->nElementos = 0;
            this->fila = new int[this->tamanhoMax];
        }
        int vazia();
        int cheia();
        int tamanhoFila();
        int obterInicio();
        int obterFim();
        int inserirElemento(int dado);
        int removerElemento();
};

int Fila::vazia() {
    if(this->fim < this->inicio) {
        return -1;
    } else {
        return 0;
    }
}

int Fila::cheia() {
    if(this->fim == this->tamanhoMax-1) {
        return -1;
    } else {
        return 0;
    }
}

int Fila::tamanhoFila() {
    return this->nElementos;
}

int Fila::obterInicio() {
    if(vazia() == -1) {
        return -1;
    } else {
        return this->fila[this->inicio];
    }
}

int Fila::obterFim() {
    if(vazia() == -1) {
        return -1;
    } else {
        return this->fila[this->fim];
    }
}

int Fila::inserirElemento(int dado) {
    if(cheia() == -1) {
        return -1;
    } else {
        this->fim = (this->fim + 1) % this->tamanhoMax;
        this->fila[this->fim] = dado;
        this->nElementos++;
        return 0;
    }
}

int Fila::removerElemento() {
    if(vazia() == -1) {
        return -1;
    } else {
        int resultado = obterInicio();
        this->inicio = (this->inicio + 1) % this->tamanhoMax;
        this->nElementos--;
        return resultado;
    }
}

void hud() {
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Obter início" << endl;
    cout << "4 - Obter fim" << endl;
    cout << "5 - Sair" << endl;
    cout << "Digite a opção: ";
}

int main() {

    Fila *fila = new Fila();
    int opcao = 0;

    while(opcao != 5) {
        hud();
        cin >> opcao;

        switch(opcao) {
            case 1: {
                int dado;
                cout << "Digite o dado: ";
                cin >> dado;
                if(fila->inserirElemento(dado) == -1) {
                    cout << "Erro ao inserir elemento" << endl;
                } else {
                    cout << "Elemento inserido com sucesso" << endl;
                }
                break;
            }
            case 2: {
                int dado = fila->removerElemento();
                if(dado == -1) {
                    cout << "Erro ao remover elemento" << endl;
                } else {
                    cout << "Elemento removido: " << dado << endl;
                }
                break;
            }
            case 3: {
                int dado = fila->obterInicio();
                if(dado == -1) {
                    cout << "Erro ao obter início" << endl;
                } else {
                    cout << "Início: " << dado << endl;
                }
                break;
            }
            case 4: {
                int dado = fila->obterFim();
                if(dado == -1) {
                    cout << "Erro ao obter fim" << endl;
                } else {
                    cout << "Fim: " << dado << endl;
                }
                break;
            }
        }
    }


    return 0;
}