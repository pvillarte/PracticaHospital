#pragma once
#include <vector>
#include <conio.h>
#define TAM_PAG 10

using namespace std;
enum class TipoLista {
	DEFAULT = 0,
	PACIENTE = 1,
	MEDICO = 2,
};

template<class T> class Paginador {
private:
	int tamPagina;
	int paginaActual;
	int totalPaginas;
	vector<T>* items;
	TipoLista tipo;
	void imprimirEncabezado();
	void imprimirCuerpo();
	void imprimirPie();
	void imprimir();
	void refrescar();
public:
	//No se agrega destructor a pesar de tener puntero ya que en este caso el comportamiento que se 
	//busca es que el propietario del vector sea el hospital, y el paginador debe apuntar a ese mismo 
	//sitio. El espacio en memoria por tanto se liberará en el destructor de la clase hospital
	Paginador(vector<T>* items = nullptr, TipoLista tipo = TipoLista::DEFAULT);
	void interactuar();
};

template<class T> void Paginador<T>::imprimirEncabezado() {
	vector<string> encabezados;
	switch (tipo) {
		case TipoLista::PACIENTE:
			encabezados = {"DNI", "NOMBRE", "APELLIDO 1", "APELLIDO 2"};
			break;
		case TipoLista::MEDICO:
			encabezados = { "DNI", "NOMBRE", "APELLIDO 1", "APELLIDO 2", "ESPECIALIDAD" };
			break;
	}
	for (int i = 0; i < encabezados.size(); i++) {
		cout << left << setw(20) << setfill(' ') << encabezados[i];
	}
	cout << endl;
}

template<class T> void Paginador<T>::imprimirCuerpo() {
	if (!items->empty()) {
		int primeroImprimir = tamPagina * paginaActual;
		int ultimoImprimir = ((paginaActual != totalPaginas - 1) || (items->size() % tamPagina == 0))?
			(primeroImprimir + tamPagina - 1) : (primeroImprimir + (items->size() % tamPagina) - 1);
		for (int i = primeroImprimir; i <= ultimoImprimir; i++) {
			T objeto(items->at(i));
			cout << objeto << endl;
		}
	}
}

template<class T> void Paginador<T>::imprimirPie() {
	cout << endl << "<---[A] Pag. Anterior---   [Pagina " << paginaActual + 1 << " de "
		<< totalPaginas << "]   ---Pag. Siguiente [D]--->" << endl;
	cout << "[S] - Retornar" << endl;
}

template<class T> Paginador<T>::Paginador(vector<T>* items, TipoLista tipo) {
	paginaActual = 0;
	tamPagina = TAM_PAG;
	totalPaginas = (items == nullptr || items->empty()) ? 1 : (1 + ((items->size() - 1) / tamPagina));
	this->items = items;
	this->tipo = tipo;
}

template<class T> void Paginador<T>::refrescar() {
	paginaActual = 0;
	totalPaginas = (items->empty()) ? 1 : (1 + ((items->size() - 1) / tamPagina));
}

template<class T> void Paginador<T>::imprimir(){
	system("cls");
	imprimirEncabezado();
	imprimirCuerpo();
	imprimirPie();
}

template<class T> void Paginador<T>::interactuar(){
	refrescar();
	bool activo = true;
	bool update = true;
	do {
		if (update) { imprimir(); }
		update = false;
		switch (toupper(_getch())) {
		case 'A':
			if (paginaActual > 0) {
				paginaActual--;
				update = true;
			}
			break;
		case 'D':
			if (paginaActual < totalPaginas - 1) {
				paginaActual++;
				update = true;
			}
			break;
		case 'S':
			activo = false;
		}
	} while (activo);
}
