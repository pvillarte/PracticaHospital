#include "Paciente.h"

Paciente::Paciente() : Persona() {
}

Paciente::Paciente(int dni, string nombre, string apellido1, string apellido2) :
		Persona(dni, nombre, apellido1, apellido2) {
}

int Paciente::getDni() {
	return dni;
}

ostream& operator<<(ostream& os, Paciente& paciente) {
	os << static_cast<Persona&>(paciente);
	return os;
}
