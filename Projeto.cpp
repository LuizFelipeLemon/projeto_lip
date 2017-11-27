#include <iostream>
using namespace std;

const int MAX = 100;

struct Aluno {
        char nome[MAX];
        int matricula;
        float nota[4];
        int faltas;
};

void le_matriz(int MatrizRelacao[MAX][MAX], int nl, int nc ){
        for(int i=0; i<nl; i++) {
                for(int j=0; j<nc; j++) {
                        cin>>MatrizRelacao[i][j];
                }
        }
}
void exibe_matriz(int MatrizRelacao[MAX][MAX], int nl, int nc){
        for(int i=0; i<nl; i++) {
                for(int j=0; j<nc; j++) {
                        cout<<MatrizRelacao[i][j]<< " ";
                }
                cout<<endl;
        }
}

int main(){
        int n, i;
        Aluno alunos[MAX];
        int MatrizRelacao[MAX][MAX];
        int nl, nc;
        cout<<"Digite a quantidade de alunos: "<<endl;
        cin>>n;
        cin.ignore();
        for(i=0; i<n; i++) {
                cout<<"Insira o nome do aluno: "<<endl;
                cin.getline(alunos[i].nome, MAX);
                cout<<"Insira a matricula do aluno: "<<endl;
                cin>>alunos[i].matricula;
                cin.ignore();
                cout<<"Insira as notas do aluno: "<<endl;
                for(int i=0; i<4; i++) {
                        cin>>alunos[i].nota[i];
                }
                cin.ignore();
                cout<<"Digite a quantidade de faltas: "<<endl;
                cin>>alunos[i].faltas;
                cin.ignore();

        }
        cin>>nl>>nc;
        le_matriz(MatrizRelacao,nl,nc);
        cout<<endl;
        exibe_matriz(MatrizRelacao,nl,nc);
        return 0;
}
