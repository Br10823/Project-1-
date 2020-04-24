#ifndef Funcion_h_
#define Funcion_h_
#include "Hora.h"

class Funcion
{
  public:
  Funcion();
  Funcion(string, int, int, Hora);
  void setFuncion(string);
  string getFuncion();
  void setNumPeli(int);
  int getNumPeli();
  void setSala(int);
  int getSala();
  void setHora(Hora);
  Hora getHora();
  void muestra();

  private:
  string cveFuncion;
  int numPeli, sala;
  Hora hora;
};
Funcion::Funcion()
{
  Hora h(0,0);
  cveFuncion = "";
  numPeli = 0;
  sala = 0;
  hora = h;
}
Funcion::Funcion(string Funcion1, int numPelicula, int salaF, Hora h)
{
  cveFuncion = Funcion1;
  numPeli = numPelicula;
  sala = salaF;
  hora = h;
}
void Funcion::setFuncion(string funcion1)
{
  cveFuncion = funcion1;
}
string Funcion::getFuncion()
{
  return cveFuncion;
}
void Funcion::setNumPeli(int numPelicula)
{
  numPeli = numPelicula;
}
int Funcion::getNumPeli()
{
  return numPeli;
}
void Funcion::setSala(int salaF)
{
  sala = salaF;
}
int Funcion::getSala()
{
  return sala;
}
void Funcion::setHora(Hora h)
{
  hora = h;
}
Hora Funcion::getHora()
{
  return hora;
}
void Funcion::muestra()
{
  cout << "Función: " << cveFuncion << endl;
  cout << "Número de película: " << numPeli << endl;
  cout << "Sala: " << sala << endl;
}
#endif