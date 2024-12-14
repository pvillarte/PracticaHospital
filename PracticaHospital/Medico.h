#pragma once
#include "Persona.h"
#include <iomanip>

class Medico : public Persona {
private:
	string especialidad;
public:
	Medico();
	Medico(int dni, string nombre, string apellido1, string apellido2, string especialidad);

	string getEspecialidad();
	friend ostream& operator<<(ostream& os, Medico& medico);
	friend istream& operator>>(istream& is, Medico& medico);
};

