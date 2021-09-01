//Lista simple enlazada
#include <iostream>

using namespace std;

class Nodo{
    private:
        string data;
    public:
        void insertarDatos();
        string mostrarDatos();
        Nodo *siguiente;
};

void insertarLista(Nodo *&);
void mostrarLista(Nodo *);
void eliminarLista(Nodo *&);

Nodo *lista=NULL;

int main(){
    insertarLista(lista);
    insertarLista(lista);
    insertarLista(lista);
    mostrarLista(lista);
    eliminarLista(lista);
    cout<<"Se elimino elementos de la lista"<<endl;
    mostrarLista(lista);
    return 0;
}

void Nodo::insertarDatos(){
    cout<<"Ingrese la informacion: ";
    cin>>this->data;
    cout<<"Informacion registrada con exito!"<<endl;
}

string Nodo::mostrarDatos(){
    return this->data;
}

void insertarLista(Nodo *&lista){
    Nodo *nuevo_dato = new Nodo();
    nuevo_dato->insertarDatos();
    
    Nodo *a1 = lista;
    Nodo *a2;
    
    while(a1 != NULL){
        a2=a1;
        a1=a1-> siguiente;
    }
    
    if(lista == a1){
        lista=nuevo_dato;
    }else{
        a2->siguiente = nuevo_dato;
    }
    nuevo_dato->siguiente = a1;
    cout<<"Elemento insertado a la lista correctamente"<<endl;
}

void mostrarLista(Nodo *lista){
    Nodo *listado = new Nodo();
    listado =lista;
    int elemento=1;
    while(listado != NULL){
        cout<<elemento++<<"-"<<listado->mostrarDatos()<<", ";
        listado= listado->siguiente;
    }
    cout<<"\nFin de la lista"<<endl;
}

void eliminarLista(Nodo *&lista){
    Nodo *listado = lista;
    while(listado!=NULL){
        listado = lista->siguiente;
        delete lista;
        lista = listado;
    }
}
