#include <iostream>
//#include "funcoes.h"
#include <fstream>
# include <cstring>
#define TAM 100

using namespace std;


struct Aluno {
        char nome[TAM];
        int matricula;
        float nota[4];
        int faltas;
};


void iniciar_alunos (Aluno alunos[TAM], int &na) {

        float media;
        fstream alunosTxt; // objeto da biblioteca fstream;
        alunosTxt.open("alunos.txt");

        if (!alunosTxt.is_open () ) { // verifica se o arquivo foi aberto corretamente;
                cout << " Erro : arquivo nao encontrado \n";
                //exit(0);
        }
        alunosTxt >> na;
        cout << "Quantidade de alunos " << na<<"\n";
        for (int i=0; i<na; i++) {
                alunosTxt.ignore();
                alunosTxt.getline(alunos[i].nome,TAM);
                cout<<"Nome: "<< alunos[i].nome<<"\n";
                alunosTxt >> alunos[i].matricula;
                alunosTxt.ignore();
                cout<<"Matricula: "<< alunos[i].matricula<<"\n";
                alunosTxt >> alunos[i].nota[0] >> alunos[i].nota[1] >> alunos[i].nota[2];
                alunosTxt.ignore();
                cout << "Notas: " << alunos[i].nota[0];
                cout << " " << alunos[i].nota[1];
                cout << " " << alunos[i].nota[2] << "\n";
                media=(alunos[i].nota[0]+alunos[i].nota[1]+alunos[i].nota[2])/3;

                if(media>=5) {
                        alunosTxt >> alunos[i].faltas;
                        cout<<"Faltas: "<< alunos[i].faltas<<"\n";
                }
                else
                {
                        alunosTxt >> alunos[i].nota[3];
                        cout<<"Reposicao: "<< alunos[i].nota[3]<<"\n";
                        alunosTxt >> alunos[i].faltas;
                        cout<<"Faltas: "<< alunos[i].faltas<<"\n";

                }

        }
}  //Lê os aqruivos e salvas todas as informações no vetor de aluno

void relacao_alunos (int MR[TAM][TAM]){
        int nl, nc;

        fstream relacaoTxt;
        relacaoTxt.open ("relacao.txt");

        if (!relacaoTxt.is_open () ) { // verifica se o arquivo foi aberto corretamente;
                cout << " Erro : arquivo nao encontrado \n";
                //exit(0);
        }
        relacaoTxt >> nl >> nc;
        for (int i = 0; i < nl; i++) {
                for (int j=0; j < nc; j++) {
                        relacaoTxt >> MR[i][j];
                        cout << MR[i][j] << " ";

                }
                cout << endl;
        }
}

int matricula(Aluno alunos[TAM], int na) {
        int m;
        cout << " digite a matricula: ";
        cin >> m;
        for(int i=0; i<na; i++) {
                if(alunos[i].matricula == m) {
                        cout << alunos[i].nome << endl;
                        cout << alunos[i].faltas << endl;
                        float media=(alunos[i].nota[0]+alunos[i].nota[1]+alunos[i].nota[2])/3;

                        if(media>=5) {

                                cout<<"nota: "<< alunos[i].nota[0]<<" "<< alunos[i].nota[1]<<" "<< alunos[i].nota[2]<<"\n";

                        }
                        else{
                                cout<<"nota: "<< alunos[i].nota[0]<<" "<< alunos[i].nota[1]<<" "<< alunos[i].nota[2]<< " "<< alunos[i].nota[3]<<"\n";

                        }

                        return i;
                }
        }
        if(i==na){
            cout << "Usuário não encontrado!" << endl;
            //matricula(alunos,na);]
            return -1;

        }
}
void consuta_nome(Aluno alunos[TAM], int na){
        char nm[TAM]; // variavel que armazena os nomes;

        cout << "digite um nome: ";
        cin.ignore();
        cin.getline(nm,TAM);

        for(int i=0; i<na; i++) {

                if(strcmp(alunos[i].nome,nm) == 0) {
                        cout << alunos[i].nome << endl;
                        cout << alunos[i].faltas << endl;
                        float media=(alunos[i].nota[0]+alunos[i].nota[1]+alunos[i].nota[2])/3;

                        if(media>=5) {

                                cout<<"nota: "<< alunos[i].nota[0]<<" "<< alunos[i].nota[1]<<" "<< alunos[i].nota[2]<<"\n";

                        }
                        else{
                                cout<<"nota: "<< alunos[i].nota[0]<<" "<< alunos[i].nota[1]<<" "<< alunos[i].nota[2]<< " "<< alunos[i].nota[3]<<"\n";

                        }

                }
        }
}
void insercao(Aluno alunos[TAM], int &na){
        cout << "digite um nome: " << endl;
        cin.ignore();
        cin.getline(alunos[na].nome,TAM);
        cout << "digite a matricula: " << endl;
        cin >> alunos[na].matricula;
        cout << "digite o numero de faltas: " << endl;
        cin >> alunos[na].faltas;
        cout << "digite as notas: " << endl;
        cin>> alunos[na].nota[0]>> alunos[na].nota[1]>>alunos[na].nota[2];
        float media=(alunos[na].nota[0]+alunos[na].nota[1]+alunos[na].nota[2])/3;
        if(media<5) {
             cout<<"Nota da Reposicao: "<<endl;
             cin>>alunos[na].nota[3];

        }
        cout<<"Usuário cadastrado com sucesso!"<<endl;
        na++; //Atualiza a quantidade de alunos


        }
// desenvolver a função BUSCA e fazer sua chamada na REMOVE_ALUNO;

void mostrar_alunos(Aluno alunos, int na){
    for(int i=0; i<na; i++){
        cout << ""
    }
}
 void remover_aluno(Aluno alunos[TAM], int &na){
        int pos = matricula(alunos,na); // posição do usuario com a matricula inserida;
        if(pos !=-1){

            for(int i=pos; i<(na-2);i++){
                alunos[i] = alunos[i+1];
            }
            na--;
        }else{
            cout << "Essa operacao nao pode ser realizada!" << endl;
        }
 }

void mostrar_menu(){

}

int main(){

        Aluno alunos[TAM];
        int naM; // Variavel quantidade de alunos;
        int MatrizRelacao[TAM][TAM],in;
        char nome[TAM];
        iniciar_alunos(alunos,naM);
        relacao_alunos(MatrizRelacao);
        mostrar_menu();
        in = 2;
        while(in != 0){
                cout << "digite uma opção: \n";
                cin >>in;
                switch(in) {
                case 1:
                        matricula(alunos,naM);
                        break;
                case 2:
                        consuta_nome(alunos,naM);
                        break;
                case 3:
                        insercao(alunos, naM);
                        break;
                case 4:
                        remover_aluno(alunos,naM);
                        break;

                }
        }
}
