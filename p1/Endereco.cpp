
#include "Endereco.hpp"
 #include <sstream>
 
 
 
/*
    Endereco(...):
    1-inicializa os atributos com os valores passados como parametro

*/
 Endereco::Endereco(string l, int n, string c, string b, string cp, string cd, string e){
    logradouro=l;
    numero=n;
    complemento=c;
    bairro=b;
    cep=cp;
    cidade=cd;
    estado=e;
}
/*
    ~Endereco():
    1-destrutor padrao

*/
Endereco::  ~Endereco(){}
/*
    obtemLogradouro():
    1-retorna o logradouro do endereco

*/
string  Endereco::obtemLogradouro() const{
    return logradouro;
}
/*
    obtemNumero():
    1-retorna o numero do endereco


*/
int  Endereco::obtemNumero() const{
    return numero;
}
/*
    obtemComplemento():
    1-retorna o complemento do endereco

*/
string  Endereco::obtemComplemento() const{
    return complemento;
}
/*
  obtemBairro():
    1-retorna o bairro do endereco

*/
string  Endereco::obtemBairro() const{
    return bairro;
}
/*
    obtemCEP():
    1-retorna o cep do endereco

*/
string  Endereco::obtemCEP() const{
    return cep;
}
/*
    obtemCidade():
    1-retorna a cidade do endereco

*/
string  Endereco::obtemCidade() const{
    return cidade;
}
/*
    obtemEstado():
    1-retorna o estado do endereco

*/
string  Endereco::obtemEstado() const{
    return estado;
}
/*
    str():
    1-retorna uma string com os dados do endereco

*/
string  Endereco::str() const{
    stringstream ss;
    ss<<logradouro<<" , "<<numero<<" - "<<complemento<<" - Bairro"<<bairro<<" - "<<cidade<<" - "<< estado;
    return ss.str();
}
/*
    defineLogradouro(...):
    1-atribui o valor passado como parametro ao atributo logradouro

*/
void  Endereco::defineLogradouro(string l){
    this->logradouro=l;
}
/*
    defineNumero(...):
    1-atribui o valor passado como parametro ao atributo numero

*/
void  Endereco::defineNumero(int n){
    this->numero=n;
}
/*
    defineComplemento(...):
    1-atribui o valor passado como parametro ao atributo complemento

*/
void  Endereco::defineComplemento(string c){
    this->complemento=c;
}
/*
    defineBairro(...):
    1-atribui o valor passado como parametro ao atributo bairro

*/
void  Endereco::defineBairro(string b){
    this->bairro=b;
}
/*
    defineCEP(...):
    1-atribui o valor passado como parametro ao atributo cep

*/
void  Endereco::defineCEP(string cp){
    this->cep=cp;
}
/*
    defineCidade(...):
    1-atribui o valor passado como parametro ao atributo cidade

*/
void  Endereco::defineCidade(string cd){
    this->cidade=cd;
}
/*
    defineEstado(...):
    1-atribui o valor passado como parametro ao atributo estado

*/
void  Endereco::defineEstado(string e){
    this->estado=e;
}
/*
    operator>>(...):
    1-sobrecarga do operador >>

*/
istream &operator>>(istream &in,Endereco &e){
    getline(in,e.logradouro);
    string auxN;
    auxN = e.numero;
    getline(in,auxN);
    e.numero=stoi(auxN);
    getline(in,e.complemento);
    getline(in,e.bairro);
    getline(in,e.cep);
    getline(in,e.cidade);
    getline(in,e.estado);
    return in;

}
/*
    operator<<(...):
    1-sobrecarga do operador <<

*/
ostream &operator<<(ostream &out,const Endereco &e){
    out<<e.str();
    return out;
}

