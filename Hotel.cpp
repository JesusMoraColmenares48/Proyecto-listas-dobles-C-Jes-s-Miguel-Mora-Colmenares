#include <iostream>
#include <string.h>
using namespace std;

struct Habitacion{
	int numeroHabitacion;
	bool ocupada = false;
}habitacion[30];


void cargarHabitaciones(){
	for(int i=0;i<30;i++){
		habitacion[i].numeroHabitacion = i + 1;
	}
}

void mostrarHabitaciones(){
	cout << "#########################" << endl;
	cout << "# Habitaciones ocupadas #" << endl;
	cout << "#########################" << endl;
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

bool habitacionDisponible(int numeroDeHabitacionBuscada){
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
void desocuparHabitacion(int numeroDeHabitacion){;
	for(int i=0;i<30;i++){
		if(habitacion[i].numeroHabitacion==numeroDeHabitacion){
			habitacion[i].ocupada = false;
		}
	}
}
