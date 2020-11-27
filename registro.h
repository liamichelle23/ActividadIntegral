/* 

Esta clase permite almacenar las conexiones de una ip

Nuestros atributos ConexionesEntrantes y ConexionesSalientes de tipo estructura lineal.


ConexionesEntrantes decidimos que fuera stack ya que necesitabamos extraer la última conexion entrante
y como vimos en la clase con stack el ultimo en llegar es el primero en salir.

ConexionesSalientes deciidimos que fuera queue ya que dice que tiene que estar ordenadas desde la
primera a la ultima dando la clave que al revés de las ConexionesEntrantes.



Estaremos llevando a cabo un diccionario de pares con ayuda de la clase Conexiones Computadora implementada en el reto2, ya que para cada ip deben tener sus
conexiones entrantes y salientes usando la función Conexiones Computadora.

También estaremos creando un conjunto el cual tendra dentro todos los dominios sin reto.com ni los que tienen guion.
Cabe mencionar que un conjunto es una colección de elemento ÚNICOS.

*/

#ifndef _registro_
#define _registro_
#include <fstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include<vector>
#include <stddef.h>
#include <iostream>
using namespace std;

template <class T>
class Registro
{
    
    public:
    string fecha,hora,ipFuente;
    string puertoFuente;
    string hostnameFuente,ipDestino;
    string puertoDestino;
    string hostnameDestino;
    
    Registro()=default;
    Registro(string fecha_, string hora_, string ipFuente_, string puertoFuente_, string hostnameFuente_, string ipDestino_, string puertoDestino_,string hostnameDestino_)
    {
        fecha=fecha_;
        hora=hora_;
        ipFuente=ipFuente_;
        puertoFuente=puertoFuente_;
        hostnameFuente=hostnameFuente_;
        ipDestino=ipDestino_;
        puertoDestino=puertoDestino_;
        hostnameDestino=hostnameDestino_;

    };
    ~Registro(){};

    string getfecha()
    {
        return fecha;
    };

    string getIPFuente()
    {
        return ipFuente;
    };

    string getPuertoFuente()
    {
        return puertoFuente;
    };

    string getHostnameFuente()
    {
        return hostnameFuente;
    };

    string getIPDestino()
    {
        return ipDestino;
    };

    string getPuertoDestino()
    {
        return puertoDestino;
    };

    string getHostnameDestino()
    {
        return hostnameDestino;
    };

    string nameSeqSearch(vector<T> arr, string a)
        {
            string idfk;
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool rito = compName(arr[i], a);
                if (rito == true)
                {
                    idfk = "Found";
                    return idfk;
                }
                
            }
            idfk = "Not found";
            return idfk; 
        }
    bool compName(Registro &a, string name)
        {
            return a.hostF == name;
        }




    void imprimirValores(Registro reg)
    {
        cout << fecha << ", " << hora << ", " << ipFuente << ", " << puertoFuente << ", " << hostnameFuente << ", " << ipDestino << ", " << puertoDestino << ", " << hostnameDestino << endl;

    }


};
class Conexion{
    public:
        string fecha;
        string ip;
        string puerto;
        Conexion(string fecha_, string ip_, string puerto_){
            fecha=fecha_;
            ip=ip_;
            puerto=puerto_;
        };

};

class ConexionComputadora
{
    private:
    string ip;
    string nombre;
    vector<Conexion> conexionEntrante; //pilas
    vector<Conexion> conexionSaliente; //colas o filas

    public:
    ConexionComputadora()=default;

    ConexionComputadora(string ip_, string nombre_){
        ip=ip_; 
        nombre=nombre_;
    }
    ConexionComputadora(string _ip,string _nombre, vector <Conexion> _conexionEntrante, vector <Conexion> _conexionSaliente)
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

    vector<Conexion> getConexionEntrante()
    {
        return conexionEntrante;
    }

    vector<Conexion> getConexionSaliente()
    {
        return conexionSaliente;
    }
    
    void insertarConexionSaliente(string ip, string fecha, string puerto){
        Conexion c(ip, fecha, puerto);
        conexionSaliente.push_back(c);
    }

    void insertarConexionEntrante(string ip, string fecha, string puerto){
        Conexion c(ip, fecha, puerto);
        conexionEntrante.push_back(c);
    }


};




#endif