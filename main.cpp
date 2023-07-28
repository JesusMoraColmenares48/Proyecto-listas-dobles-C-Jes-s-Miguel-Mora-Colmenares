#include "Utils.cpp" 

int main(){
	int accion;
	int continuar=1;
	cargarHabitaciones();
	while(continuar==1){
		cout << "Ingrese la accion que desea realizar:" << endl;
		cout << "1. Registrar nuevo cliente." << endl;
		cout << "2. Mostrar habitaciones ocupadas." << endl;
		cout << "3. Reasignar habitacion y editar cliente." << endl;
		cout << "4. Mostrar clientes del primero a ultimo." << endl;
		cout << "5. Mostrar clientes del ultimo al primero." << endl;
		cout << "6. Eliminar a un cliente." << endl;
		cout << "Ingrese su opcion: ";
		cin >> accion;
		bool isInputValid = validateInput();
		if(!isInputValid) continue;
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
				mostrarDelPrimeroAlUltimo();
				break;	
			case 5:
				mostrarDelUltimoAlPrimero();
				break;	
			case 6:
				eliminar();
				break;
			default:
				cout << "Accion no valida" << endl;
				break;
		}
		do {
			isInputValid = validateInput();
			if(!isInputValid) continue;
			cout << "----------------------------------------" << endl;
			cout << "Â¿Desea seguir realizando operaciones?" << endl;
			cout << "1. Si." << endl;
			cout << "2. No." << endl;
			cout << "Ingrese su opcion: ";
			cin >> continuar;
			cin.ignore();
			cout<<endl;
		}while(continuar!=1&&continuar!=2);
	}
	return 0;
}
