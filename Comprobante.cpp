#include "Comprobante.h"
#include "Comprobante.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "cstdlib"
#include <string> 
using namespace std;


Comprobante::Comprobante(int numero)
{
	bandera=-1;
	this->numero=numero;
	this->numero_auxiliar=numero;
}

int Comprobante::setBandera(){
	return bandera;
}

int Comprobante::Comprobacion(int size){
	

	int band=EsPrimo();

	
	
	if(band!=-1) {
	 	bandera=band;
	 	return bandera;
	}
	
	if(size>=2){
		stringstream ss; 
		string digitos;
		ss<<numero_auxiliar;
		ss>>digitos;
		
		int acum=0;
		for(int i=0;i<digitos.length();i++){
			char a;
			a=digitos[i];
			int b=a - '0';
			acum=acum+b;
		}
		
		numero_auxiliar=acum;
		stringstream aa; 
		string digitos1;
		aa<<numero_auxiliar;
		aa>>digitos1;


		Comprobacion(digitos1.length());
	}
	if(bandera==-1) return -1;

}

int Comprobante::EsPrimo(){
	if(numero_auxiliar < 2) return numero_auxiliar; //Si es primo
	
	int square= sqrt(numero_auxiliar);

	for(int i=2;i<=square;i++){
		if((numero_auxiliar % i) == 0){
			return -1; //No es primo
		}
	
	}

	return numero_auxiliar; //si es primo

}

int Comprobante::setNumero(){
	return numero;
}
Comprobante::~Comprobante()
{
}
