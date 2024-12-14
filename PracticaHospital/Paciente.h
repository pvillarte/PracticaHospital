#pragma once
#include "Persona.h"

class Paciente : public Persona {
protected:
public:
	Paciente();
	Paciente(int dni, string nombre, string apellido1, string apellido2);

	int getDni();
	friend ostream& operator<<(ostream& os, Paciente& paciente);
};

