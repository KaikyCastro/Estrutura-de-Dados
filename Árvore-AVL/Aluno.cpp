#include "Aluno.h"
#include <iostream>
#include <string>
using namespace std;

Aluno::Aluno() {
    matricula = 0;
    nome = "";
}

Aluno::Aluno(int m, string n) {
    matricula = m;
    nome = n;
}

int Aluno::getMatricula() {
    return matricula;
}

string Aluno::getNome() {
    return nome;
}
