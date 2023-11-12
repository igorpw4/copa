

#ifndef _APLICACAO_HPP
#define _APLICACAO_HPP
#include <vector>
#include <string>
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Programacao.hpp"

#define MAX_CINEMAS 50
#define MAX_PROGRAMACAO 250

using namespace std;

class Aplicacao {
private:
  vector<Cinema> vetcinemas;
  int numCinemas;
  vector<Filme> vetfilmes;
  int numFilmes;
  vector<Programacao> vetprogramacao;
  int numProgramacao;
public:
  Aplicacao(); // Primeira etapa
  ~Aplicacao();
  bool carregaFilmes(string nomeArquivo);
  bool salvaFilmes(string nomeArquivo);
  void mostraFilmes();
  void ordenaFilmes();
  Filme *obtemFilme(int id);

  bool carregaCinemas(string nomeArquivo); // Segunda etapa
  bool salvaCinemas(string nomeArquivo);
  void mostraCinemas();
  void ordenaCinemas();
  Cinema *obtemCinema(int id);

  bool carregaProgramacao(string nomeArquivo); // Terceira etapa
  void mostraProgramacao();
};

#endif
