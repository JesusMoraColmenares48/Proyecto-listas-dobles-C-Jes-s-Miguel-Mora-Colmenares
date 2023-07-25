#include "funciones.cpp"

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
		ultimo = NuevoCliente;
	}
	
}


void mostrar(){
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
	
	cout<<"porfavor ingrese el numero de habitacion para el cliente"<<endl;
	cin>>habitacion;
	
	insertar(Cedula,nombres,apellido,habitacion);		
}

void

int main(){

	RegistrarNuevoCliente();
	cin.ignore();
	RegistrarNuevoCliente();
	cin.ignore();
	RegistrarNuevoCliente();
	buscar();


	
	return 0;
}