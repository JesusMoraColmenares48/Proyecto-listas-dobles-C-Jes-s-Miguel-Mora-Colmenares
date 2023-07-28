#include "Cliente.cpp"
#include "Hotel.cpp"
//#include <bits/types/error_t.h>
#include <system_error>

bool validateInput(){
	if(!cin.good()){
		cin.clear();
		cin.ignore();
		cout << "\n ####################" << endl;
		cout << "# Accion no valida #" << endl;
		cout << "####################" << endl;
		return false;
	}
	return true;
}
void eliminar(){
	int cedulaBuscada;
	cout<<"ingrese la cedula del cliente que quiere eliminar "<<endl;
	cin>>cedulaBuscada;
	Cliente* cliente = eliminarCliente(cedulaBuscada);
	int numeroHabitacion=cliente->habitacion;
	desocuparHabitacion(numeroHabitacion);
}
void registrarNuevoCliente(){
	cin.ignore();
	int Cedula;
	char nombres[30];
	char apellido[20];
	int habitacion;
	cout<<"Por favor ingrese el nombre del Cliente: ";
	cin.getline(nombres,30,'\n');

	cout<<"Por favor ingrese los apellidos del Cliente: ";
	cin.getline(apellido,20,'\n');
	
	do{
		validateInput();
		cout<<"Por favor ingrese la cedula del cliente: ";
		cin>>Cedula;
	} while(!cin.good());
	do{

		do{
			validateInput();
			cout<<"Por favor ingrese el numero de habitacion para el cliente: ";
			cin>>habitacion;
		} while(!cin.good());

		if(!habitacionDisponible(habitacion)&&habitacion<=30){
			cout<<endl;
			cout<<"**LA HABITACION YA SE ENCUENTRA OCUPADA**"<<endl;
			cout<<"**ACONTINUACION SE IMPRIME LA LISTA DE HABITACIONES"<<endl;
			cout<<"**INDICANDO CUALES ESTAN DESOCUPADAS**"<<endl;
			cout<<endl;
			mostrarHabitaciones();
			cout<<"\n"<<endl;
		}else if(habitacion>30){
			cout<<"**DIGITASTE UN NUMERO DE HABITACION NO VALIDO"<<endl;
			cout<<"**EL MAXIMO NUMERO DE LAS HABITACIONES ES 30**"<<endl;
			cout<<"\n"<<endl;
		}				
	}while(!habitacionDisponible(habitacion)||habitacion>30);
	ocuparHabitacion(habitacion);
	
	insertar(Cedula,nombres,apellido,habitacion);		
}

void editarCliente(){
	int cedulaCliente;
	int nuevaHabitacion;

	int opcion;
	char nombre[30];
	char apellido[20];
	do{
		validateInput();
		cout<<"Ingrese la cedula del cliente que quiere editar:";
		cin>>cedulaCliente;
	} while(!cin.good());
	Cliente* cliente = buscarHaciaAdelante(cedulaCliente);
	do{
		validateInput();
		cout<<"Ingrese el dato del cliente que desea editar: ";
		cout << "\n1. Nombre" << endl;
		cout << "2. Apellido" << endl;
		cout << "3. Habitacion" << endl;
		cout << "Ingrese su opcion: ";
		cin>>opcion;
	} while(!cin.good());

	switch(opcion){
		case 1:
			cout << "Ingrese el nombre nuevo: ";
			cin.ignore();
			cin.getline(nombre,30,'\n');
			strcpy(cliente->nombres, nombre);
			break;
		case 2:
			cout << "Ingrese el apellido nuevo: ";
			cin.getline(apellido,20,'\n');
			strcpy(cliente->apellido, apellido);
			break;
		case 3:
			cout << "Ingrese la habitacion que desea asignar: ";
			cin >> nuevaHabitacion;

			desocuparHabitacion(cliente->habitacion);
			ocuparHabitacion(nuevaHabitacion);
			cliente->habitacion=nuevaHabitacion;
			cout << "Cliente " << cliente->nombres <<" "<< cliente->apellido << " reasignado a la habitaciÃ³n nÃºmero " << nuevaHabitacion << endl;

			break;
	}

	if(cliente==NULL){
		cout << "###############################" << endl;
		cout << "# ERROR: " << "el cliente no existe #" << endl;
		cout << "###############################" << endl;
		return;
	}

}
