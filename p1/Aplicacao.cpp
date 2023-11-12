#include "Aplicacao.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

/*
    Aplicacao :
    1-inicializa as variaveis

*/
Aplicacao::Aplicacao() {
    numFilmes = 0;
    numCinemas = 0;
    numProgramacao = 0;
    
}
/*
    ~Aplicacao :
    1-for para percorrer o vetor de filmes
    2-for para percorrer o vetor de cinemas
    3-for para percorrer o vetor de programacao
    4-deleta os filmes
    5-deleta os cinemas
    6-deleta a programacao	
*/
Aplicacao::~Aplicacao() {
}
/*
    carregaFilmes :
    1-abre o arquivo
    2-if para verificar se o arquivo esta aberto
    3-while com paramentro de linha
    4-vai percorrendo as linhas do arquivo com % para saber qual linha é
    5-vai salvando as informaçoes 
    6-vai colocar as informaçoes no vetor de filmes
    7-vai incrementar o numero de filmes
    8-fecha o arquivo

*/
bool Aplicacao::carregaFilmes(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return false;
    }

    string linha;
    int numFilme = 0;
    Filme filme;
    while (getline(arquivo, linha)) {
        numFilme++;
        // if (arquivo.eof()) {
        //     cout << "Limite máximo de filmes excedido." << endl;
        //     return false;
            
        // }
        if (numFilme % 4 == 1) {
           
            int aux;
            aux = stoi(linha);
            filme.defineNumero(aux);
            
        } else if (numFilme % 4 == 2) {
            filme.defineTitulo(linha);
           
        } else if (numFilme % 4 == 3) {
            int aux;
            aux = stoi(linha);
            filme.defineFaixaEtaria(aux);
          
        } else if (numFilme % 4 == 0) {
            filme.defineEstilo(linha);
            vetfilmes.push_back(filme);
            numFilmes++;
        }
        
    }

    arquivo.close();

    return true;
}
/*
    salvaFilmes :
    1-abre o arquivo
    2-if para verificar se o arquivo esta aberto
    3-for para percorrer o vetor de filmes
    4-salva as varieis no arquivo
    5-fecha o arquivo

*/
bool Aplicacao::salvaFilmes(string nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return false;
    }

    for (int i = 0; i < numFilmes; i++) {
        arquivo << vetfilmes[i].obtemNumero() << endl;
        arquivo << vetfilmes[i].obtemTitulo() << endl;
        arquivo << vetfilmes[i].obtemFaixaEtaria() << endl;
        arquivo << vetfilmes[i].obtemEstilo() << endl;
    }

    arquivo.close();
    return true;
}
/*
    mostraFilmes :
    1-for para percorrer o vetor de filmes
    2-imprime o filme str()


*/
void Aplicacao::mostraFilmes() {
    for (int i = 0; i < numFilmes; i++) {
        
        cout << vetfilmes[i].str() << endl;
    }
}
/*
    ordenaFilmes :
    1-fiz um bouble sort para ordenar os filmes
    2-if para verificar se o numero do filme da posiçao i do vetor de filmes é igual ao numero do filme passado como parametro
    3-se sim min_idx recebe j
    4-se nao min_idx recebe i
    5-se min_idx for diferente de i
    6-troca os ponteiros de filmes[i] e filmes[min_idx]
    7-se nao troca nada



*/
void Aplicacao::ordenaFilmes() {
    sort(vetfilmes.begin(), vetfilmes.end());
}

/*
    obtemFilme :
    1-verifica se o numero do filme esta dentro do limite
    2-for para percorrer o vetor de filmes
    3-if para verificar se o numero do filme da posiçao i do vetor de filmes é igual ao numero do filme passado como parametro
    4-se sim retorna o filme
    5-se nao retorna nullptr

*/
Filme* Aplicacao::obtemFilme(int id) {
    
    if(id<0 || id>numFilmes){
        
        return nullptr;
    }
    for (int i = 0; i < numFilmes; i++) {
        if (vetfilmes[i].obtemNumero() == id) {
            return &vetfilmes[i];
        }
    }
   
    return nullptr; 
}
/*
    carregaCinemas :
    1-verifica se abriu corretamente
    2-cria variaveis auxiliares para a leitura do arquivo   
    3-while com paramentro de linha
    4-vai percorrendo as linhas do arquivo com % para saber qual linha é
    5-vai salvando as informaçoes 
    6-vai colocar as informaçoes no vetor de cinemas
    7-vai incrementar o numero de cinemas
    8-fecha o arquivo
    

*/
bool Aplicacao::carregaCinemas(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return false;
    }

    string linha;
    Cinema cinema;
    int numlinha= 0;
    Endereco Endereco;

    while (getline(arquivo, linha)) {
       numlinha++;
        // if (arquivo.eof()) {
        //     cout << "Limite máximo de cinemas excedido." << endl;
        //     return false;
        //     }
        if(numlinha%10==1){
            int aux;
            aux = stoi(linha);
            cinema.defineNumero(aux);
        }else if(numlinha%10==2){
            cinema.defineNome(linha);
        }else if(numlinha%10==3){
            
            Endereco.defineLogradouro(linha);
        }else if(numlinha%10==4){
            int aux;
            aux = stoi(linha);
            Endereco.defineNumero(aux);
        }else if(numlinha%10==5){
            Endereco.defineComplemento(linha);
        }else if(numlinha%10==6){
            Endereco.defineBairro(linha);
        }else if(numlinha%10==7){
            Endereco.defineCEP(linha);
        }else if(numlinha%10==8){
            Endereco.defineCidade(linha);
        }else if(numlinha%10==9){
            Endereco.defineEstado(linha);
            cinema.defineEndereco(Endereco);

        }else if(numlinha%10==0){
            int aux;
            aux= stoi(linha);
            cinema.defineSalas(aux);
            vetcinemas.push_back(cinema);
            numCinemas++;
        }
    }
     arquivo.close();
     return true;
    }

