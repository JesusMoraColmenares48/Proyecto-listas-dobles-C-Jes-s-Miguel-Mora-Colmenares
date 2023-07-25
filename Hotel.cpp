#include "funciones.cpp"

struct Cliente {
	int Cedula;
	char nombres[30];
	char apellidoP[20];
	char apellidoM[20];
	int habitacion;
	bool desayuno;
	bool tdc;
	Cliente *siguiente;
	Cliente *anterior; 
}*primero,*ultimo;



void insertar(int numeroCedula){
	
	Cliente *NuevoCliente = new Cliente;
	NuevoCliente->Cedula = numeroCedula;
	
	if(primero==NULL){
		primero = NuevoCliente;
		primero->siguiente = primero;
		ultimo = NuevoCliente;
	}else{
		ultimo->siguiente = NuevoCliente;
		NuevoCliente->siguiente;
		ultimo = NuevoCliente;
	}
	
}


void mostrar(){
	
	Cliente *clienteActual = new Cliente;
	clienteActual = primero;	
	if(primero!=NULL){
		do{
			cout<<clienteActual->Cedula<<endl;
			clienteActual = clienteActual->siguiente;
		}while(clienteActual!=primero);
	}
	

}

void mostrarPrimero(){
	cout<<"primero"<<primero->Cedula;
}

int main(){
	
	insertar(30);
	insertar(70);
	insertar(23);
	insertar(33);
	insertar(12);

	mostrarPrimero();

	
	return 0;
}