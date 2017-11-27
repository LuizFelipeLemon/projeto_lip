#include <iostream>
using namespace std;

const int MAX = 100;

struct Aluno {
        char nome[MAX];
        int matricula;
        float nota;
};

void limite (Aluno v[], int n, Aluno &maior, Aluno &menor){
        maior=v[0];
        menor=v[0];
        for(int i=0; i<n; i++) {
                if(v[i].nota>maior.nota) {
                        maior = v[i];
                }
                if(v[i].nota<menor.nota) {
                        menor = v[i];
                }
        }
}
int main(){
        int n, i;
        Aluno alunos[MAX];
        float media = 0.0;
        cout<<"Digite a quantidade de alunos: "<<endl;
        cin>>n;
        cin.ignore();
        for(i=0; i<n; i++) {
                cout<<"Insira o nome do aluno: "<<endl;
                cin.getline(alunos[i].nome, MAX);
                cout<<"Insira a matricula do aluno: "<<endl;
                cin>>alunos[i].matricula;
                cin.ignore();
                cout<<"Insira a nota do aluno: "<<endl;
                cin>>alunos[i].nota;
                cin.ignore();
        }
        Aluno maior, menor;
        limite(alunos,n,maior,menor);
        cout<<"Menores notas:"<<endl;
        for(int i=0; i<n; i++) {
                if(alunos[i].nota == menor.nota) {
                        cout<<"Nome: " << alunos[i].nome<<endl;
                        cout<<"Matricula: " << alunos[i].matricula<<endl;
                        cout<<"Nota: " << alunos[i].nota<<endl;
                }
        }
        cout<<"Maiores notas:"<<endl;
        for(int i=0; i<n; i++) {
                if(alunos[i].nota == maior.nota) {
                        cout<<"Nome: " << alunos[i].nome<<endl;
                        cout<<"Matricula: " << alunos[i].matricula<<endl;
                        cout<<"Nota: " << alunos[i].nota<<endl;
                }
        }
        return 0;
}
