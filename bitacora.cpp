/*Equipo 1
Lia Michelle Nuñez
Ana Sofia Rojas Rodriguez
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "registro.h"
using namespace std;


int main()
{
  string fecha, hora , ipfuente, hostnamefuente, ipdestino, hostnamedestino;
  int puertofuente, puertodestino;

  stringstream s;
  vector<Registro> registros; //Declaracion del vector
  ifstream datos_csv("equipo1.csv");
  char coma=  ',';

  //Registro r;
  string line, dato, todo;
  int renglon;

  
  while(getline(datos_csv,line))
  {
  Registro r;
  stringstream s(line);
  renglon=0;
  

  while(getline(s,dato,coma))
  {
  
  if(renglon==0)
  {
    r.fecha=dato;
  }
  else if(renglon==1)
  {
    r.hora=dato;
  }

  else if(renglon==2)
  {
    r.ipFuente=dato;
  }

  else if(renglon==3)
  {
      r.puertoFuente=dato;
  }

  else if(renglon==4)
  {
    r.hostnameFuente=dato;
  }

  else if(renglon==5)
  {
    r.ipDestino=dato;
  }

  else if(renglon==6)
  {
    r.puertoDestino=dato;
  }

  else if(renglon==7)
  {
    r.hostnameDestino=dato;
  }
  else{
      cout << "Error de apertura del archivo" << endl;
  }
  renglon ++;
  }

  registros.push_back(r);
  }

  /*for(size_t i=0; i<registros.size(); i++)
  {
    registros[i].imprimirValores(registros[i]);
  }*/

  cout<<"Numero de registros es de: "<<registros.size()<<endl; //Cuantos registros ahi
  
  
  Busqueda <Registro> b;

  //pregunta 3
  cout<<"La cantidad de registros de la segunda fecha es : "<<b.BusquedaSecuencial(registros,"11-8-2020")<<endl;

  //pregunta 4
  cout<<"Computadora de Jeffrey : "<<b.BusquedaSecuencial_2(registros,"jeffrey.reto.com")<<endl;
  cout<<"Computadora de Betty : "<<b.BusquedaSecuencial_2(registros,"betty.reto.com")<<endl;
  cout<<"Computadora de Katherine : "<<b.BusquedaSecuencial_2(registros,"katherine.reto.com")<<endl;
  cout<<"Computadora de Scott : "<<b.BusquedaSecuencial_2(registros,"scott.reto.com")<<endl;
  cout<<"Computadora de Benjamin : "<<b.BusquedaSecuencial_2(registros,"benjamin.reto.com")<<endl;
  cout<<"Computadora de Samuel : "<<b.BusquedaSecuencial_2(registros,"samuel.reto.com")<<endl;
  cout<<"Computadora de Raymond : "<<b.BusquedaSecuencial_2(registros,"raymond.reto.com")<<endl;

  //pregunta 6
  cout<<"Computadora de Server: "<<b.BusquedaSecuencial_2(registros,"server.reto.com")<<endl;

  //pregunta 7
  b.BusquedaSecuencial_3(registros,"34.107.163.25");
  b.BusquedaSecuencial_3(registros,"10.105.56.183");
  b.BusquedaSecuencial_3(registros,"72.71.117.167");
  b.BusquedaSecuencial_3(registros,"4.4.4.4");
  b.BusquedaSecuencial_3(registros,"183.149.77.206");
  b.BusquedaSecuencial_3(registros,"103.164.80.217");
    
    
 
  








  

  
}