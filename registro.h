#ifndef _registro_
#define _registro_
#include <fstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include<vector>

using namespace std;

class Registro
{
    
    public:
    string fecha,hora,ipFuente;
    string puertoFuente;
    string hostnameFuente,ipDestino;
    string puertoDestino;
    string hostnameDestino;
    
    Registro()=default;
    Registro(string fecha_, string hora_, string ipFuente_, int puertoFuente_, string hostnameFuente_, string ipDestino_, int puertoDestino_,string hostnameDestino_){
        fecha=fecha_;
        hora=hora_;
        ipFuente=ipFuente_;
        puertoFuente=puertoFuente_;
        hostnameFuente=hostnameFuente_;
        ipDestino=ipDestino_;
        puertoDestino=puertoDestino_;
        hostnameDestino=hostnameDestino_;

    }
    ~Registro(){};

    void imprimirValores(Registro reg)
    {
        cout << fecha << ", " << hora << ", " << ipFuente << ", " << puertoFuente << ", " << hostnameFuente << ", " << ipDestino << ", " << puertoDestino << ", " << hostnameDestino << endl;

    }

};

template <typename T>
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};

string Redinterna(string ipFuente)
{
    int f;
    f=ipFuente.find_last_of(".\\");
    string ip_total= ipFuente.substr(0,f);
    string cero=".0";
    string ipt=ip_total+cero;
    cout<<"Red interna de la compañia: "<<ipt<<endl;
    cout<<endl;
    return ipt;
};

bool compare_fecha(Registro &a, string date)
{
  
  return a.fecha == date;

}

bool compare_nombre(Registro &a, string nombre)
{
  
  return a.hostnameFuente == nombre;

}

bool compare_ipdestino(Registro &a, string ip)
{
  
  return a.ipDestino == ip;

}

bool compare_ipfuente(Registro &a, string fuente)
{
    string v=Redinterna(a.ipFuente);
    return v==fuente;
}




template<typename T>
class Busqueda
{
    public:
    Busqueda()=default;
    ~Busqueda(){};
    int BusquedaSecuencial(vector<T> e, string n);
    string BusquedaSecuencial_2(vector<T> e, string n);
    void BusquedaSecuencial_3(vector<T> e, string n);
    void BusquedaSecuencial_4(vector<T> e, string n);
    
};


template<typename T>
int Busqueda<T>::BusquedaSecuencial(vector<T> e, string n)
{
    int counter=0;
    for(size_t i=0;i<e.size();i++)
    {
        bool comp=compare_fecha(e[i],n);
        
        if (comp==true)
        {
            counter++;
            
        }
        
    }

    return counter;
};

template<typename T>
string Busqueda<T>::BusquedaSecuencial_2(vector<T> e, string n)
{
    string affirmation;
    for(size_t i=0;i<e.size();i++)
    {
        bool comp=compare_nombre(e[i],n);
        
        if (comp==true)
        {
            affirmation="yes";
            return affirmation;
 
        }
  
    }
    affirmation="no";

    return affirmation;

};

string gethostnamedestino(Registro &a)
{
    if(a.ipDestino=="34.107.163.25")
    {

        return a.hostnameDestino;
    }
    else
    {
        return "ERROR";
    }
    
}


template<typename T>
void Busqueda<T>::BusquedaSecuencial_3(vector<T> e, string n)
{
    int counter;
    for(size_t i=0;i<e.size();i++)
    {
        bool comp=compare_ipdestino(e[i],n);
        
        if (comp==true)
        {
            counter++;
 
        }
  
    }

    cout<<"Numeros de veces que se repite ip destino: "<<counter<<endl;
    
};



template<typename T>
void Busqueda<T>::BusquedaSecuencial_4(vector<T> e, string n)
{
    int counter;

    //for(size_t i=0;i<e.size();i++)
    //{
        
        bool comp=compare_ipfuente(e[2],n);
        
        if (comp==true)
        {
            cout<<"No hay red"<<endl;
            
        }
    
    //}
    

};



vector<int> changepd(vector<Registro> &a)
{
    vector<int> pdestino;
    int p;
    for(size_t i=0;i<a.size();i++)
    {
        p= stoi(a[i].puertoDestino);
        pdestino.push_back(p);
    }
    return pdestino;
    
    

};



//8
template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(vector<T> &arr)
    {
        quicksort(arr, 0, arr.size() - 1);
    };

    void quicksort(vector<T> &arr, int low, int high)
    {
        if (low < high)  
        {  

            int pi = partition(arr, low, high);  
      

            quicksort(arr, low, pi - 1);  
            quicksort(arr, pi + 1, high);  
        }  
    };


    int partition (vector<Registro> &arr, int low, int high)
    {  
        Registro pivot = arr[high]; // pivot  
        int i = (low - 1);     // Index of smaller element  
      
        for (int j = low; j <= high - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            //if (arr[j] < pivot)  
            //{  
            //    i++; // increment index of smaller element
              //  Sorter<T>::swap(i, j, arr);
            //}  
        }  
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);  
    }; 
};    
#endif