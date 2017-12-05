#include <iostream>
//#include "funcoes.h"
#include <fstream>
# include <cstring>
#include<cstdlib>
#define TAM 100

using namespace std;


struct Aluno {            // inicia as variáveis referentes ao aluno        
        char nome[TAM];
        int matricula;
        float nota[4];
        int faltas;
}; 

void atualizar_alunos(Aluno alunos[TAM],int na){ // Salva as alterações feitas no progama, no txt.

        fstream txt ;
        txt.open("alunos.txt", ofstream::out);
        if (!txt.is_open()){      // Verifica se o arquivo foi aberto corretamente ou existe.
                cout << " Erro : arquivo nao encontrado \n";
                exit(0) ; // sai do programa ( biblioteca cstdlib ).
        }

        txt<<na<<endl;
        for(int i = 0; i < na; i++){
                txt<<alunos[i].nome<<endl;
                txt<<alunos[i].matricula<<endl;

                float media=(alunos[i].nota[0]+alunos[i].nota[1]+alunos[i].nota[2])/3;

                if(media>=5) {
                        txt<<alunos[i].nota[0]<<" "<<alunos[i].nota[1]<<" "<<alunos[i].nota[2]<<endl;
                }
                else{
                        
                        txt<<alunos[i].nota[0]<<" "<<alunos[i].nota[1]<<" "<<alunos[i].nota[2]<<" "<<alunos[i].nota[3]<<endl;

                }

                txt<<alunos[i].faltas<<endl;
        }
        txt.close();
}

void atualizar_relacao(int Rel[TAM][TAM],int na){ // salva as alterações fetas no programa, no txt.

        ofstream rel;
        rel.open("relacao.txt", ofstream::out);
        if (!rel.is_open()){
                cout << " Erro : arquivo nao encontrado \n";
                exit(0) ; // sai do programa ( biblioteca cstdlib )
        }
        rel<<na<<" "<<na<<endl;
        for(int i = 0; i < na; i++){
                for(int j = 0;j<na;j++){
                        rel<<Rel[i][j]<<" ";
                }
                rel<<endl;
        }
        rel.close();
}


void iniciar_alunos (Aluno alunos[TAM], int &na) { // lê as informaçoes do arquivo txt.

        float media;
        fstream alunosTxt; // objeto da biblioteca fstream;
        alunosTxt.open("alunos.txt");

        if (!alunosTxt.is_open () ) { // verifica se o arquivo foi aberto corretamente.
                cout << " Erro : arquivo nao encontrado \n";
                exit(0);
        }
        alunosTxt >> na;
        for (int i=0; i<na; i++) { // lê o txt e salva nas variáveis do programa.
                alunosTxt.ignore();
                alunosTxt.getline(alunos[i].nome,TAM);
                alunosTxt >> alunos[i].matricula;
                alunosTxt.ignore();
                alunosTxt >> alunos[i].nota[0] >> alunos[i].nota[1] >> alunos[i].nota[2];
                alunosTxt.ignore();
                media=(alunos[i].nota[0]+alunos[i].nota[1]+alunos[i].nota[2])/3;

                if(media>=5) {
                        alunosTxt >> alunos[i].faltas;
                }
                else
                {
                        alunosTxt >> alunos[i].nota[3];
                        alunosTxt >> alunos[i].faltas;
                }

        }
}  //L� os aqruivos e salvas todas as informa��es no vetor de aluno

void relacao_alunos (int MR[TAM][TAM]){ // lê o txt e salva nas variáveis do programa.
        int nl, nc;

        fstream relacaoTxt;
        relacaoTxt.open ("relacao.txt");

        if (!relacaoTxt.is_open () ) { // verifica se o arquivo foi aberto corretamente;
                cout << " Erro : arquivo nao encontrado \n";
                exit(0);
        }
        relacaoTxt >> nl >> nc;

        for(int i = 0; i < na; i++){
                for(int j = 0;j<na;j++){
                        relacaoTxt>>Rel[i][j];
                }
        }

}

