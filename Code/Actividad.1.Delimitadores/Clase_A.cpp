#include "Clase_A.h"

void Clase_A::Menu()
{
	bool continuar = true;
	char Opcion;
	do{
	cout << "Menu Super basico jeje" << endl;
	cout << "1.-Agregar" << endl;
	cout << "2.-Eliminar" << endl;
	cout << "3.-Modificar" << endl;
	cout << "4.-Mostrar Registros" << endl;
	cout << "5.-Salir" << endl;
	cout << "Ingresa una Opcion: ";
	cin >> Opcion;
	switch (Opcion)
	{
	case '1': {
		system("CLS");
		cout << "Selecciona en que lugar del archivo quieres agregar un registro:" << endl;
		cout << "1.-Inicio" << endl;
		cout << "2.-Final" << endl;
		cout << "Ingresa una opcion: ";
		cin >> Opcion;
		switch (Opcion)
		{
		case '1': {
			system("CLS");
			Insertar_al_Inicio();
			break;
		}
		case '2': {
			system("CLS");
			Insertar_al_Final();
			break;
		}
		default:
			cout << "Opcion no valida, intenta de nuevo." << endl;
			break;
		}
		break;
	}
	case '2': {
		system("CLS");
		Eliminar_Registros();
		break;
	}
	case '3': {
		system("CLS");
		Modificar_registros();
		break;
	}
	case '4': {
		system("CLS");
		Mostrar_Registros();
		break;
	}
	case '5': {
		cout << "Nos vemos..." << endl;
		continuar = false;
		break;
	}
	default:
		cout << "Opcion no valida, intenta de nuevo." << endl;
		break;
	}
	} while (continuar);
}

string Clase_A::Insertar()
{
	string Nombre,ID;
	int C1,C2,C3,C4;
	cout << "Ingresa un nombre" << endl;
	cin >> Nombre;
	do {
		cout << "Ingresa el ID" << endl;
		cin >> ID;
		if (Unicidad_de_ID(ID)) {
			break;
		}
	} while (true);
	
	cout << "Ingresa calificacion 1 (en enteros)" << endl;
	cin >> C1;
	cout << "Ingresa calificacion 2 (en enteros)" << endl;
	cin >> C2;
	cout << "Ingresa calificacion 3 (en enteros)" << endl;
	cin >> C3;
	cout << "Ingresa calificacion 4 (en enteros)" << endl;
	cin >> C4;
	stringstream ss;
	ss << ID << "|" << Nombre << "|" << C1 << "|" << C2 << "|" << C3 << "|" << C4;
	return ss.str();
}

void Clase_A::Insertar_al_Final()
{
	string row;
	ifstream Aoriginal;
	Aoriginal.open("iny.txt");
	Aoriginal >> row;
	ofstream Aauxiliar("Auxiliar.txt");
	while (!Aoriginal.eof()) {
		Aauxiliar << row << endl;
		Aoriginal >> row;
	}
	Aauxiliar.close();
	Aoriginal.close();
	ofstream fout("iny.txt", ios::app);
	fout << Insertar() << endl;
	fout.close();
}

void Clase_A::Insertar_al_Inicio()
{
	string row;
		ifstream Aoriginal;
		Aoriginal.open("iny.txt");
		Aoriginal >> row;
		ofstream Aauxiliar("Auxiliar.txt");
		while (!Aoriginal.eof()) {
			Aauxiliar << row << endl;
			Aoriginal >> row;
		}
		Aauxiliar.close();
		Aoriginal.close();
	ofstream fout("iny.txt");
	fout << Insertar() << endl;
	fout.close();
	ifstream ArchivoAuxiliar;
	ArchivoAuxiliar.open("Auxiliar.txt");
	ArchivoAuxiliar >> row;
	ofstream ArchivoPrincipal("iny.txt", ios::app);
	while (!ArchivoAuxiliar.eof()) {
		ArchivoPrincipal << row << endl;
		ArchivoAuxiliar >> row;
	}
	ArchivoPrincipal.close();
	ArchivoAuxiliar.close();
}

void Clase_A::llenar_Archivo_Principal()
{
	ifstream ArchivoAuxiliar;
	string row;
	ArchivoAuxiliar.open("Auxiliar.txt");
	ArchivoAuxiliar >> row;
	ofstream ArchivoPrincipal("iny.txt");
	while (!ArchivoAuxiliar.eof()) {
		ArchivoPrincipal << row << endl;
		ArchivoAuxiliar >> row;
	}
	ArchivoPrincipal.close();
	ArchivoAuxiliar.close();
}


bool Clase_A::Buscar_Registros(string ID)
{
	ifstream Lectura;
	string Clave, row;
	Lectura.open("iny.txt");
	Lectura >> row;
	while (!Lectura.eof()) {
		int contador = 0;
		Clave = "";
		while (row[contador] != '|') {
			Clave += row[contador];
			contador++;
		}
		if (Clave == ID) {
			this->ID = atoi(Clave.c_str());
			contador++;
			Clave = "";
			while (row[contador] != '|') {
				Clave += row[contador];
				contador++;
			}
			this->Nombre = Clave;
			int contador2;
			for(contador2=0;contador2 < 3;contador2++){
				contador++;
				Clave = "";
				while (row[contador] != '|') {
					Clave += row[contador];
					contador++;
				}
				this->Calificaciones[contador2] = atoi(Clave.c_str());
			}
			int Aux = row.size() - contador;
			contador++;
			Clave = "";
			for (Aux; Aux != 0; Aux--) {
				Clave += row[contador];
				contador++;
			}
			this->Calificaciones[contador2] = atoi(Clave.c_str());
			return true;
		}
		Lectura >> row;
	}
	Lectura.close();
	return false;
}

