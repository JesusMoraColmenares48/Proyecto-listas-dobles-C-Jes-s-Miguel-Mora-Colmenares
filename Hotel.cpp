
#include <iostream>
using namespace std;
struct Cliente {
	int Cedula;
	char nombres[30];
	char apellido[20];
	int habitacion;
	Cliente *siguiente;
	Cliente *anterior; 
}*primero,*ultimo;

struct Habitacion{
	int numeroHabitacion;
	bool ocupada = false;
}habitacion[30];

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

void buscarHaciaAdelante(){
	Cliente *clienteActual = new Cliente;
	clienteActual = primero;	
	int cedulaBuscada;
	cout<<"ingrese una cedula "<<endl;
	cin>>cedulaBuscada;
	if(primero!=NULL){
		do{
			cout<<clienteActual->nombres<<endl;
			if(clienteActual->Cedula==cedulaBuscada){
				cout<<"el ultimo cliente que se imprimio es el titular de la cedula: "<<cedulaBuscada<<endl;
				break;	
			}
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);		
	}
}

void mostrarPrimero(){
	cout<<"primero "<<primero->nombres;
}

void cargarHabitaciones(){
	for(int i=0;i<30;i++){
		habitacion[i].numeroHabitacion = i + 1;
	}
}

void mostrarHabitaciones(){
	for(int i=0;i<30;i++){
		cout<<"la habitacion "<<habitacion[i].numeroHabitacion;
		if(!habitacion[i].ocupada){
			cout<<" esta desocupada";
		}else{
			cout<<" esta ocupada";
		}
		cout<<endl;
	}	
}

bool HabitacionDisponible(int numeroDeHabitacionBuscada){
	bool disponible = false;
	for(int i=0;i<30;i++){
		if(habitacion[i].numeroHabitacion==numeroDeHabitacionBuscada && !habitacion[i].ocupada){
			
			disponible = true;
		}
	}
	if(disponible){
		return true;
	}else{
		return false;
	}
}

void ocuparHabitacion(int numeroDeHabitacion){
	for(int i=0;i<30;i++){
		if(habitacion[i].numeroHabitacion==numeroDeHabitacion){
			habitacion[i].ocupada = true;
		}
	}
}
void RegistrarNuevoCliente(){
	int Cedula;
	char nombres[30];
	char apellido[20];
	int habitacion;
	cout<<"porfavor ingrese el nombre del Cliente"<<endl;
	cin.getline(nombres,30,'\n');

	cout<<"porfavor ingrese los apellidos del Cliente"<<endl;
	cin.getline(apellido,20,'\n');
	
	cout<<"porfavor ingrese la cedula del cliente"<<endl;
	cin>>Cedula;
	do{
		cout<<"porfavor ingrese el numero de habitacion para el cliente"<<endl;
		cin>>habitacion;
		if(!HabitacionDisponible(habitacion)&&habitacion<=30){
			cout<<"**LA HABITACION YA SE ENCUENTRA OCUPADA**"<<endl;
			cout<<"**ACONTINUACION SE IMPRIME LA LISTA DE HABITACIONES"<<endl;
			cout<<"**INDICANDO CUALES ESTAN DESOCUPADAS**"<<endl;
			mostrarHabitaciones();
			cout<<"\n"<<endl;
		}else if(habitacion>30){
			cout<<"**DIGITASTE UN NUMERO DE HABITACION NO VALIDO"<<endl;
			cout<<"**EL MAXIMO NUMERO DE LAS HABITACIONES ES 30**"<<endl;
			cout<<"\n"<<endl;
		}				
	}while(!HabitacionDisponible(habitacion)||habitacion>30);
	ocuparHabitacion(habitacion);
	
	insertar(Cedula,nombres,apellido,habitacion);		
}

void eliminarCliente(){
	Cliente *clienteActual = new Cliente;
	clienteActual = primero;	
	int cedulaBuscada;
	cout<<"ingrese la cedula del cliente que quiere eliminar "<<endl;
	cin>>cedulaBuscada;
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
				cout<<"Cliente eliminado compadre"<<endl;
			}
			
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);	
		
		mostrarDelPrimeroAlUltimo();	
	}
}

int main(){

	cargarHabitaciones();
	RegistrarNuevoCliente();
	mostrarHabitaciones();	
	return 0;
}
