#include "Cliente.cpp"
#include "Hotel.cpp"

void invalidInput(){
	cin.clear();
	cin.ignore();
	cout << "####################" << endl;
	cout << "# Accion no valida #" << endl;
	cout << "####################" << endl;
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
		if(!cin.good()){
			invalidInput();
		}
		cout<<"Por favor ingrese la cedula del cliente: ";
		cin>>Cedula;
	} while(!cin.good());
	do{

		do{
			if(!cin.good()){
				invalidInput();
			}
			cout<<"Por favor ingrese el numero de habitacion para el cliente: ";
			cin>>habitacion;
		} while(!cin.good());

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

void editarCliente(){
	int cedulaCliente;
	int nuevaHabitacion;

	cout<<"Ingrese la cedula del cliente que quiere editar:"<<endl;
	cin>>cedulaCliente;
	cout << "ingrese la habitacion que desea asignar" << endl;
	cin >> nuevaHabitacion;

	Cliente* cliente = buscarHaciaAdelante(cedulaCliente);
	desocuparHabitacion(cliente->habitacion);
	ocuparHabitacion(nuevaHabitacion);
	// mostrarHabitaciones();

}
