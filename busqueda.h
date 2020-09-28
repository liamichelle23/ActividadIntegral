#ifndef busqueda_h
#define busqueda_h

#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;

template<typename T>
class Busqueda
{
    public:
    Busqueda(){};
    ~Busqueda(){};
    int BusquedaBinaria(vector<T> e, int inicio, int final, int n);
};


template<typename T>
int Busqueda<T>::BusquedaBinaria(vector<T>e, int inicio, int final, int n)
{
    int i;
    if(final<inicio)
    {
        return -1;
    }
    else
    {
        int puntoMedio=(inicio+final)/2;
        if(n==e.at(puntoMedio))
        {
            i=puntoMedio;
        }
        else if(n<e.at(puntoMedio))
        {
            i=BusquedaBinaria(e,inicio,puntoMedio-1,n);
        }
        else
        {
            i=BusquedaBinaria(e,puntoMedio+1,final, n);
        }
    }
    return i;

};



#endif
