/*
Act/Reto 5 - Actividad Integral de Grafos (Evidencia Competencia)
____________________________________
Autores:
Equipo 1
Lia Michelle Nuñez A01023743
Ana Sofía Rojas    A01379583

Este reto se basa en utilizar el conocimiento adquirido del tema de grafos para poder crear uno y que nos ayude a responder las preguntas 
solicitadas para finalizar la última entrega de nuestro reto.

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "registro.h"
#include "graph.h"
#include <set>
#include <map>

using namespace std;

map<string,Graph<string> > crearGrafo1(set<string> fechas, string iptest,
map<string,ConexionComputadora> conComp,map<string,int >&conexiones_por_dia, bool (*compare)(Conexion c))
{

    map<string,Graph<string> >grafos_por_dia; 
    
    for (auto x = fechas.begin(); x !=fechas.end(); x++)
    {
        conexiones_por_dia[*x]=0;
        Graph<string> grafo_hoy;
        for (auto i = conComp.begin(); i != conComp.end(); i++)
        {
            grafo_hoy.add_node(i->first);
        }

        
        for (auto i = conComp.begin(); i != conComp.end(); i++)
        {
            string ipHoy=i->first;
            ConexionComputadora computadoraHoy= i->second;
            vector<Conexion> conexionEntrante=computadoraHoy.getConexionEntrante();
            vector<Conexion> conexionSaliente=computadoraHoy.getConexionSaliente();
            for(size_t j=0; j<conexionEntrante.size(); j++){
                string ipConEntr=conexionEntrante[j].ip;
                string fecha_=conexionEntrante[j].fecha;
                if (*x==fecha_ && compare(conexionEntrante[j])){
                    grafo_hoy.add_edge(ipConEntr, ipHoy);
                    if (ipHoy== iptest){
                        conexiones_por_dia[*x]++;//agregar linea desde ip hasta ipHoy 
                    }
                }
                
            }
            for(size_t j=0; j<conexionSaliente.size(); j++){
                string ipConSal=conexionSaliente[j].ip;
                string fecha_=conexionSaliente[j].fecha;
                if (*x==fecha_ && compare(conexionSaliente[j])){
                    grafo_hoy.add_edge(ipHoy, ipConSal);
                    if (ipConSal== iptest){
                        conexiones_por_dia[*x]++;//agregar linea desde ip hasta ipHoy 
                    }
                }
                
                
            }

        }

        grafos_por_dia[*x]=grafo_hoy; 
    
    }
    return grafos_por_dia;

}


bool es_web(Conexion c){
    return c.puerto=="443";
}

map<string, int> conexionesPorDia(string fecha, vector<Registro<string> > datos){
    map <string, int> dominios;
    for (size_t i = 0; i < datos.size(); i++)
    {
        if (fecha==datos[i].fecha && datos[i].getHostnameDestino()!= "-" ){
                string chain=datos[i].getHostnameDestino();
                int count=chain.find_first_of(".\\");
                string name=chain.substr(count,chain.size());
                if (name!= ".reto.com"){
                    if (dominios.find(chain)==dominios.end()){
                        dominios.insert(make_pair(chain,1));
                    }
                   else{
                        dominios[chain]++; 
                    }
                             
                }                
            
        }    
    }

    return dominios;
}

bool es_ip_interna(Conexion c){
    string fuente=c.ip;
    string ipint="10.105.56";
    for (int i=0; i<ipint.size(); i++){
        if(ipint[i] != fuente[i]){
            return false;
        }
        
    }
    return true;
}


int main(){
    vector<Registro<string> > registros;
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
        Registro<string> reg(fecha, hora, ipFuente, puertoFuente, hostnameFuente, ipDestino, puertoDestino, hostnameDestino);
        registros.push_back(reg);
    }
    datos_csv.close();

    //Iterar los registros y agruparlos por computadora en conexionesComputadora
    map<string,ConexionComputadora> conComp;

    for(size_t i=0; i<registros.size(); i++){
        if(conComp.find(registros[i].getIPFuente()) == conComp.end()){
            ConexionComputadora computadora(registros[i].getIPFuente(), registros[i].getHostnameFuente());
            conComp[registros[i].getIPFuente()]=computadora;
        }
         if(conComp.find(registros[i].getIPDestino()) == conComp.end()){
            ConexionComputadora computadora(registros[i].getIPDestino(), registros[i].getHostnameDestino());
            conComp[registros[i].getIPDestino()]=computadora;
        }
    }

    for(size_t i=0; i<registros.size(); i++){
        string ipFuente_ = registros[i].getIPFuente();
        string ipDestino_ = registros[i].getIPDestino();
        string puertoFuente_=registros[i].getPuertoFuente();
        string puertoDestino_=registros[i].getPuertoDestino();
        string fecha_ = registros[i].getfecha();
        conComp[ipFuente_].insertarConexionSaliente( fecha_,ipDestino_,puertoFuente_);
        conComp[ipDestino_].insertarConexionEntrante(fecha_,ipFuente_, puertoDestino_);
    }

    set<string> entrante;
    set<string> saliente;
    set<string> fechas;
    set<string> ips_fins;
    map<string,int >conexiones_por_dia; 

    for (size_t i=0; i<registros.size(); i++)
    {
        if(registros[i].getfecha() != "" && fechas.find(registros[i].getfecha()) == fechas.end())
        {
            fechas.insert(registros[i].getfecha());
        }

    }
        
    string fuente,destino,host,res,res2,res3;
    int count,count2,count3;

    string A="10.105.56.105";
    string B="165.60.81.107";
    string C="72.71.117.167";

//_________________________________________________________________________________________________________________________________

   //Pregunta 1
   cout<<"Pregunta 1"<<endl;
   map<string,Graph<string> > grafos_por_dia=crearGrafo1(fechas, A, conComp,conexiones_por_dia, es_ip_interna);
    for(auto i=grafos_por_dia.begin(); i != grafos_por_dia.end(); i++){
        string fecha_i=i->first;
        Graph<string> grafo_i=i->second;
        cout << "Fecha: " << fecha_i << endl;
        int vecinosMax=0;
        string ipMax="ninguna";
        for (auto j=conComp.begin(); j !=conComp.end(); j++){
            if(grafo_i.vecinos(j->first) > vecinosMax){
                vecinosMax=grafo_i.vecinos(j->first);
                ipMax=j->first;
            }
        }
        cout << "La ip con más vecinos ese día fue: " << ipMax << endl;
        cout << "A tuvo " << grafo_i.vecinos(A) << " vecinos"<<endl;
        cout << endl;

    }
    // Pregunta 2
    cout<<"Pregunta 2"<<endl;
    cout << "Conexiones por día hacia A" << endl;
    for(auto i=conexiones_por_dia.begin(); i != conexiones_por_dia.end(); i++){
    
        cout << i->first << " : " << i->second << endl;
    }

    cout << endl;

    /*Utilizando un grafo de conexiones a sitios web,
     determina cuántas computadoras se han conectado a B por día.*/

    //Pregunta 3
    cout<<"Pregunta 3"<<endl;
    map<string,Graph<string> > grafos_por_dia_web=crearGrafo1(fechas,B, conComp,conexiones_por_dia, es_web);
    cout << "Conexiones por día a B" << endl;
    for(auto i=conexiones_por_dia.begin(); i != conexiones_por_dia.end(); i++){
    
        cout << i->first << " : " << i->second << endl;
    }

    /*Utilizando el mismo grafo del punto anterior,
    indica cuántas computadoras se han conectado a C por día.*/

   //Pregunta 4
   cout<<"Pregunta 4"<<endl;
    map<string,Graph<string> > grafos_por_dia_C=crearGrafo1(fechas,C, conComp,conexiones_por_dia, es_web);
    cout << "Conexiones por día a C" << endl;
    for(auto i=conexiones_por_dia.begin(); i != conexiones_por_dia.end(); i++){
        cout << i->first << " : " << i->second << endl;
    }

    cout << endl;

};