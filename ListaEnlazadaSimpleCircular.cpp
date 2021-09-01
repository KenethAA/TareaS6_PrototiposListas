#include <iostream>
using namespace std;

struct Nodo{
  int data;
  Nodo *siguiente;
};

void insertarFin(Nodo *&, int);
void insertarInicio(Nodo *&, int);
void mostrarLista(Nodo *);
void eliminarNodoLista(Nodo *&, int);
Nodo *final;
Nodo *lista;

int main() {
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

void insertarFin(Nodo *&lista, int n){
  Nodo *nuevo = new Nodo();
  nuevo->data = n;
  Nodo *aux = lista;

  if(lista != NULL){
    final->siguiente = nuevo;
    nuevo->siguiente = lista;
    final = nuevo;
  }else{
    lista = nuevo;
    nuevo->siguiente = lista;
    final = lista;
  }
}

void insertarInicio(Nodo *&lista, int n){
  Nodo *nuevo = new Nodo();
  nuevo->data = n;
  Nodo *aux = lista;

  if(lista != NULL){
		nuevo->siguiente = lista;
		lista = nuevo;
		final->siguiente = lista;
  }else{
    lista = nuevo;
    nuevo->siguiente = lista;
    final = lista;
  }
}


void mostrarLista(Nodo *lista){
  if(lista != NULL){
    Nodo *listado = lista;
    int elemento=1;
    do{
      cout<<elemento++<<"-"<<listado->data<<", ";
      listado = listado -> siguiente;
    }while(listado != lista);
    cout<<endl;
  }
  cout<<"\nFin de la lista"<<endl;
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
      }else{
        lista = lista -> siguiente;
        final->siguiente = lista; 
        delete aux;   
      }
    }else{
      if(aux == final){
        anterior -> siguiente = lista;
        final = anterior;
      }else{
      	anterior -> siguiente = aux -> siguiente;
      }
      delete aux;
    }
  }
}
