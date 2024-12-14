#include "Persona.h"

Persona::Persona(int dni, string nombre, string apellido1, string apellido2) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellido1 = apellido1;
	this->apellido2 = apellido2;
}

string Persona::getNombreCompleto()
{
	return (nombre+" "+apellido1+" "+apellido2);
}

istream& operator>>(istream& is, Persona& persona) {
	cout << "DNI (sin letra): ";
	is >> persona.dni;
	cout << "Nombre: ";
	is >> persona.nombre;
	cout << "Primer apellido: ";
	is >> persona.apellido1;
	cout << "Segundo apellido: ";
	is >> persona.apellido2;
	return is;
}

ostream& operator<<(ostream& os, Persona& persona) {
	os << left << setw(20) << setfill(' ') << persona.dni
		<< left << setw(20) << setfill(' ') << persona.nombre
		<< left << setw(20) << setfill(' ') << persona.apellido1
		<< left << setw(20) << setfill(' ') << persona.apellido2;
	return os;
}
