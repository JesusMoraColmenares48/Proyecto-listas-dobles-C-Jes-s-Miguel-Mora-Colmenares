#include "Cliente.cpp"
#include "Hotel.cpp"

void eliminar(){
	int cedulaBuscada;
	cout<<"ingrese la cedula del cliente que quiere eliminar "<<endl;
	cin>>cedulaBuscada;
	Cliente* cliente = eliminarCliente(cedulaBuscada);
	int numeroHabitacion=cliente->habitacion;
	desocuparHabitacion(numeroHabitacion);
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