int matricula(int m,Aluno alunos[TAM], int na) { // Procura o aluno através da matricula e retorna a posição no vetor de alunos.

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
            cout << "Usuario nao encontrado!" << endl;
            //matricula(alunos,na);]
            return -1;

        }
}
void consuta_nome(Aluno alunos[TAM], int na){ // Procura o aluno através do nome.
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
void insercao(Aluno alunos[TAM], int &na){ // insere um novo aluno no programa
        cout << "Digite um nome: " << endl;
        cin.ignore();
        cin.getline(alunos[na].nome,TAM);
        cout << "Digite a matricula: " << endl;
        cin >> alunos[na].matricula;
        cout << "Digite o numero de faltas: " << endl;
        cin >> alunos[na].faltas;
        cout << "Digite as notas: " << endl;
        cin>> alunos[na].nota[0]>> alunos[na].nota[1]>>alunos[na].nota[2];
        float media=(alunos[na].nota[0]+alunos[na].nota[1]+alunos[na].nota[2])/3;
        if(media<5) {
             cout<<"Nota da Reposicao: "<<endl;
             cin>>alunos[na].nota[3];

        }
        cout<<"Usuario cadastrado com sucesso!"<<endl;
        na++; //Atualiza a quantidade de alunos
        atualizar_alunos(alunos,na);

        }
// desenvolver a fun��o BUSCrA e fazer sua chamada na REMOVE_ALUNO;
void insercao_nota(Aluno alunos[TAM], int &na){ // Substitui um nota de um aluno.
 int m1,pos;
 int u;
 float novanota,media;
        cout << " digite a matricula do aluno:";
        cin >> m1;
        pos = matricula(m1,alunos,na);

        while(pos==-1){
                cout << " Usuario nao encontrado! \n Digite a matricula do aluno:\n";
                cin >> m1;
                pos = matricula(m1,alunos,na);
        }
        cout<<"Digite a unidade em que se deseja substituir a nota: "<<endl;
        cin>>u;
        cout<<"Digite a nova nota: "<<endl;
       cin>>novanota;
       alunos[pos].nota[u-1]=novanota;
               cout<<"Nota cadastrada com sucesso !"<<endl;
}

void insercao_faltas(Aluno alunos[TAM], int &na){ // Insere as faltas de um aluno .
    int m1,pos,nfaltas;
        cout << " digite a matricula do aluno:";
        cin >> m1;
        pos = matricula(m1,alunos,na);

        while(pos==-1){
                cout << " Usuário não encontrado! \n Digite a matricula do aluno:\n";
                cin >> m1;
                pos = matricula(m1,alunos,na);
        }
            cout<<"Digite a insercao de faltas: "<<endl;
            cin>>nfaltas;
                alunos[pos].faltas=alunos[pos].faltas+nfaltas;
      if(alunos[pos].faltas<0){
        alunos[pos].faltas=0;
      }
      cout<<"Operacao realizada com sucesso!"<<endl;
}

void media_faltas(Aluno alunos[TAM], int &na){ // Retorna a media das faltas dos alunos.
    float media;
    float soma=0;
    for(int i=0;i<na;i++){
       soma=soma+ alunos[i].faltas;
    }
    media=soma/na;
    cout<<"Media de faltas: "<<media<<endl;
}

void mostrar_alunos(Aluno alunos[TAM], int na){ // Lista os alunos.
    for(int i=0; i<na; i++){
        cout << alunos[i].nome<<endl;
    }
}
void remover_aluno(Aluno alunos[TAM], int &na, int Rel[TAM][TAM]){ //  Remove um aluno do porgrama e atualiza a matriz de relação.

        int m1,pos;
        cout << " Digite a matricula do aluno:";
        cin >> m1;
        pos = matricula(m1,alunos,na);

        while(pos==-1){
                cout << " Usuário nao encontrado! \n Digite a matricula do aluno:\n";
                cin >> m1;
                pos = matricula(m1,alunos,na);
        }
        //Atualiza a matriz de Relação
        
        for(int i=0; i<na;i++){
                Rel[pos][i] = Rel[pos+1][i];
                Rel[i][pos] = Rel[i][pos+1];
        }
        

        
        //Atualiza o vetor de Alunos
        for(int i=pos; i<(na-1);i++){
                alunos[i] = alunos[i+1];
        }

        na--;

        cout<<"Aluno removido com sucesso !"<<endl;
        cout<<"Alunos restantes:"<<endl;
        mostrar_alunos(alunos,na);
        atualizar_alunos(alunos,na);
        cout<<"\n";
 }


void mostrar_menu(){ // Mostra o menu das opções.

        cout << "Digite uma opcao: \n";
        cout<<"1 - Consulta por matricula\n";
        cout<<"2 - Consulta por nome\n";
        cout<<"3 - Insercao de novo aluno\n";
        cout<<"4 - Remocao de aluno\n";
        cout<<"5 - Insercao de uma nota\n";
        cout<<"6 - Insercao de uma falta\n";
        cout<<"7 - Atribuicao de relacao entre alunos\n";
        cout<<"8 - Media de faltas dos alunos\n";
        cout<<"9 - Histograma das medias dos alunos\n";
        cout<<"10 - Listagem dos alunos que estao relacionados ou nao com um aluno\n";
        cout<<"11 - Relacao entre dois alunos\n"<<endl;

}

void atribuir_relacao(int MatrizRelacao[TAM][TAM],Aluno alunos[TAM],int na){ //  Muda ou atribui a relação entre os alunos.
        int al1, al2,rel; // al1 (matricula do aluno 1), al2(matricula do aluno 2);
        int m1;
        cout << " Digite a matricula do primeiro usuario:";
        cin >> m1;
        al1 = matricula(m1,alunos,na);

        while(al1==-1){
                cout << " Usuario nao encontrado! \n Digite a matricula do primeiro usuario:\n";
                cin >> m1;
                al1 = matricula(m1,alunos,na);
        }
        int m2;
        cout << "Digite a matricula do segundo usuario:";
        cin >> m2;
        al2 = matricula(m2,alunos,na);
        while(al2==-1 || m2 == m1){
                cout << "Usuario Invalido! \n Digite a matricula do segundo usuario:";
                cin >> m2;
                al2 = matricula(m2,alunos,na);
        }
        cout<<"Digite a relacao entre eles:\n";
        cout << "Digite 0 para nao se conhecem " << endl <<"Digite 1 para sao conhecidos" << endl << "Digite 2 para sao amigos\n";
        cin>>rel;
    if(rel==0 || rel==1 || rel==2){
        MatrizRelacao[al2][al1]=rel;
        MatrizRelacao[al1][al2]=rel;
        cout<<"Matriz Relacao entre os alunos"<<endl;
        for (int i = 0; i < na; i++){
                for(int j=0; j < na; j++) {
                        cout << MatrizRelacao[i][j] << " ";
                }
                cout << endl;
        }
    }
        else{
                cout<<"Relacao nao encontrada"<<endl;
        }
}

void listar_alunos(Aluno alunos[TAM],int na,int MatrizRelacao[TAM][TAM]){ // Lista todos os alunos com uma dada relação cm um aluno especifico.
        int m1,al1;
        cout << " digite a matricula do primeiro usuario:";
        cin >> m1;
        al1 = matricula(m1,alunos,na);

        while(al1==-1){
                cout << " Usuario não encontrado! \n Digite a matricula do primeiro usuario:\n";
                cin >> m1;
                al1 = matricula(m1,alunos,na);
        }
        cout<<"Digite o status da relacao:\n";
        int status;
        cin>>status;
        for(int i = 0; i < na;i++){
                if(i!=al1 && MatrizRelacao[al1][i] == status){
                        cout<<alunos[i].nome<<" possue essa relacao com "<<alunos[al1].nome<<endl;
                }
        }


}
void histograma(Aluno alunos[TAM],int na, float media[TAM]){ // Calcula a media e mstra quantos alunos estar em um dado intervalo. 
    int ocorrencias[TAM];
        int i=0, k=0;
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
        for(int i = 0; i < 5; i++) {
        ocorrencias[i] = 0;
    }
    for(int j = 0; j < na; j++) {
        if(media[j] < 2) {
            ocorrencias[0]++;
        }
        else if(media[j] < 4) {
            ocorrencias[1]++;
        }
        else if(media[j] < 6) {
            ocorrencias[2]++;
        }
        else if(media[j] < 8) {
            ocorrencias[3]++;
        }
        else ocorrencias[4]++;
    }



        cout << "0 - 2: ";
    for(int i = 0; i < ocorrencias[0]; i++) {
        cout << "*";
    }
    cout << "\n2 - 4: ";
    for(int i = 0; i < ocorrencias[1]; i++) {
        cout << "*";
    }
    cout << "\n4 - 6: ";
    for(int i = 0; i < ocorrencias[2]; i++) {
        cout << "*";
    }
    cout << "\n6 - 8: ";
    for(int i = 0; i < ocorrencias[3]; i++) {
        cout << "*";
    }
    cout << "\n8 - 10: ";
    for(int i = 0; i < ocorrencias[4]; i++) {
        cout << "*";
    }
    cout << "\n";

}

void relacao_por_matricula(Aluno alunos[TAM],int na,int MatrizRelacao[TAM][TAM]){ // Pede duas matriculos e mostra a relação entre os alunos da matricula crrespondente.
        int m1,al1,m2,al2;


        cout << " digite a matricula do primeiro usuario:";
        cin >> m1;
        al1 = matricula(m1,alunos,na);

        cout << " digite a matricula do segundo usuario:";
        cin >> m2;
        al2 = matricula(m2,alunos,na);
         if(al1==al2){
            cout<<"Ocorreu um erro"<<endl;
         }
            else
                while(al1==-1){
                cout << " Usuario não encontrado! \n Digite a matricula do primeiro usuario:\n";
                cin >> m1;
                al1 = matricula(m1,alunos,na);
        }


        while(al2==-1){
                cout << " Usuario nao encontrado! \n Digite a matricula do segundo usuario:\n";
                cin >> m2;
                al2 = matricula(m2,alunos,na);
        }
     if(al1!=al2){
        if(MatrizRelacao[al1][al2]==0 || MatrizRelacao[al2][al1] == 0)
            cout<<"Nao se conhecem"<<endl;
        else if(MatrizRelacao[al1][al2]==1 || MatrizRelacao[al2][al1] == 1)
        cout<<"Conhecem-se de vista"<<endl;
        else if(MatrizRelacao[al1][al2]==2 || MatrizRelacao[al2][al1] == 2)
                cout<<"Sao amigos"<<endl;
}
}




int main(){

        Aluno alunos[TAM];
        int naM; // Variavel quantidade de alunos;
        int MatrizRelacao[TAM][TAM],in;
        float media[TAM];
        char nome[TAM];
        iniciar_alunos(alunos,naM);
        relacao_alunos(MatrizRelacao);
        //mostrar_menu();
        in = 2;
        while(in != 0){
                
                mostrar_menu();
                cin >>in;
                switch(in) { // Verifica as condições de entrada.
                case 1:
                        int m1,al1;
                        cout << " digite a matricula do aluno:";
                        cin >> m1;
                        al1 = matricula(m1,alunos,naM);

                        while(al1==-1){
                                cout << " Usuario nao encontrado! \n Digite a matricula do aluno:\n";
                                cin >> m1;
                                al1 = matricula(m1,alunos,naM);
                        }
                        break;
                case 2:
                        consuta_nome(alunos,naM);
                        atualizar_relacao(MatrizRelacao,naM);

                        break;
                case 3:
                        insercao(alunos, naM);
                        atualizar_relacao(MatrizRelacao,naM);

                        break;
                case 4:
                        remover_aluno(alunos,naM,MatrizRelacao);
                        atualizar_relacao(MatrizRelacao,naM);
                        break;
                case 5:
                        insercao_nota(alunos,naM);
                        break;
                case 6:
                        insercao_faltas(alunos,naM);
                        break;

                case 7:
                        atribuir_relacao(MatrizRelacao,alunos,naM);
                        atualizar_relacao(MatrizRelacao,naM);                        
                        break;
                case 8:
                        media_faltas(alunos,naM);
                        break;

                case 9:
                        histograma(alunos,naM,media);
                        break;
                case 10:
                        listar_alunos(alunos,naM,MatrizRelacao);
                        break;
                case 11:
                        relacao_por_matricula(alunos,naM,MatrizRelacao);
                        break;

                case 20:
                        mostrar_alunos(alunos,naM);
                        break;
                case 30:
                        iniciar_alunos(alunos,naM);
                        break;
                case 28:
                        atualizar_alunos(alunos,naM);
                        break;
                case 40:
                        atualizar_relacao(MatrizRelacao,naM);
                        break;
                case 50:
                        relacao_alunos(MatrizRelacao);
                        break;
        

                }
        }

}
