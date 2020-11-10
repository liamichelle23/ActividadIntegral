/*
Act/Reto 4 - Actividad Integral de BST (Evidencia Competencia)
__________________________________________________________________________________________________________
Autores:
Equipo 1
Lia Michelle Nuñez A01023743
Ana Sofía Rojas    A01379583

En esta cuarta enrega del reto 4 implementaremos diccionarios (map) asi como la estructura de datos vista BTS 
la cual nos permitirá contestar las preguntas que se nos solicitan.

Estaremos implementando 2 funciones solicitadas , la primera será llamada conexionesPorDia que recibirá la fecha, definida desde la primera entrega
Esta función será implementada para que nos regrese un  map<string, int> 
conteniendo la cantidad de conexiones entrantes a cada sitio/página que no sea "-" y que no pertenezca al dominio "reto.com" del día especificado por la fecha de entrada.

La segunda función se llamará  top, la cual recibe un parámetro n de tipo int y una fecha. Esta función debe imprimir los n sitios con más accesos en esa fecha. 
Para ello, puedes usar la función conexionesPorDia y debes agregar los sitios a un BST utilizando como parámetro de ordenamiento la cantidad de conexiones entrantes.

*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "conexiones.h"
#include "bst.h"
#include <set>
using namespace std;
string chain, name, estr;
int counter=0;

map<string, int> conexionesPorDia(string fecha, vector<Registro> function)
{
    map <string, int> dominios;
    for (size_t i = 0; i < function.size(); i++)
    {
        if (fecha==function[i].fecha)
        {
            if (function[i].getHostnameDestino()!= "-")
            {
                chain=function[i].getHostnameDestino();
                int count=chain.find_first_of("\\");
                name=chain.substr(count,chain.size());
                if (name!= ".reto.com")
                {
                    if (dominios.find(chain)==dominios.end())
                    {
                        dominios.insert(make_pair(chain,1));
                    }

                    if (dominios.find(chain)!= dominios.end())
                    {
                        dominios[chain]++;
                       
                    }
                             
                }                
            }
        }    
    }

    for (auto it=dominios.begin();it!=dominios.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
    return dominios;
}


void top(int n,string fecha,vector<Registro> registro)
{
    BinarySearchTree<pair<int,string> > bts;
    map<string,int> dic=conexionesPorDia(fecha,registro);
    for (auto it = dic.begin(); it!= dic.end(); it++)
    {
        bts.insert_node_recursive(make_pair(it->second,it->first));
    }

    bts.print_preorder();
         
}

int main()
{
    vector<Registro> registros;
    string fecha, hora, ipFuente, puertoFuente, hostnameFuente, ipDestino, puertoDestino, hostnameDestino;
    ifstream datos_csv;
    datos_csv.open("nuevo1.csv");
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

    set <string> fech;
    for (size_t i = 0; i < registros.size(); i++)
    {
        fech.insert(registros[i].fecha);
    }
    
    for (auto it=fech.begin();it!=fech.end(); ++it)
    {
         map <string, int> dom_fech = conexionesPorDia(*it, registros);
        cout << "Fechas: " << *it << endl;
    }
    return 0;
}