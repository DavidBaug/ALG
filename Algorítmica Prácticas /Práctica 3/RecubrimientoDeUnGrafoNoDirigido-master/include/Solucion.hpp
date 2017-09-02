#ifndef _SOLUCION_HPP_
#define _SOLUCION_HPP_


#include "Problema.hpp"
#include <vector>


class Solucion {

	private:

		/**
			La solución la almacenamos en un vector de nodos que son los nodos
			que forman el recubrimiento
		**/

		vector<int> nodos;
		


	public:

		/**
			@brief Constructor por defecto

		**/

		Solucion();


		/**
			@brief Constructor de copia
		**/

		Solucion(const Solucion & s);


		/**
			@brief Sobrecarga del operador de asignación.
		**/

		Solucion & operator=(const Solucion & s);


		/**
			@brief Coste de la solución
			@return Devuelve el coste de la solución
		**/

		int coste();

		/**
			@brief Consulta un nodo dada una posición
		**/

		int getNodo(int num);


		/**
			@brief Imprime el contenido del vector y el coste
		**/

		void imprimeSolucion();



		/**
			@brief Añade un nuevo nodo al vector
		**/

		void aniadirNodo(int nodo);


};

#endif