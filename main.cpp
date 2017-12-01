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
}  //L� os aqruivos e salvas todas as informa��es no vetor de aluno

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

int matricula(int m,Aluno alunos[TAM], int na) {
        
        int i;
        for(i=0; i<na; i++) {
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
            cout << "Usu�rio n�o encontrado!" << endl;
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
        cout<<"Usu�rio cadastrado com sucesso!"<<endl;
        na++; //Atualiza a quantidade de alunos


        }
// desenvolver a fun��o BUSCrA e fazer sua chamada na REMOVE_ALUNO;

void mostrar_alunos(Aluno alunos[TAM], int na){
    for(int i=0; i<na; i++){
        cout << alunos[i].nome<<endl;
    }
}
void remover_aluno(Aluno alunos[TAM], int &na){

        int m1,pos;
        cout << " digite a matricula do aluno:";
        cin >> m1;
        pos = matricula(m1,alunos,na);

        while(pos==-1){
                cout << " Usuário não encontrado! \n Digite a matricula do aluno:\n";
                cin >> m1;
                pos = matricula(m1,alunos,na);
        }        
        

        for(int i=pos; i<(na-1);i++){
                alunos[i] = alunos[i+1];
        }
        na--;
        mostrar_alunos(alunos,na);
 }

void mostrar_menu(){

}

void atribuir_relacao(int MatrizRelacao[TAM][TAM],Aluno alunos[TAM],int na){
        int al1, al2,rel; // al1 (matricula do aluno 1), al2(matricula do aluno 2);
        int m1;
        cout << " digite a matricula do primeiro usuário:";
        cin >> m1;
        al1 = matricula(m1,alunos,na);
        
        while(al1==-1){
                cout << " Usuário não encontrado! \n Digite a matricula do primeiro usuário:\n";
                cin >> m1;
                al1 = matricula(m1,alunos,na);
        }
        int m2;
        cout << "Digite a matricula do segundo usuário:";
        cin >> m2;
        al2 = matricula(m2,alunos,na);
        while(al2==-1 || m2 == m1){
                cout << "Usuário Inválido! \n Digite a matricula do segundo usuário:";
                cin >> m2;
                al2 = matricula(m2,alunos,na);        
        }
        cout<<"Digite a relacao entre eles:\n";
        cout << "Digite 0 para nao se conhecem " << endl <<"Digite 1 para sao conhecidos" << endl << "Digite 2 para sao amigos\n";
        cin>>rel;        

        MatrizRelacao[al2][al1]=rel;
        MatrizRelacao[al1][al2]=rel;


        for (int i = 0; i < na; i++){
                for(int j=0; j < na; j++) {
                        cout << MatrizRelacao[i][j] << " ";
                }
                cout << endl;
        }
}

void listar_alunos(Aluno alunos[TAM],int na,int MatrizRelacao[TAM][TAM]){
        int m1,al1;
        cout << " digite a matricula do primeiro usuário:";
        cin >> m1;
        al1 = matricula(m1,alunos,na);
        
        while(al1==-1){
                cout << " Usuário não encontrado! \n Digite a matricula do primeiro usuário:\n";
                cin >> m1;
                al1 = matricula(m1,alunos,na);
        }
        cout<<"Digite o status da relacao:\n";
        int status;
        cin>>status;
        for(int i = 0; i < na;i++){
                if(i!=al1 && MatrizRelacao[al1][i] == status){
                        cout<<alunos[i].nome<<endl;
                }
        }
        cout<<"Possue essa relação com "<<alunos[al1].nome<<endl;

}
void histograma(Aluno alunos[TAM],int na, float media[TAM]){
        
        for(int i=0;i<na;i++){

                float mediaTemp;
                mediaTemp = (alunos[i].nota[0] + alunos[i].nota[1] + alunos[i].nota[2])/3;
                if(mediaTemp >=5){
                        media[i] = mediaTemp;
                }else{
                        if(alunos[i].nota[0] <= alunos[i].nota[1] && alunos[i].nota[0] <= alunos[i].nota[2]){

                                mediaTemp = (alunos[i].nota[3] + alunos[i].nota[1] + alunos[i].nota[2])/3;

                        } else if(alunos[i].nota[1] < alunos[i].nota[0] && alunos[i].nota[1] < alunos[i].nota[2]){
                                
                                mediaTemp = (alunos[i].nota[0] + alunos[i].nota[3] + alunos[i].nota[2])/3;
                        } else{
                                
                                mediaTemp = (alunos[i].nota[0] + alunos[i].nota[1] + alunos[i].nota[3])/3;

                        }
                        media[i] = mediaTemp;
                }
        }

}
        i++;
        char s[TAM];
        cout<<"Digite um texto: "<<endl;
        cin.getline(s,TAM);
        int cont[26];
        histograma(s,cont);
        for(int i=0;i<;i++){
                cout<<char(i+97)<<":"<<cont[i]<<endl;
        }
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
                cout << "digite uma op��o: \n";
                cin >>in;
                switch(in) {
                case 1:
                        int m1,al1;
                        cout << " digite a matricula do aluno:";
                        cin >> m1;
                        al1 = matricula(m1,alunos,naM);
        
                        while(al1==-1){
                                cout << " Usuário não encontrado! \n Digite a matricula do aluno:\n";
                                cin >> m1;
                                al1 = matricula(m1,alunos,naM);
                        }
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
                case 7: 
                        atribuir_relacao(MatrizRelacao,alunos,naM);
                        break;
                case 10: 
                        listar_alunos(alunos,naM,MatrizRelacao);
                        break;
                case 20:
                        mostrar_alunos(alunos,naM);
                        break;
                case 30:
                        iniciar_alunos(alunos,naM);
                        break;
                case 40:
                        histograma(alunos,naM);
                        break;

                }
        }

}
