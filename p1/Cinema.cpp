#include "Cinema.hpp"
#include <sstream>

/*
    Cinema():
    1-inicializa os atributos


*/
Cinema::Cinema(){
    numero = 0;
    nome = "";
    endereco = Endereco();
    salas = 0;
 }


 /*
    Cinema(...):
    1-inicializa os atributos com os valores passados como parametro

*/
Cinema::Cinema(int n, string nm, Endereco &e, int s){
    numero = n;
    nome = nm;
    endereco = e;
    salas = s;
  }
/*
    ~Cinema():
    1-destrutor padrao
  
 */
Cinema::~Cinema(){}
/*
    obtemNumero():
    1-retorna o numero do cinema

*/
int Cinema::obtemNumero() const{
   return numero;
}
/*
    obtemNome():
    1-retorna o nome do cinema

*/
string Cinema::obtemNome() const{
    return nome;
}
/*
    obtemEndereco():
    1-retorna o endereco do cinema

*/
Endereco Cinema::obtemEndereco() const{
    return endereco;
}
/*
    obtemSalas():
    1-retorna o numero de salas do cinema

*/
int Cinema::obtemSalas() const{
    return salas;
}
/*
    str():
    1-retorna uma string com os dados do cinema

*/
string Cinema::str() const{
    stringstream ss;
    ss<<nome<<" [ "<< numero <<" ]"<<endl;
    ss<<endereco.str()<<endl;
    ss<<"Cinema (s) :"<<salas;
    return ss.str();

}
/*
    defineNumero(...):
    1-atribui um valor ao numero do cinema

*/
void Cinema::defineNumero(int n){
    numero = n;
}
/*
    defineNome(...):
    1-atribui um valor ao nome do cinema
*/
void Cinema::defineNome(string nm){
    nome = nm;
}
/*
    defineEndereco(...):
    1-atribui um valor ao endereco do cinema
*/
void Cinema::defineEndereco(Endereco &e){
    endereco = e;
}
/*
    defineSalas(...):
    1-atribui um valor ao numero de salas do cinema
*/
void Cinema::defineSalas(int s){
    salas = s;
}
/*
    operator<(...):
    1-compara se cinema atual é menos que cinema passado como parametro por oredem alfabetica
*/
bool Cinema::operator<(const Cinema &c) const{
    return this->nome < c.nome;

}

/*
    operetor>>(...):
    1-faz a sobrecarga do operador >>

*/
istream &operator>>(istream &in,Cinema &c){
    string auxN;
    auxN = c.numero;
    getline(in,auxN);
    c.numero = stoi(auxN);
    getline(in,c.nome);
    in>>c.endereco;
    string auxS;
    auxS = c.salas;
    getline(in,auxS);
    c.salas = stoi(auxS);
    return in;
    



}
/*
    operator<<(...):
    1-faz a sobrecarga do operador <<

*/
ostream &operator<<(ostream &out,const Cinema &c){
    out<<c.str();
    return out;
}