void Clase_A::Modificar_registros()
{
	string ID_modificar;
	char Opcion;
	bool Continuar=true;
	cout << "Modificar Registro" << endl;
	cout << "Ingresa el ID del registro a modificar:" << endl;
	cin >> ID_modificar;
	if (Buscar_Registros(ID_modificar)) {
		do {
			cout << "Registro:" << endl << "ID#" << this->ID << " Nombre: " << this->Nombre << endl;
			cout << "Calificacion #1: " << this->Calificaciones[0] << "    Calificacion #2: " << this->Calificaciones[1] << endl;
			cout << "Calificacion #3: " << this->Calificaciones[2] << "    Calificacion #4: " << this->Calificaciones[3] << endl << endl;;
			cout << "Que quieres modificar del Registro?" << endl;
			cout << "1.-Nombre" << endl;
			cout << "2.-Calificaciones" << endl;
			cout << "Ingresa una opcion:   ";
			cin >> Opcion;
			switch (Opcion)
			{
			case '1': {
				cout << "Ingresa el nuevo nombre:" << endl;
				cin >> this->Nombre;
				Continuar = false;
				break;
			}
			case '2': {
				for (int i = 0; i < 4; i++) {
					cout << "Ingresa la nueva calificacion#:" << i + 1 << endl;
					cin >> this->Calificaciones[i];
				}
				Continuar = false;
				break;
			}
			default:
				cout << "Opcion no valida, intenta de nuevo." << endl;
				break;
			}
		} while (Continuar);
		stringstream ss;
		ss << this->ID << "|" << this->Nombre << "|" << this->Calificaciones[0] << "|" << this->Calificaciones[1] << "|" << this->Calificaciones[2] << "|" << this->Calificaciones[3];
		string row;
		ifstream Aoriginal;
		Aoriginal.open("iny.txt");
		Aoriginal >> row;
		ofstream Aauxiliar("Auxiliar.txt");
		while (!Aoriginal.eof()) {
			string ID_leido = "";
			int contador = 0;
			while (row[contador] != '|') {
				ID_leido += row[contador];
				contador++;
			}
			if (atoi(ID_leido.c_str()) != this->ID) {
				Aauxiliar << row << endl;
			}
			else {
				Aauxiliar << ss.str() << endl;
			}
			Aoriginal >> row;
		}
		llenar_Archivo_Principal();
		Aauxiliar.close();
		Aoriginal.close();
	}
	else{
		cout << "No se encontro el registro a modificar..." << endl;
	}
}

void Clase_A::Eliminar_Registros()
{
	string ID_eliminar;
	cout << "Elimidar Registro" << endl;
	cout << "Ingresa el ID del registro que quieres eliminar:" << endl;
	cin >> ID_eliminar;
	if (Buscar_Registros(ID_eliminar)) {
		string row;
		ifstream Aoriginal;
		Aoriginal.open("iny.txt");
		Aoriginal >> row;
		ofstream Aauxiliar("Auxiliar.txt");
		while (!Aoriginal.eof()) {
			string ID_leido = "";
			int contador = 0;
			while (row[contador] != '|') {
				ID_leido += row[contador];
				contador++;
			}
			if (atoi(ID_leido.c_str()) != this->ID){
				Aauxiliar << row << endl;
			}
			Aoriginal >> row;
			
		}
		llenar_Archivo_Principal();
		Aauxiliar.close();
		Aoriginal.close();
	}
	else {
		cout << "No se encontro el registro a eliminar..." << endl;
	}
}

void Clase_A::Mostrar_Registros()
{
	ifstream Lectura;
	string Cadena, row;
	int Registro=1;
	Lectura.open("iny.txt");
	Lectura >> row;
	while (!Lectura.eof()) {
		cout << "Registro #" << Registro << endl;
		int contador = 0;
		Cadena = "";
		while (row[contador] != '|') {
			Cadena += row[contador];
			contador++;
		}
		cout << "ID: " << Cadena << endl;
		contador++;
		Cadena = "";
		while (row[contador] != '|') {
			Cadena += row[contador];
			contador++;
		}
		cout << "Nombre: " << Cadena << endl;
		int contador2;
		for (contador2 = 0; contador2 < 3; contador2++) {
			contador++;
			Cadena = "";
			while (row[contador] != '|') {
				Cadena += row[contador];
				contador++;
			}
			cout << "Calificacion #" << contador2+1 << ": " << Cadena << endl;
		}
		int Aux = row.size() - contador;
		contador++;
		Cadena = "";
		for (Aux; Aux != 0; Aux--) {
			Cadena += row[contador];
			contador++;
		}
		cout << "Calificacion #4: " << Cadena << endl << endl;
		Registro++;
		Lectura >> row;
	}
	Lectura.close();
}

bool Clase_A::Unicidad_de_ID(string ID)
{
	string Clave, row;
	ifstream Lectura;
	Lectura.open("Auxiliar.txt");
		Lectura >> row;
		while (!Lectura.eof()) {
			int contador = 0;
			Clave = "";
			while (row[contador] != '|') {
				Clave += row[contador];
				contador++;
			}
			if (Clave == ID) {
				return false;
			}
			Lectura >> row;
		}
	Lectura.close();
	return true;
}
