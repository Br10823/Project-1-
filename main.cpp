#include <iostream>
#include "Hora.h"
#include "Actor.h"
#include "Funcion.h"
#include "Pelicula.h"
#include <fstream>
#include <string.h>
using namespace std;

void menu()
{
cout << "\t MENU" << endl;
cout << "1) Consulta todos los actores que están en la lista" << endl;
cout << "2) Consulta todas las películas que están en la lista" << endl;
cout << "3) Consulta todas las funciones disponibles" << endl;
cout << "4) Consulta de funciones por hora" << endl;
cout << "5) Consulta por clave de función" << endl;
cout << "6) Consulta películas en las que participa un actor" << endl;
cout << "7) Terminar" << endl;
}

int main() 
{
  int opcion, cont, id, cont1, numPeli, añoPeli, durPeli, cantActores, listaId[20], cantFunciones, numFuncionPeli, numSala, Hora, minutos, HoraBuscar, minutosBuscar, claveFuncion, pasoClave, HoraPaso, idBuscar, pasoId, pasoLista[20], pasoNumPeli, minutosPaso;

  Actor arrActores[20];
  Pelicula arrPelicula[20];
  Funcion arrFuncion[20];
  class Hora HoraMinutos[20], pasoHora, pasoH;
  string nombreActor, generoPeli, tituloPeli, nomFuncion;
  ifstream archActores, archPeliculas;
  bool encontro = false;


  archActores.open("Actores.txt");
  archPeliculas.open("Peliculas.txt");

  cont = 0;
  cont1 = 0;

  while (archActores >> id)
  {
    getline(archActores, nombreActor);

    arrActores[cont].setId(id);
    arrActores[cont].setNombre(nombreActor);
 
    cont ++;
  }

  while (archPeliculas >> numPeli)
  {
    archPeliculas >> añoPeli;
    archPeliculas >> durPeli;
    archPeliculas >> generoPeli;
    archPeliculas >> cantActores;
    for(int j = 0; j<cantActores;j++)
    {
      archPeliculas >> listaId[j];
    }
    getline(archPeliculas, tituloPeli);
    arrPelicula[cont1].setNumPeli(numPeli);
    arrPelicula[cont1].setAño(añoPeli);
    arrPelicula[cont1].setDuracion(durPeli);
    arrPelicula[cont1].setGenero(generoPeli);
    for(int i = 0; i< cantActores; i++)
    {
      arrPelicula[cont1].agregarActor(listaId[i]);
    }
    arrPelicula[cont1].setTitulo(tituloPeli);

    cont1++;
  }

  cout << "Escribe la cantidad de peliculas que deseas: ";
  cin >> cantFunciones;
  for(int i = 0; i<cantFunciones; i++)
  {
    cout << endl <<"Escribe el nombre de la película " << i+1 << " :" ;
    cin.ignore();
    getline(cin,nomFuncion);

    cout << endl << "Escribe la clave de la película " << i+1 << " :";
    cin >> numFuncionPeli;

    cout << endl << "Escribe el número de sala para la pelicula " << i+1 << " :";
    cin >> numSala;

    do
    {
      cout << endl << "Escribe las horas para la película " << i+1 << " :";
      cin >> Hora;
    } while(Hora<0 || Hora>23);

    do
    {
      cout << endl << "Escribe los minutos de la película " << i+1 << " :";
      cin >> minutos;
    } while( minutos<0 || minutos>59);

    HoraMinutos[i].setHora(Hora);
    HoraMinutos[i].setMinutos(minutos);

    arrFuncion[i].setHora(HoraMinutos[i]);
    arrFuncion[i].setNumPeli(numFuncionPeli);
    arrFuncion[i].setFuncion(nomFuncion);
    arrFuncion[i].setSala(numSala);
  }

  
  menu();
  cout << endl;
  cin >> opcion;
  cout << endl << endl;

  while(opcion !=7)
  {
    switch(opcion)
    {
      case 1:
      cout << "1. Lista de todos los actores en la lista" << endl;
      for(int j = 0;j<cont;j++)
      {
        arrActores[j].muestra();
        cout << endl;
      }
      break;

      case 2:
      cout << "2. Lista de todas las películas en la lista" << 
      endl;
      for(int i = 0; i<cont1 ;i++)
      {
        cout << "Título: " << arrPelicula[i].getTitulo() << endl;
        cout << "Año: " << arrPelicula[i].getAño() << endl;
        cout << "Duración: " << arrPelicula[i].getDuracion() << " min" << endl;
        cout << "Género: " << arrPelicula[i].getGenero() << endl;
        for(int j = 0; j<20; j++)
        {
          for(int g = 0; g<3;g++)
          {
            if(arrActores[j].getId() == arrPelicula[i].getListaActores(g))
            {
              cout << "-" << arrActores[j].getNombre() << endl; 
            }
          }
        }
        cout << endl;
      }
      break;

      case 3:
      cout << "3. Lista de todas las películas disponibles" << endl;
      for(int i=0;i<cantFunciones; i++)
      {
        arrFuncion[i].muestra();
        pasoH = arrFuncion[i].getHora();
        cout << "Hora: " << pasoH.getHora() << " : " << pasoH.getMinutos() << endl;
      }
      break;

      case 4:
      encontro = false;
      cout << "4. Lista de peliculas por Hora." << endl;
      while(encontro == false)
      {
        do
        {
        cout << "Escribe las horas de la pelicula seleccionada: ";
        cin >> HoraBuscar;
        }while(HoraBuscar<0 || HoraBuscar>24);
        do
        {
          cout << "Escribe los minutos de la película seleccionada: ";
          cin>>minutosBuscar;
        }while(minutosBuscar<0 || minutosBuscar>59);

        pasoHora.setHora(HoraBuscar);
        pasoHora.setMinutos(minutosBuscar);

        for(int i=0;i<cantFunciones;i++)
        {
          pasoHora = arrFuncion[i].getHora();
          HoraPaso = pasoHora.getHora();
          minutosPaso = pasoHora.getMinutos();
          if(HoraPaso == HoraBuscar && minutosPaso == minutosBuscar)
          {
            encontro = true;
            cout << "Título: " << arrFuncion[i].getFuncion() << endl << "Sala: " << arrFuncion[i].getSala() << endl;
          } 
        }
        if(encontro == false)
        {
          cout << "El programa no encontró la hora de la película seleccionada." << endl;
        }
      } 
      break;
      case 5:
      encontro = false;
      cout <<  "5. Lista de películas por ID." << endl;
      while(encontro == false)
      {
        cout << "Escribe el ID de la película que quieras: ";
        cin >> claveFuncion;
        for(int i=0;i<cantFunciones;i++)
        {
          pasoClave = arrPelicula[i].getNumPeli();
          if(pasoClave == claveFuncion)
          {
            encontro = true;
            pasoHora = arrFuncion[i].getHora();
            cout << "Sala: " << arrFuncion[i].getSala() << endl << "Título: " << arrFuncion[i].getFuncion() << endl << "Hora: " << pasoHora.getHora() << ":" << pasoHora.getMinutos() <<  endl << "Duración: " << arrPelicula[i].getDuracion() << endl << "Género: " << arrPelicula[i].getGenero() << endl;
            for(int j = 0; j<20; j++)
            {
              for(int g = 0; g<3;g++)
              {
                if(arrActores[j].getId() == arrPelicula[i].getListaActores(g))
                {
                  cout << "-" << arrActores[j].getNombre() << endl; 
                }
              }
            }
          }
        }
        if(encontro == false)
        {
          cout << "El programa no encontró esa película" << endl;
        }
      }
      
      break;

      case 6:
      encontro = false;
      cout << "6. Lista de películas en las que participa un actor:" <<endl;
      while(encontro == false)
      {
        cout << "Escribe el ID del actor que quieras: ";
        cin >> idBuscar;
        for(int i=0;i<cont1;i++)
        {
          for(int j=0;j<cantActores;j++)
          {
            pasoId = arrPelicula[i].getListaActores(j);
            if(idBuscar == pasoId)
            {
              cout << endl << "Título: " << arrPelicula[i].getTitulo() << endl << "Año: " << arrPelicula[i].getAño() << endl; 
              encontro =true;
            }
          }
        }
        if(encontro == false)
        {
          cout << "El programa no encontró el ID del actor buscado." << endl;
        }
      }
      break;
    }
    menu();
    cout << endl;
    cin >> opcion; 
    cout << endl << endl;
  }
  archActores.close();
  archPeliculas.close();
  cout << "El programa fue terminado. " << endl;
  return 0;
}