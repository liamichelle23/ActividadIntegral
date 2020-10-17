#ifndef CONEXIONES_H
#define CONEXIONES_H

#include <stddef.h>
#include <iostream>
#include <queue>
#include <stack> 
using namespace std;

//Esta clase permite almacenar las conexiones de una ip


/* Nuestros atributos ConexionesEntrantes y ConexionesSalientes de tipo estructura lineal.


ConexionesEntrantes decidimos que fuera stack ya que necesitabamos extraer la última conexion entrante
y como vimos en la clase con stack el ultimo en llegar es el primero en salir.

ConexionesSalientes deciidimos que fuera queue ya que dice que tiene que estar ordenadas desde la
primera a la ultima dando la clave que al revés de las ConexionesEntrantes.

*/

class ConexionComputadora
{
    private:
    string ip;
    string nombre;
    stack<string> conexionEntrante; //pilas
    queue<string> conexionSaliente; //colas o filas

    public:
    ConexionComputadora()=default;


    ConexionComputadora(string _ip,string _nombre, stack <string> _conexionEntrante, queue <string> _conexionSaliente)
    {
        ip=_ip;
        nombre=_nombre;
        conexionEntrante=_conexionEntrante;
        conexionSaliente=_conexionSaliente;

    }
    ~ConexionComputadora(){};

    string getIp()
    {
        return ip;
    }


    string getNombre()
    {
        return nombre;
    }

    stack<string> getConexionEntrante()
    {
        return conexionEntrante;
    }

    queue<string> getConexionSaliente()
    {
        return conexionSaliente;
    }


};




#endif







