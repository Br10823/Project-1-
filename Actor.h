#ifndef Actor_h_
#define Actor_h_

class Actor
{
  public:
  Actor();
  Actor(int, string);
  void setId(int);
  int getId();
  void setNombre(string);
  string getNombre();
  void muestra();

  private:
  int id;
  string nombre;
};
Actor::Actor()
{
  id = 0;
  nombre = "";
}
Actor::Actor(int identifiacion, string nombreActor)
{
  id = identifiacion;
  nombre = nombreActor;
}
void Actor::setId(int identifiacion)
{
  id = identifiacion;
}
int Actor::getId()
{
  return id;
}
void Actor::setNombre(string nombreActor)
{
  nombre = nombreActor;
}
string Actor::getNombre()
{
  return nombre;
}
void Actor::muestra()
{
  cout << "iD: " << id << endl << "Nombre del actor: " << nombre << endl;
}

#endif