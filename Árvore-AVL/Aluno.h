#include <iostream>
#include <string>

using namespace std;

class Aluno {
    private:
        int matricula;
        string nome;

    public:
        Aluno();
        Aluno(int m, string n);
        int getMatricula();
        string getNome();
};