#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Archivo
{
	private:
		fstream Arch_Txt; //Archivo 
		char nombre[25];	//Nombre del archivo
	public:
		Archivo();
		Archivo(char * nombre); //Constructor que recibe el nombre del archivo
		void Abrir(); //Método para abrir el archivo
		void Cerrar(); 	//Método para cerrar el archivo
		vector<vector<string> > Obtener_Datos(); //Obtengo el vector con cada uno de los sets de datos 
		vector<string> Revertir(vector<string> datos);
		void Crear(); //Creo el archivo 
		void Almacenar(int ancho,int largo,vector<vector<string> > estrellas); //Almaceno el mapa de las regiones de estrellas
		void Lectura(); //Leo el mapa de las regiones de estrellas
		int Devolucion(string linea);
		~Archivo();
	protected:
};

#endif
