/*
Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)
_______________________________________________________________________________________________
Este codigo es una implementación donde se pone en práctica lo visto de estructuras lineales
para ayudarnos a reponer las preguntas planteadas.
Autores:
Equipo 1
Lia Michelle Nuñez A01023743
Ana Sofía Rojas    A01379583

*/



#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "registro.h"
#include "registro.h"
#include "conexiones.h"

using namespace std;

template<typename T>
void imprimirVector(vector<T> arr)
{
  for(size_t i=0; i<arr.size(); i++)
  {
    arr[i].imprimirValores(arr[i]);
  }
}


int main(){

    vector<Registro> registros;
    string fecha, hora, ipFuente, puertoFuente, hostnameFuente, ipDestino, puertoDestino, hostnameDestino;
    ifstream datos_csv;
    datos_csv.open("equipo1.csv");
    while (datos_csv.good())
    {
        getline(datos_csv, fecha, ',');
        getline(datos_csv, hora, ',');
        getline(datos_csv, ipFuente, ',');
        getline(datos_csv, puertoFuente, ',');
        getline(datos_csv, hostnameFuente, ',');
        getline(datos_csv, ipDestino, ',');
        getline(datos_csv, puertoDestino, ',');
        getline(datos_csv, hostnameDestino, '\n');
        Registro reg(fecha, hora, ipFuente, puertoFuente, hostnameFuente, ipDestino, puertoDestino, hostnameDestino);
        registros.push_back(reg);
    }
    datos_csv.close();



    int i=0;
    string busquedaIP="ipfuente";
    while (busquedaIP=="ipfuente" || busquedaIP=="-")
    {
        i++;
        busquedaIP=registros[i].getIPFuente();
    }
    int ultimoPunto = busquedaIP.find_last_of(".");
    string ipComp= busquedaIP.substr(0,ultimoPunto);
    int extensionIP=0;

    while(extensionIP<1 || extensionIP>150)
    {
        cout << "Ingrese un número del 1 al 150 para generar la ip interna correspondiente: ";
        cin >> extensionIP;
    }
    string ipFinal= ipComp + "." + to_string(extensionIP);
    
    vector<ConexionComputadora> conexiones;
    stack<string> conEntr; //Conexiones Entrantes
    queue<string> conSal; //Conexiones Salientes
    string nombre;

    for(int j=0; i<=registros.size(); i++)
    {
            if(ipFinal==registros[i].getIPFuente())
            {
                conSal.push(registros[i].getIPDestino());
                nombre=registros[i].getHostnameFuente();
            }
            if(ipFinal==registros[i].getIPDestino())
            {
                conEntr.push(registros[i].getIPFuente());
                nombre=registros[i].getHostnameDestino();
            }
    }
    ConexionComputadora conexionesIP(ipFinal, nombre, conEntr, conSal);


    //Pregunta 1. ¿Qué ip estás usando?
    cout << "La ip que se está utilizando es: " << ipFinal << endl;

    //Pregunta 2. ¿Cuál fue la ip de la última conexión que recibió esta computadora? 
    
    string ultimaConexion=conexionesIP.getConexionEntrante().top();
    cout << "La última conexión que recibió esta computadora es de la ip: " << ultimaConexion <<endl;

    //¿Es interna o externa?
    int ultimoPunto2 = ultimaConexion.find_last_of(".");
    string iporigen = ultimaConexion.substr(0,ultimoPunto2);
    if(ipComp==iporigen){
        cout << "La ultima conexion es interna." <<endl;
    }
    else{
        cout <<"La última conexión es externa." <<endl;
    }

    //Pregunta 3. ¿Cuántas conexiones entrantes tiene esta computadora?
    cout << "Conexiones entrantes de esta computadora: " << conexionesIP.getConexionEntrante().size()<< endl;
    
    //Pregunta 4. ¿Cuántas conexiones salientes tiene esta computadora?
    cout << "Conexiones salientes de esta computadora: " << conexionesIP.getConexionSaliente().size()<< endl;
    











}
