#include "Archivo.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


Archivo::Archivo()
{
}

//Constructor para inicializar el array que le da nombre al archivo.txt
Archivo::Archivo(char * nombre){
	
	strcpy(this->nombre,nombre);
}



//Método para la apertura del archivo.txt
void Archivo::Abrir(){
	Arch_Txt.open(nombre,ios::in);
}

//Método para el cierre del archivo.txt
void Archivo::Cerrar(){
	Arch_Txt.close();
}

//Revierte el vector
vector<string> Archivo::Revertir(vector<string> datos){
	vector<string>auxiliar;

	for(int i=datos.size()-1;i>=0;i--){
		auxiliar.push_back(datos[i]);
	}

	
	return auxiliar;

}

//Obtengo el vector con cada uno de los sets de datos
vector<vector<string> > Archivo::Obtener_Datos(){

string linea="";
vector<string> fila;	
vector<vector<string> >Matriz;
	if(!Arch_Txt){
		cout<<"Error al abrir el archivo"<<endl;
		system("PAUSE");
	}

	while(getline(Arch_Txt,linea)){
	
		
		if(atoi(linea.c_str())==0)	break;
		if(Devolucion(linea)==-1) 	break;
		if(atoi(linea.c_str())>0 && atoi(linea.c_str())<9999999 ){
				fila.push_back(linea);
		Matriz.push_back(fila);
		}
	
	
	}

	

return Matriz;
	
	
}

int Archivo::Devolucion(string linea){
	
int observacion=0;
	for(int i=0;i<linea.length();i++){
		if((int) linea[i] <48){
		return -1;
		} 
		if((int) linea[i] >57) return -1;
	}
	
	
	return observacion;
}



void Archivo::Crear(){
		remove("estrellas.out");
		Arch_Txt.open(nombre,ios::app);
}


void Archivo::Almacenar(int ancho,int largo, vector<vector<string> > estrellas){
	//Marco del radar
	Arch_Txt<<"  ";
	for(int i=1;i<=ancho;i++){
		Arch_Txt<<i;
		Arch_Txt<<" ";
	}
	Arch_Txt<<endl;
	//Regiones de estrellas
	for(int i=0;i<largo;i++){
		Arch_Txt<<i+1;
		Arch_Txt<<" ";
		for(int j=0;j<ancho;j++){
			if(estrellas[i][j]!="*") {
			Arch_Txt<<" ";
			Arch_Txt<<" "; }
			else {
				Arch_Txt<<estrellas[i][j];
				Arch_Txt<<" ";
			}
		}
		Arch_Txt<<i+1;
		Arch_Txt<<endl;
	}
	Arch_Txt<<"  ";
	//Marco del radar
		for(int i=1;i<=ancho;i++){
		Arch_Txt<<i;
		Arch_Txt<<" ";
	}
}

void Archivo::Lectura(){
	string a="";
	if(!Arch_Txt){
		cout<<"Error al abrir el archivo"<<endl;
		system("PAUSE");
	}
	
	while(getline(Arch_Txt,a)){
		cout<<a;
		cout<<endl;
	}
	
}

Archivo::~Archivo()
{
}


