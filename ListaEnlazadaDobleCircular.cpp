#include <iostream>
using namespace std;

struct Nodo{
  int data;
  Nodo *siguiente;
  Nodo *anterior;
};

void insertarFin(Nodo *&, int);
void insertarInicio(Nodo *&, int);
void mostrarLista(Nodo *);
void eliminarNodoLista(Nodo *&, int);
Nodo *lista=NULL;
Nodo *final=NULL;
Nodo *inicio=NULL;

int main() {
  int dato;
  insertarFin(lista, 60);
  insertarInicio(lista, 40);
  insertarFin(lista, 85);
  insertarFin(lista, 52);
  insertarInicio(lista, 90);
  mostrarLista(lista);
  cout<<"Eliminando un nodo"<<endl;
  eliminarNodoLista(lista, 85);
  mostrarLista(lista);
}


void insertarInicio(Nodo *&lista, int n){
  Nodo *nuevo = new Nodo();
  nuevo->data = n;
  if(lista != NULL){
    nuevo->siguiente = inicio;
    inicio->anterior = nuevo;
    nuevo->anterior = final;
    inicio = nuevo;
    final->siguiente = inicio;
    lista = inicio;
  }else{
    final = nuevo;
    inicio = nuevo;
    nuevo->siguiente = inicio;
    nuevo->anterior = final;
    lista = nuevo;
  }
}


void insertarFin(Nodo *&lista, int n){
  Nodo *nuevo = new Nodo();
  nuevo->data = n;
  if(lista != NULL){
    final->siguiente = nuevo;
    nuevo->anterior = final;    
    nuevo->siguiente = inicio;
    inicio->anterior = nuevo;
    final = nuevo;
  }else{
    final = nuevo;
    inicio = nuevo;
    nuevo->siguiente = inicio;
    nuevo->anterior = final;
    lista = nuevo;
  }
}



void mostrarLista(Nodo *lista){
  if(lista != NULL){
    Nodo *listado = lista;
    int elemento=1;
    do{
      cout<<elemento++<<"- dato: "<<listado->data<<" siguiente:";
        (listado->siguiente == NULL) ? cout<<"vacio" : cout<< (listado->siguiente)->data;
        cout<<" anterior: ";
        (listado->anterior == NULL) ? cout<<"vacio" : cout<< (listado->anterior)->data;
        cout<<endl;
        listado= listado->siguiente;
    }while(listado != inicio);
    cout<<"\nFin de la lista"<<endl;
  }
}


void eliminarNodoLista(Nodo *&lista, int n){
  if(lista != NULL){
    Nodo *aux = lista;
    Nodo *anterior = NULL;
  
    while(aux->siguiente != lista  && aux -> data != n){ 
      anterior = aux;
      aux = aux -> siguiente; 
    }

    if(aux == final && aux -> data != n){
      cout<<"Valor no encontrado"<<endl;
    }else if(anterior == NULL){
      if(aux->siguiente == lista){
      	lista = NULL;
        final = NULL;
        inicio = NULL;
      }else{
        lista = aux -> siguiente;
        inicio = lista;
        inicio->anterior = final;
        final->siguiente = inicio; 
      }
      delete aux;
    }else{
      if(aux == final){
        anterior -> siguiente = inicio;
        final = anterior;
        inicio->anterior = final;
      }else{
      	anterior -> siguiente = aux -> siguiente;
        aux->siguiente->anterior = anterior;
      }
      delete aux;
    }
  }
}
