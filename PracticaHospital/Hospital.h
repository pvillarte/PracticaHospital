#pragma once
#include "Cita.h"
#include "Paciente.h"
#include "Medico.h"
#include "Paginador.h"

class Hospital {
private:
	vector<Cita>* citas;
	vector<Paciente>* pacientes;
	vector<Medico>* medicos;
	Paginador<Paciente> pacientesPaginados;
	Paginador<Medico> medicosPaginados;
	void addPaciente(const Paciente& p);
	void addMedico(const Medico& m);
	void addCita(const Cita& c);
	bool contains(const string&, const string&);
public:
	Hospital();
	Hospital(const Hospital& original);
	~Hospital();
	void inicializarValores();
	void addPaciente();
	void addMedico();
	void menuBusquedaPersonas();
	void menuListados();
	void getionarMedicos();

	Hospital& operator=(const Hospital& opDcha);
};

