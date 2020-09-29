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
template <typename T>

void print_vector(vector<T> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}



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


  //pregunta 1
  cout<<endl;
  cout<<"Numero de registros es de: "<<registros.size()<<endl; 
  cout<<endl;
  

  Busqueda <Registro> b;

  //pregunta 2
  cout<<"La cantidad de registros de la segunda fecha es : "<<b.BusquedaSecuencial(registros,"11-8-2020")<<endl;
  cout<<endl;

  //pregunta 3
  cout<<"Computadora de Jeffrey : "<<b.BusquedaSecuencial_2(registros,"jeffrey.reto.com")<<endl;
  cout<<"Computadora de Betty : "<<b.BusquedaSecuencial_2(registros,"betty.reto.com")<<endl;
  cout<<"Computadora de Katherine : "<<b.BusquedaSecuencial_2(registros,"katherine.reto.com")<<endl;
  cout<<"Computadora de Scott : "<<b.BusquedaSecuencial_2(registros,"scott.reto.com")<<endl;
  cout<<"Computadora de Benjamin : "<<b.BusquedaSecuencial_2(registros,"benjamin.reto.com")<<endl;
  cout<<"Computadora de Samuel : "<<b.BusquedaSecuencial_2(registros,"samuel.reto.com")<<endl;
  cout<<"Computadora de Raymond : "<<b.BusquedaSecuencial_2(registros,"raymond.reto.com")<<endl;
  cout<<endl;

   //4
  b.BusquedaSecuencial_4(registros,"-");


  //pregunta 5
  cout<<"Computadora de Server: "<<b.BusquedaSecuencial_2(registros,"server.reto.com")<<endl;
  cout<<endl;
  
  //pregunta 6
  b.BusquedaSecuencial_3(registros,"34.107.163.25");
  b.BusquedaSecuencial_3(registros,"10.105.56.183");
  b.BusquedaSecuencial_3(registros,"72.71.117.167");
  b.BusquedaSecuencial_3(registros,"4.4.4.4");
  b.BusquedaSecuencial_3(registros,"183.149.77.206");
  b.BusquedaSecuencial_3(registros,"103.164.80.217");
  cout<<endl;
  cout<<"El mail de la compañia es: "<<gethostnamedestino(registros[6])<<endl;

  //7

    vector<string> pdestino;
    string p;
    for(size_t i=0; i<registros.size(); i++)
    {
        p=registros[i].puertoDestino;
        pdestino.push_back(p);
  
    }

    vector<int> menoresamil;
    
    for (size_t i = 0; i < pdestino.size(); i++)
    {
      string g= compare_pdestino(pdestino[i],"1000");
      
      if (g!="-")
      { 
       int n=stoi(g);
        menoresamil.push_back(n);
      }
      i++;
      
    }

    cout<<"Vector con puertos Destinos menores a mil y sin ordenar"<<endl;
    print_vector(menoresamil);
    cout<<endl;

  vector<int> arr_2(menoresamil);

  MergeSort<int> m;

  m.mergesort(arr_2,0,arr_2.size()-1);
  cout<<"Vector ordenado: "<<endl;
  print_vector(arr_2);

  
}