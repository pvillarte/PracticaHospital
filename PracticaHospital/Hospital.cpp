#include "Hospital.h"

void Hospital::inicializarValores() {
	addPaciente(Paciente(17438604, "Pablo", "Villarte", "Diestre"));
	addPaciente(Paciente(24543234, "Pepe", "Garcia", "Sancho"));
	addPaciente(Paciente(23232321, "Marco", "Sancho", "Ramirez"));
	addPaciente(Paciente(12323134, "Jose", "Luna", "Fron"));
	addPaciente(Paciente(24533234, "Natalia", "Garcia", "Sancho"));
	addPaciente(Paciente(23112321, "Pedro", "Sancho", "Ramirez"));
	addPaciente(Paciente(12323986, "Angelines", "Luna", "Fron"));
	addPaciente(Paciente(23423424, "Marta", "Garcia", "Sancho"));
	addPaciente(Paciente(23231321, "Lorena", "Garcia", "Ramirez"));
	addPaciente(Paciente(88684286, "Lupita", "Fita", "Cinturita"));
	addPaciente(Paciente(13131321, "Pepo", "Pipo", "Pepo"));
	addPaciente(Paciente(56543267, "Pipo", "Pipito", "Pepone"));
	addMedico(Medico(17438604, "Pablo", "Villarte", "Diestre", "inutil"));
	addMedico(Medico(24543234, "Pepe", "Garcia", "Sancho", "psiquiatria"));
	addMedico(Medico(23232321, "Marco", "Sancho", "Ramirez", "medicina de familia"));
	addMedico(Medico(12323134, "Jose", "Luna", "Fron", "medicina de familia"));
	addMedico(Medico(24533234, "Natalia", "Garcia", "Sancho","pediatria"));
	addMedico(Medico(23112321, "Pedro", "Sancho", "Ramirez", "ginecologia"));
	addMedico(Medico(12323986, "Angelines", "Luna", "Fron", "psiquiatria"));
	addMedico(Medico(23423424, "Marta", "Garcia", "Sancho", "medicina familia"));
	addMedico(Medico(23231321, "Lorena", "Garcia", "Ramirez", "pediatria"));
	addMedico(Medico(88684286, "Lupita", "Fita", "Cinturita", "pediatria"));
	addMedico(Medico(13131321, "Pepo", "Pipo", "Pepo", "pediatria"));
	addMedico(Medico(56543267, "Pipo", "Pipito", "Pepone", "pediatria"));
}

Hospital::Hospital() {
	this->citas = new vector<Cita>();
	this->pacientes = new vector<Paciente>();
	this->medicos = new vector<Medico>();
	this->pacientesPaginados = Paginador<Paciente>(pacientes, TipoLista::PACIENTE);
	this->medicosPaginados = Paginador<Medico>(medicos, TipoLista::MEDICO);
}

Hospital::Hospital(const Hospital& original) {
	this->citas = new vector<Cita>(*original.citas);
	this->pacientes = new vector<Paciente>(*original.pacientes);
	this->medicos = new vector<Medico>(*original.medicos);
	this->pacientesPaginados = Paginador<Paciente>(pacientes, TipoLista::PACIENTE);
	this->medicosPaginados = Paginador<Medico>(medicos, TipoLista::MEDICO);
}

Hospital::~Hospital() {
	delete citas;
	delete pacientes;
	delete medicos;
}

void Hospital::addPaciente() {
	system("cls");
	cout <<"--AGREGANDO DATOS DE NUEVO PACIENTE AL SISTEMA--" << endl;
	Paciente nuevo;
	cin >> nuevo;
	addPaciente(nuevo);
}

void Hospital::addPaciente(const Paciente &p){
	pacientes->push_back(p);
}

void Hospital::addMedico() {
	system("cls");
	cout << "--AGREGANDO DATOS DE NUEVO MEDICO AL SISTEMA--" << endl;
	Medico nuevo;
	cin >> nuevo;
	addMedico(nuevo);
}

