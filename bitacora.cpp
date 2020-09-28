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
#include "busqueda.h"

using namespace std;


bool compare(Registro &r1, Registro &r2)
{
    // en proceso 

};

void mergeSort(vector<Registro> &arr, int primero, int ultimo)
{
    int medio;
    int size = arr.size();
    if(primero < ultimo) 
    {
      int medio = primero+(ultimo-primero)/2;
      // Se hacen las llamadas recursivas con el vector dividido
      mergeSort(arr, primero, medio);
      mergeSort(arr, medio+1, ultimo);

      int i, j, k, nl, nr;
      int size = arr.size();

      //size of left and right sub-arrays
      nl = medio - primero + 1;
      nr = ultimo - medio;
      vector<Registro> larr, rarr;

      // Para rellenar los sub vectores de la izquierda y derecha
      for(i = 0; i<nl; i++)
      {
        larr.push_back(arr[primero+i]);
      }

      for(j = 0; j<nr; j++)
      {
        rarr.push_back(arr[medio + 1 + j]);
      }

      i = 0; j = 0; k = primero;
      // Para hacer el merge de vectorel temporales con un vector real
      while(i < nl && j < nr) 
      {
         if(compare(larr[i], rarr[j])) 
         {   //    (compare(entrada, entrada)) larr[i] >= rarr[j]
            arr[k] = larr[i];
            i++;
         }
         else
         {
            arr[k] = rarr[j];
            j++;
         }

         k++;
      }

      while(i<nl) 
      { // Para elemento extra en arreglo izquierdo
        arr[k] = larr[i];
        i++; k++;
      }

      while(j<nr) // Para elemento extra en arreglo derecho
      {
        arr[k] = rarr[j];
        j++; k++;
      }
  
   }
   

};





int main()
{
  string fecha, hora , ipfuente, puertofuente, hostnamefuente, ipdestino, puertodestino, hostnamedestino;
  stringstream s;
  vector<Registro> registros; //Declaracion del vector
  ifstream datos_csv("equipo1.csv");
  char coma=  ',';

  //Registro r;
  string line, dato, todo;
  int renglon;
  
  while(getline(datos_csv,line)){
  Registro r;
  stringstream s(line);
  renglon=0;

  while(getline(s,dato,coma)){
  
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
      cout << "Error" << endl;
  }
  renglon ++;
  }

  registros.push_back(r);
  }

  //Se imprime el vector
  for(size_t i=0; i<registros.size(); i++){
    registros[i].imprimirValores(registros[i]);
  }

  

}