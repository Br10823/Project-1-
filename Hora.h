#ifndef Hora_h_
#define Hora_h_
using namespace std;
class Hora
{
  private:
  int hora, minuto;

  public:
  Hora();
  Hora(int,int);
  int getHora();
  int getMinutos();
  void muestra();
  void setHora(int);
  void setMinutos(int);
};

Hora::Hora()
{
  hora = 0;
  minuto = 0;
}
Hora::Hora(int HoraP, int minP)
{
  hora = HoraP;
  minuto = minP;
}
int Hora::getHora()
{
  return hora;
}
int Hora::getMinutos()
{
  return minuto;
}
void Hora::muestra()
{
  cout << hora << " : " << minuto << endl;
}
void Hora::setHora(int HoraP)
{
  hora = HoraP;
}
void Hora::setMinutos(int minP)
{
  minuto = minP;
}

#endif