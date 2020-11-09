/*
Act/Reto 3 - Actividad Integral sobre el uso de conjuntos y diccionarios (Evidencia Competencia)
__________________________________________________________________________________________________________
Autores:
Equipo 1
Lia Michelle Nuñez A01023743
Ana Sofía Rojas    A01379583

Este reto se basa en el uso de diccionarios y conjuntos, estaremos implementando un código que nos otorgue las respuestas de las preguntas
solicitadas, también estaremos usando partes del código del reto pasado como la clase Conexiones Computadora. 
De igual manera cabe mencionar que se actualizó el .csv que teniamos en los retos anteriores.

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "registro.h"
#include <set>
#include <map>
using namespace std;

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

    vector<string> p2;
    string reto1,reto2, ans, res, name,ip;
    int count, num;
    int counter=0;
    stack<string> stack, s2;
    queue<string> queue;
    set<string> conjunto;
    map<string,ConexionComputadora> diccionario;


    for (size_t i = 0; i < registros.size(); i++)
    {
        reto1=registros[i].getHostnameFuente();
        reto2=registros[i].getHostnameDestino();
        count=reto1.find_first_of(".\\");
        ans=reto1.substr(count,reto1.size());
        if(registros[i].getHostnameDestino() != "-")
        {
            num=reto2.find_first_of(".\\");
            res=reto2.substr(num,reto2.size());
            
            if(res != ".reto.com")
            {
                conjunto.insert(reto2);
            }
            if (diccionario.find(reto1)==diccionario.end())
            {
                ip=registros[i].getIPFuente();

                for (size_t i = 0; i < registros.size(); i++)
                {
                    if (ip==registros[i].getIPFuente())
                    {
                        stack.push(registros[i].getIPDestino());
                        name=registros[i].getHostnameFuente();
                    }
                    if (ip==registros[i].getIPDestino())
                    {
                        queue.push(registros[i].getIPFuente());
                    }                
                }

                ConexionComputadora conexion(ip,name,stack,queue);
                diccionario.insert(make_pair(reto1,conexion));   
            }
        }

        if (ans!=".reto.com")
        {
            conjunto.insert(reto1);
            
        }

    }


    cout<<"Conjunto"<<endl;
    for (auto it=conjunto.begin();it!=conjunto.end(); ++it)
    {
        cout<<" "<< *it<<endl;
        
    }
    cout<<endl;
    cout<<"Diccionario"<<endl;
    map<string, ConexionComputadora>::iterator in = diccionario.begin();
    while (in!=diccionario.end())
    {
        cout<<in->first<<" "<< in->second.getConexionEntrante().size()<<endl;
        in++;
    }


    //Preguntas solicitadas
    cout<<endl;
    cout<<"1. Esta pregunta como decía en el documento se puede sacar con inspeccion visual"<<endl;
    cout<<"Los nombres de los dominios que son anómalos son: "<<endl;
    cout<<"1xtj2ixienaj9muzj52w.com y  25xzybj3yyltpg9jlfla.org"<<endl;
    cout<<endl;

    cout<<"2. Las ip de los dominios de la pregunta 1 son: "<<endl;
    for (size_t i = 0; i < registros.size(); i++)
    {
        if (registros[i].getHostnameDestino()== "1xtj2ixienaj9muzj52w.com")
        {
            p2.push_back(registros[i].getIPDestino());
            cout<<"1xtj2ixienaj9muzj52w.com: "<<registros[i].getIPDestino()<<endl;
        }
        if (registros[i].getHostnameDestino()== "25xzybj3yyltpg9jlfla.org")
        {
           p2.push_back(registros[i].getIPDestino());
           cout<<"25xzybj3yyltpg9jlfla.org: "<<registros[i].getIPDestino()<<endl;
        }
        if (p2.size()==2)
        {
            break;
        }        
        
    }
    cout<<endl;
    //3
    int n=0;

    for (auto in = diccionario.begin(); in != diccionario.end(); in++)
    {
        string s= in->first;
        int c= s.find_first_of(".\\");
        string r= s.substr(c,s.size()-1);
        if (r==".reto.com")
        {
            if (in->second.getConexionEntrante().size()>0)
            {
                n++;
                
            }
            
        }
        
    }
        
    cout<<"3. La cantidad de ips que tienen al menos una conexión entrante son:"<<n<<endl;
    cout<<endl;


    //4

    set<string> ip4;
    for (auto in = diccionario.begin(); in != diccionario.end(); in++)
    {
        s2 = in->second.getConexionEntrante();
        while(s2.empty() == false)
        {
            if(s2.top() != "-")
           { 
                ip4.insert(s2.top());
           }
           s2.pop();
        }
    }

    cout << "4. Las ip unicas de las conexiones entrantes son: "<< ip4.size() << endl;
    cout<<"Las siguientes:"<<endl;
    cout << endl;

    //For para imprimir los ips de la pregunta 4
    for (auto it=ip4.begin();it!=ip4.end(); ++it)
    {
        cout<<" "<< *it<<endl;
        
    }

    cout<<endl;
    cout<<"5. Pregunta sin codigo"<<endl;
    cout<<endl;

    //6
    for (auto it=ip4.begin();it!=ip4.end(); ++it)
    {
        if((*it) == " 173.44.106.80")
        {
            counter++;

        }

        if((*it) == " 165.60.81.107")
        {
            counter++;

        }     
    }

    cout<<"6. Tomaremos los dominios de la pregunta uno y los ips de la pregunta anterior para ver si se han comunicado"<<endl;

    if (counter>0)
    {
        cout<<"Si se han comunicado con los datos encontrados en la pregunta 1."<<endl;

    }

    if (counter==0)
    {
        cout<<"No se han comunicado con los datos encontrados en la pregunta 1."<<endl;
        
    }
    
    


    

}
