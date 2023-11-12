#include "Programacao.hpp"
#include <iostream>
#include <sstream>
/*
    Programacao():
    1-inicializa os atributos

*/
Programacao::Programacao(Cinema *c, int s, Filme *f, int t, string h){
    cinema = c;
    sala = s;
    filme = f;
    tipoDeExibicao = t;
    horarios = h;
}
/*
    ~Programacao():
    1-destrutor padrao

*/
Programacao::~Programacao(){
    delete cinema;
    delete filme;
}
/*
    obtemCinema():
    1-retorna um objeto cinema 

*/
Cinema* Programacao::obtemCinema() const{
    return cinema;
   
}
/*
    obtemSala():
    1-retorna a sala da programacao

*/
int Programacao::obtemSala() const{
    return sala;
}
/*
    obtemFilme():
    1-retorna um objeto filme

*/
Filme* Programacao::obtemFilme() const{
    return filme;
}
/*
    obtemTipoDeExibicao():
    1-retorna o tipo de exibicao da programacao

*/
int Programacao::obtemTipoDeExibicao() const{
    return tipoDeExibicao;
}
/*
    obtemHorarios():
    1-retorna os horarios da programacao

*/
string Programacao::obtemHorarios() const{
    return horarios;
}
/*
    str():
    1-retorna uma string com os dados da programacao

*/
string Programacao::str(bool incluiCinema) const {
    stringstream ss;
    
    if (incluiCinema) {
        ss << cinema->obtemNome() << endl;
    } else {
        
   
        ss << " - Sala " << sala << ": " << filme->obtemTitulo() << " | " << horarios << " | ";
        
        string aux;
        switch (tipoDeExibicao) {
            case 1:
                aux = "LEG";
                break;
            case 2:
                aux = "DUB";
                break;
            case 3:
                aux = "3D LEG";
                break;
            case 4:
                aux = "3D DUB";
                break;
            case 5:
                aux = " NAC";
                break;
        }
        
        ss << aux;

        if (filme->obtemFaixaEtaria() < 1) {
            ss << " [LIVRE]";
        } else {
            ss << " [" << filme->obtemFaixaEtaria() << "]";
        }
    }
    
    return ss.str(); 
}
/*
    defineCinema():
    1-atribui um objeto cinema a outro objeto cinema passado como parametro

*/
void Programacao::defineCinema(Cinema *c){
    cinema = c;
}
/*
    defineSala():
    1-atribui um valor a sala da programacao

*/
void Programacao::defineSala(int s){
    sala = s;
}
/*
    defineFilme():
    1-atribui um objeto filme a outro objeto filme passado como parametro

*/
void Programacao::defineFilme(Filme *f){
    filme = f;
}
/*
    defineTipoDeExibicao():
    1-atribui um valor ao tipo de exibicao da programacao

*/
void Programacao::defineTipoDeExibicao(int t){
    tipoDeExibicao = t;
}
/*
    defineHorarios():
    1-atribui um valor aos horarios da programacao

*/
void Programacao::defineHorarios(string h){
    horarios = h;
}

