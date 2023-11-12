#include "Filme.hpp"
#include <sstream>
#include <iostream>
/*
    Filme():
    1-inicializa os atributos

*/
 Filme::Filme(int n, string t, int f, string e){
    numero=n;
    titulo=t;
    faixaEtaria=f;
    estilo=e;
   
    }
/*
    ~Filme():
    1-destrutor padrao

*/
Filme:: ~Filme(){}
/*
    obtemNumero():
    1-retorna o numero do filme
*/
int Filme::obtemNumero() const{   
    return numero;

 }
/*
    obtemTitulo():
    1-retorna o titulo do filme

*/
string Filme::obtemTitulo() const{
    return titulo;
}
/*
    obtemFaixaEtaria():
    1-retorna a faixa etaria do filme

*/
int Filme::obtemFaixaEtaria() const{
    return faixaEtaria;
}
/*
    obtemEstilo():
    1-retorna o estilo do filme

*/
string Filme::obtemEstilo() const{
    return estilo;
}
/*
    str():
    1-retorna uma string com os dados do filme

*/
string Filme::str() const{
    stringstream ss;
    string aux;
    if(faixaEtaria==0){
        aux="LIVRE";
    }
    aux=" anos";

    ss<< titulo <<" [ "<<numero<<" ] - "<<faixaEtaria<< aux<<" - "<<estilo;
    return ss.str();
}
/*
    defineNumero():
    1-atribui um numero ao filme

*/
void Filme::defineNumero(int n){
    numero=n;
}
/*
    defineTitulo():
    1-atribui um titulo ao filme

*/
void Filme::defineTitulo(string t){
    titulo=t;
}
/*
    defineFaixaEtaria():
    1-atribui uma faixa etaria ao filme

*/
void Filme::defineFaixaEtaria(int f){
    faixaEtaria=f;
}
/*
    defineEstilo():
    1-atribui um estilo ao filme

*/
void Filme::defineEstilo(string e){
    estilo=e;
}
/*
    operator<():
    1-compara dois filmes pelo titulo em ordem alfabetica

*/
bool Filme::operator<(const Filme &f) const{
  for(int i=0;i<this->titulo.size();i++){
      if(this->titulo[i]<f.titulo[i]){
          return true;
      }else if(this->titulo[i]>f.titulo[i]){
          return false;
      }
  }
    return false;
}
/*
    operator>>():
    1-sobrecarga do operador >>

*/
istream &operator>>(istream &in, Filme &f) {
    string auxN;
    getline(in, auxN);
    f.numero = stoi(auxN);
    
    getline(in, f.titulo);
    
    string auxF;
    getline(in, auxF);
    f.faixaEtaria = stoi(auxF);
    
    getline(in, f.estilo);
    
    return in;
}

/*
    operator<<():
    1-sobrecarga do operador <<

*/
ostream &operator<<(ostream &out,const Filme &f){
    out << f.str();
    return out;
}
