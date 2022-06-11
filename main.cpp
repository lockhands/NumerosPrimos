#include <iostream>
#include "Archivo.h"
#include "cstring"
#include "string"
#include <string>
#include "cstdlib"
#include "Comprobante.h"
#include <sstream>

/*Andrés Gabriel Diaz Rodriguez
V-28285435*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	

	Archivo * in= new Archivo("Entrada.in");
	in->Abrir();
	vector<vector<string> >Numeros=in->Obtener_Datos();
	in->Cerrar();
	

	for(int i=0;i<Numeros.size();i++){
		
		//Paso de string a array a int
		Comprobante * numero = new Comprobante(atoi(Numeros[i][i].c_str()));
		
		int ok=numero->Comprobacion(Numeros[i][i].size());
	
	
		
		//Impresión
		int cantidad_espacios=7-(Numeros[i][i].size());
		for(int i=0;i<cantidad_espacios;i++){cout<<" ";}
		cout<<numero->setNumero();
		for(int i=0;i<4;i++){cout<<" ";}
		
		if(ok==-1){cout<<"none";}
		else{
		
		stringstream ss; 
		string digitos;
		ss<<ok;
		ss>>digitos;
		
		cantidad_espacios=4-digitos.size();
		for(int i=0;i<cantidad_espacios;i++){cout<<" ";}
		cout<<digitos;
		}
	cout<<endl;
	
		
		
	}
	return 0;
}
