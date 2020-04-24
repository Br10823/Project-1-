#ifndef Pelicula_h_
#define Pelicula_h_

class Pelicula
{
  private:
  int numPeli, año, duracion, cantidadActores, listaActores[10];
  string titulo, genero; 

  public:
  Pelicula();
  void setNumPeli(int);
  int getNumPeli();
  void setTitulo(string);
  string getTitulo();
  void setAño(int);
  int getAño();
  void setDuracion(int);
  int getDuracion();
  void setGenero(string);
  string getGenero();
  int getListaActores(int);
  bool agregarActor(int);
  
};
Pelicula::Pelicula()
{
  numPeli = 0;
  año = 0;
  duracion = 0;
  cantidadActores = 0;
  listaActores[0] = 0;
  titulo = "";
  genero = ""; 
}
void Pelicula::setNumPeli(int numeroPeli)
{
  numPeli = numeroPeli;
}
int Pelicula::getNumPeli()
{
  return numPeli;
}
void Pelicula::setTitulo(string tituloPeli)
{
  titulo = tituloPeli;
}
string Pelicula::getTitulo()
{
  return titulo;
}
void Pelicula::setAño(int añoP)
{
  año =añoP;
}
int Pelicula::getAño()
{
  return año;
}
void Pelicula::setDuracion(int duracionPeli)
{
  duracion = duracionPeli;
}
int Pelicula::getDuracion()
{
  return duracion;
}
void Pelicula::setGenero(string generoPeli)
{
  genero = generoPeli;
}
string Pelicula::getGenero()
{
  return genero;
}
int Pelicula::getListaActores(int i)
{
  return listaActores[i];
}
bool Pelicula::agregarActor(int i)
{
  bool valido = true;
  if(cantidadActores<10)
  {
    for(int j =0; j<cantidadActores; j++)
    {
      if(listaActores[j] == i)
      {
        valido = false;
      }
    }
  } else
  valido = false;
  
  if (valido == true)
  {
    
    listaActores[cantidadActores] = i;
    cantidadActores++;

  }
  return valido;
}
#endif