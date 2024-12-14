#include "Medico.h"
Medico::Medico() : Persona() {
	this->especialidad = "Sin especialidad";
}

Medico::Medico(int dni, string nombre, string apellido1, string apellido2, string especialidad) :
		Persona(dni, nombre, apellido1, apellido2) {
	this->especialidad = especialidad;
}

string Medico::getEspecialidad() {
	return especialidad;
}

ostream& operator<<(ostream& os, Medico& medico) {
	os << static_cast<Persona&>(medico);
	os << left << setw(20) << setfill(' ') << medico.especialidad;
	return os;
}

istream& operator>>(istream& is, Medico& medico) {
	is >> static_cast<Persona&>(medico);
	cout << "Especialidad: ";
	is >> medico.especialidad;
	return is;
}
