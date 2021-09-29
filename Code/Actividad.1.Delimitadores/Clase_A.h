#pragma once
#include <iostream>
#include <sstream> 
#include <fstream>
using namespace std;
class Clase_A
{
public:
	string Nombre;
	int ID;
	int Calificaciones[4];

public:
	void Menu();
	string Insertar();//Funcion secundaria
	void Insertar_al_Final();//listo
	void Insertar_al_Inicio();//listo
	void llenar_Archivo_Principal();//Funcion secundaria
	bool Buscar_Registros(string ID);//listo
	void Modificar_registros();//listo
	void Eliminar_Registros();//listo
	void Mostrar_Registros();//listto
	bool Unicidad_de_ID(string ID);//listo
};

