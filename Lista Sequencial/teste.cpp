#include "LSequencial.h"
#include <cassert>

void runTests() {
    listaSequencial lista;
    assert(lista.listaVazia());
    lista.inserirElemento(1, 42);
    assert(!lista.listaVazia());
    assert(lista.elementoLista(1) == 42);
    lista.removerElemento(1);
    assert(lista.listaVazia());
    std::cout << "Todos os testes passaram!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
