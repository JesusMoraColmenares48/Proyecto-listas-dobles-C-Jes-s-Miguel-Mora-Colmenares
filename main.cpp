#include "Utils.cpp" 

int main(){
	int accion;
	int continuar=1;
	cargarHabitaciones();
	while(continuar==1){
		cout << "Ingrese la accion que desea realizar:" << endl;
		cout << "1. Registrar nuevo cliente." << endl;
		cout << "2. Mostrar habitaciones ocupadas." << endl;
		cout << "3. Reasignar habitación y editar cliente." << endl;
		cout << "4. Eliminar cliente." << endl;
		cout << "Ingrese su opcion: ";
		cin >> accion;
		if(!cin.good()){
			invalidInput();
			continue;
		}
		switch(accion){
			case 1:
				registrarNuevoCliente();
				break;
			case 2:
				mostrarHabitaciones();	
				break;
			case 3:
				editarCliente();
				break;
			case 4:
				eliminar();
				break;
			default:
				cout << "Accion no valida" << endl;
				break;
		}
		do {
			if(!cin.good()){
				invalidInput();
				continue;
			}
			cout << "¿Desea seguir realizando operaciones?" << endl;
			cout << "1. Si." << endl;
			cout << "2. No." << endl;
			cout << "Ingrese su opcion: ";
			cin >> continuar;
			cin.ignore();
		}while(continuar!=1&&continuar!=2);
	}
	return 0;
}
