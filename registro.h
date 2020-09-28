#ifndef _registro_
#define _registro_
#include <fstream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Registro{
    
    public:
    string fecha,hora,ipFuente;
    string puertoFuente;
    string hostnameFuente,ipDestino;
    string puertoDestino;
    string hostnameDestino;
    
    Registro()=default;
    Registro(string fecha_, string hora_, string ipFuente_, string puertoFuente_, string hostnameFuente_, string ipDestino_, string puertoDestino_,string hostnameDestino_){
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

    void imprimirValores(Registro reg){
        cout << fecha << ", " << hora << ", " << ipFuente << ", " << puertoFuente << ", " << hostnameFuente << ", " << ipDestino << ", " << puertoDestino << ", " << hostnameDestino << endl;

    }
};
    
#endif