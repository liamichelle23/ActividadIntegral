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
    Registro(string fecha_, string hora_, string ipFuente_, int puertoFuente_, string hostnameFuente_, string ipDestino_, int puertoDestino_,string hostnameDestino_)
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

//Funciones

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

string compare_pdestino(string a, string n)
{
    
    if( a<n)
    {
        return "-";
        

    }
    else
    {
        return a;
    }
    

}


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
    
};


//Compares (ejemplo rectangulos)
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




       //BUSQUEDAS SECUENCIALES

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
        
        bool comp=compare_ipfuente(e[2],n);
        
        if (comp==true)
        {
            cout<<"No hay red"<<endl;
            
        }    

};



                //ORDENAMIENTO

template <typename T>
class MergeSort : public Sorter<T>
{
    public:
    MergeSort() {};
    ~MergeSort() {};

    void sort(std::vector<T> &arr)
    {
        mergesort(arr, 0, arr.size()-1);
    };


    void mergesort(std::vector<T> &arr, int l, int r)
    {
        if (l < r) {
      
            int m = l + (r-l) / 2;
            

            mergesort(arr, l, m);
            mergesort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }

    void merge(std::vector<T> &arr, int l, int m, int r) 
    { 
        size_t i, j, k; 
        size_t n1 = m - l + 1; 
        size_t n2 = r - m; 
      
        
        T L[n1], R[n2]; 
      
    
        for (i = 0; i < n1; i++) 
            L[i] = arr[l + i]; 
        for (j = 0; j < n2; j++) 
            R[j] = arr[m + 1 + j]; 
      
        
        i = 0;  
        j = 0;  
        k = l; 
        while (i < n1 && j < n2) { 
            if (L[i] <= R[j]) { 
                arr[k] = L[i]; 
                i++; 
            } 
            else { 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        } 
      
      
        while (i < n1) { 
            arr[k] = L[i]; 
            i++; 
            k++; 
        } 
      
        while (j < n2) { 
            arr[k] = R[j]; 
            j++; 
            k++; 
        } 
    };
};
#endif