void Hospital::menuBusquedaPersonas() {
	bool activo = true;
	bool update = true;
	do {
		if (update) {
			system("cls");
			cout << "*** MENU DE BUSQUEDA DE PERSONAS ***" << endl;
			cout << "[Y] - Buscar medico por nombre" << endl;
			cout << "[U] - Buscar medico por especialidad" << endl;
			cout << "[I] - Buscar paciente por nombre" << endl;
			cout << "[O] - Buscar paciente por DNI" << endl;
			cout << "[S] - Retornar" << endl;
		}
		update = true;
		char input = toupper(_getch());

		if (input == 'Y' || input == 'U') {
			string busqueda = "";
			vector<Medico> resultadoBusqueda;
			Paginador<Medico> resultadoPaginado;
			cout << ((input == 'Y') ? ("Introduzca el nombre: ") : "Introduzca especialidad: ");
			cin >> busqueda;
			if (input == 'Y') {
				for (int i = 0; i < medicos->size(); i++) {
					if (contains(medicos->at(i).getNombreCompleto(), busqueda)) {
						resultadoBusqueda.push_back(medicos->at(i));
					}
				}
			} else {
				for (int i = 0; i < medicos->size(); i++) {
					if (contains(medicos->at(i).getEspecialidad(), busqueda)) {
						resultadoBusqueda.push_back(medicos->at(i));
					}
				}
			}
			resultadoPaginado = Paginador<Medico>(&resultadoBusqueda, TipoLista::MEDICO);
			resultadoPaginado.interactuar();
		}

		if (input == 'I' || input == 'O') {
			string busqueda = "";
			int busquedaInt = 0;
			vector<Paciente> resultadoBusqueda;
			Paginador<Paciente> resultadoPaginado;
			if (input == 'I') {
				cout << "Introduzca el nombre: ";
				cin >> busqueda;
				for (int i = 0; i < pacientes->size(); i++) {
					if (contains(pacientes->at(i).getNombreCompleto(), busqueda)) {
						resultadoBusqueda.push_back(pacientes->at(i));
					}
				}
			} else {
				cout << "Introduzca el dni: ";
				cin >> busquedaInt;
				for (int i = 0; i < pacientes->size(); i++) {
					if (pacientes->at(i).getDni() == busquedaInt) {
						resultadoBusqueda.push_back(pacientes->at(i));
						break;
					}
				}
			}
			resultadoPaginado = Paginador<Paciente>(&resultadoBusqueda, TipoLista::PACIENTE);
			resultadoPaginado.interactuar();
		}

		if (input == 'S') {
			activo = false;
		}
	} while (activo);
}

void Hospital::menuListados() {
	bool activo = true;
	bool update = true;
	do {
		if (update) {
			system("cls");
			cout << "*** MENU DE ACCESO A LISTADOS COMPLETOS ***" << endl;
			cout << "[P] - Listar pacientes" << endl;
			cout << "[M] - Listar medicos" << endl;
			cout << "[S] - Retornar" << endl;
		}
		update = true;
		switch (toupper(_getch())) {
		case 'P':
			pacientesPaginados.interactuar();
			break;
		case 'M':
			medicosPaginados.interactuar();
			break;
		case 'S':
			activo = false;
			break;
		default:
			update = false;
		}
	} while (activo);
}

void Hospital::getionarMedicos() {
	bool activo = true;
	bool update = true;
	do {
		if (update) {
			system("cls");
			cout << "*** MENU DE GESTION DE MEDICOS ***" << endl;
			cout << "[L] - Listar medicos" << endl;
			cout << "[N] - Buscar medico por nombre" << endl;
			cout << "[E] - Buscar medico por especialidad" << endl;
			cout << "[S] - Retornar" << endl;
		}
		update = true;
		switch (toupper(_getch())) {
		case 'L':
			medicosPaginados.interactuar();
			break;
		case 'N':
			break;
		case 'E':
			break;
		default:
			update = false;
		}
	} while (activo);
}

void Hospital::addMedico(const Medico &m){
	medicos->push_back(m);
}
void Hospital::addCita(const Cita &c) {
	citas->push_back(c);
}

Hospital& Hospital::operator=(const Hospital& opDcha) {
	if (citas->size() != opDcha.citas->size()) {
		delete citas;
		citas = new vector<Cita>(*opDcha.citas);
	} else {
		citas = opDcha.citas;
	}
	if (pacientes->size() != opDcha.pacientes->size()) {
		delete pacientes;
		pacientes = new vector<Paciente>(*opDcha.pacientes);
	} else {
		pacientes = opDcha.pacientes;
	}
	if (medicos->size() != opDcha.medicos->size()) {
		delete medicos;
		medicos = new vector<Medico>(*opDcha.medicos);
	} else {
		medicos = opDcha.medicos;
	}
	this->pacientesPaginados = Paginador<Paciente>(pacientes, TipoLista::PACIENTE);
	this->medicosPaginados = Paginador<Medico>(medicos, TipoLista::MEDICO);
	return *this;
}

bool Hospital::contains(const string& str, const string& subString) {
	return str.find(subString) != string::npos;
}