/*
    salvaCinemas :
    1-verifica se o numero de cinemas é igual a zero
    2-abre o arquivo
    3-if para verificar se o arquivo esta aberto
    4-for para percorrer o vetor de cinemas
    5-salva as varieis no arquivo
    6-fecha o arquivo

*/
bool Aplicacao::salvaCinemas(string nomeArquivo) {
    if(numCinemas==0){
        return false;
    }
    
    ofstream arquivo(nomeArquivo);
    Endereco Endereco;
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return false;
    }

   for (int i = 0; i < numCinemas; i++) {
       arquivo << vetcinemas[i].obtemNumero() << endl;
       arquivo << vetcinemas[i].obtemNome() << endl;
       arquivo << Endereco.obtemLogradouro() << endl;
       arquivo << Endereco.obtemNumero() << endl;
       arquivo << Endereco.obtemComplemento() << endl;
       arquivo << Endereco.obtemBairro() << endl;
       arquivo << Endereco.obtemCEP() << endl;
       arquivo << Endereco.obtemCidade() << endl;
       arquivo << Endereco.obtemEstado() << endl;
       arquivo << vetcinemas[i].obtemSalas() << endl;
    }
    arquivo.close();
    return true;
}
/*
    mostraCinemas :
    1-for para percorrer o vetor de cinemas
    2-imprime o cinema str()
*/
void Aplicacao::mostraCinemas() {
   for(int i=0;i<numCinemas;i++){
       cout<<vetcinemas[i].str()<<endl;
    }
}
/*
    ordenaCinemas :
    1-fiz um bouble sort para ordenar os cinemas
    2-if para verificar se o numero do cinema da posiçao i do vetor de cinemas é igual ao numero do cinema passado como parametro
    3-se sim min_idx recebe j
    4-se nao min_idx recebe i
    5-se min_idx for diferente de i
    6-troca os ponteiros de cinemas[i] e cinemas[min_idx]
    7-se nao troca nada
*/
void Aplicacao::ordenaCinemas() {
    sort(vetcinemas.begin(), vetcinemas.end());
}
/*
    obtemCinema :
    1-verifica se o numero do cinema esta dentro do limite
    2-for para percorrer o vetor de cinemas
    3-if para verificar se o numero do cinema da posiçao i do vetor de cinemas é igual ao numero do cinema passado como parametro
    4-se sim retorna o cinema
    5-se nao retorna nullptr

*/
Cinema* Aplicacao::obtemCinema(int id) {
    if(id<0 || id>numCinemas){
        return nullptr;
    }
    for (int i = 0; i < numCinemas; i++) {
        if (vetcinemas[i].obtemNumero() == id) {
            return &vetcinemas[i]; 
        }
    }
    return nullptr; 
}

/*
    carregaProgramacao :
    1faz as verificaçoes de erro e carrega o arquivo de programacao
    2-o while tem parametro de verificar se o arquivo esta vazio
    3-cria variaveis auxiliares para a leitura do arquivo
    4-tem o if que diz quando parar se nao tiver mais 
    5-le o arquivo e coloca nas variaveir criadas
    6-por fim coloca as informaçoes no vetor de programacao
    7-incrementa o numero de programacao
    8-fecha o arquivo

*/
bool Aplicacao::carregaProgramacao(string nomeArquivo) {
    if (numProgramacao == MAX_PROGRAMACAO){
        return false;
    }
    ifstream arquivo(nomeArquivo);
         if (arquivo.eof()){
            return false;
        }
        if (!arquivo.is_open()){
            cout << "Erro ao abrir o arquivo" << endl;  
            return false;
        }
        while (!arquivo.eof()){
            string aux = "";
            string auxH;
            int s;
            int Exibicao;
            int idCinema;
            int idFilme;

            getline(arquivo, aux);
            idCinema = stoi(aux);

            getline (arquivo, aux);
            s = stoi(aux);

            getline(arquivo,aux);
            idFilme = stoi(aux);

            getline (arquivo, aux);
            Exibicao = stoi(aux);

            getline (arquivo, auxH);
            Programacao prog(obtemCinema(idCinema),s,obtemFilme(idFilme),Exibicao,auxH);
            vetprogramacao.push_back(prog);
            numProgramacao++;
        }
        arquivo.close();
        return true;
}


/*
    mostraProgramacao :
    1-for para percorrer o vetor de cinemas
    2-imprime o nome do cinema
    3-for para percorrer o vetor de programacao
    4-if para verificar se o cinema da posiçao j do vetor de programacao é igual ao cinema da posiçao i do vetor de cinemas
    5-se for igual imprime a programacao str()
    6-fecha o for
*/
void Aplicacao::mostraProgramacao() {
 
    for (int i = 0; i < vetcinemas.size(); i++) {
        cout << vetcinemas[i].obtemNome() << endl;
        
        for (int j = 0; j < vetprogramacao.size(); j++) {
           
            if(vetprogramacao[j].obtemCinema() == &vetcinemas[i]){
                cout << vetprogramacao[j].str(false) << endl; 
            }
            
           
        }
    }
}
