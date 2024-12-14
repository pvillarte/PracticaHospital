#pragma once
#include "Cita.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Persona {
protected:
	int dni;
	string nombre;
	string apellido1;
	string apellido2;
public:
	Persona(int dni=0, string nombre="", string apellido1="", string apellido2="");
	//virtual void actualizarDatos() = 0;
	friend istream& operator>>(istream& is, Persona& persona);
	friend ostream& operator<<(ostream& os, Persona& persona);
	string getNombreCompleto();
};

