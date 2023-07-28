#include "string.h"
#include "iostream"


using namespace std;
struct Cliente {
	int Cedula;
	char nombres[30];
	char apellido[20];
	int habitacion;
	Cliente *siguiente;
	Cliente *anterior; 
}*primero,*ultimo;

void insertar(int numeroCedula, char nombres[], char apellido[], int numeroDeHabitacion){
	Cliente *NuevoCliente = new Cliente;
	NuevoCliente->Cedula = numeroCedula;
	strcpy(NuevoCliente->nombres,nombres);
	strcpy(NuevoCliente->apellido,apellido);
	NuevoCliente->habitacion = numeroDeHabitacion;
	
	if(primero==NULL){
		primero = NuevoCliente;
		primero->siguiente = primero;
		ultimo = NuevoCliente;
	}else{
		ultimo->siguiente = NuevoCliente;
		NuevoCliente->siguiente = primero;
		NuevoCliente->anterior = ultimo;
		ultimo = NuevoCliente;
	}
	
}


void mostrarDelUltimoAlPrimero(){
	Cliente *clienteActual = new Cliente;
	clienteActual = ultimo;	
	if(clienteActual->anterior!=NULL){
		do{
			cout<<clienteActual->nombres<<endl;
			clienteActual = clienteActual->anterior;
		}while(clienteActual!=primero);
		cout<<clienteActual->nombres<<endl;
	}
}


void mostrarDelPrimeroAlUltimo(){
	Cliente *clienteActual = new Cliente;
	clienteActual = primero;	
	if(primero!=NULL){
		do{
			cout<<clienteActual->nombres<<endl;
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);
		
	}
}

Cliente* buscarHaciaAdelante(int cedulaBuscada){
	Cliente *clienteActual = new Cliente;
	clienteActual = primero;	
	bool encontrado = false;
	if(primero!=NULL){
		do{
			// cout<<clienteActual->nombres<<endl;
			if(clienteActual->Cedula==cedulaBuscada){
				// cout<<"el ultimo cliente que se imprimio es el titular de la cedula: "<<cedulaBuscada<<endl;
				encontrado=true;
				break;	
			}
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);		
		if(!encontrado) return NULL;
	}
	return clienteActual;
}

void mostrarPrimero(){
	cout<<"primero "<<primero->nombres;
}


Cliente* eliminarCliente(int cedulaBuscada){
	Cliente *clienteActual = new Cliente;
	Cliente *clienteEliminado = new Cliente;
	clienteActual = primero;	
	if(primero!=NULL){
		do{
			if(clienteActual->Cedula==cedulaBuscada){
				if(clienteActual == primero){
					primero = clienteActual->siguiente;
					ultimo->siguiente = primero;
				}else if(clienteActual == ultimo){
					ultimo = clienteActual->anterior;
					ultimo->siguiente = primero;
				}else{
					Cliente *clienteAnterior = new Cliente;
					clienteAnterior = clienteActual->anterior;
					clienteActual = clienteActual->siguiente;
					clienteActual->anterior = clienteAnterior;
					clienteAnterior->siguiente = clienteActual;
				}
				
				clienteEliminado = clienteActual;
				cout<<"Cliente eliminado compadre"<<endl;
			}
			
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);	
		
		mostrarDelPrimeroAlUltimo();	
	}
	return clienteEliminado;
}
