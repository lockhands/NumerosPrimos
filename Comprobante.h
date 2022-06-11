#ifndef COMPROBANTE_H
#define COMPROBANTE_H

class Comprobante
{
	private:
		int numero;
		int numero_auxiliar;
		int bandera;
	public:
		Comprobante(int numero);
		int Comprobacion(int size);
		int EsPrimo();
		int setNumero();
		int setBandera();
		~Comprobante();
	protected:
};

#endif
