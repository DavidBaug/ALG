#ifndef _ALGORITMO_HPP_
#define _ALGORITMO_HPP_
#include "Problema.hpp"
#include "Solucion.hpp"
#include <utility>
#include <vector>
#include <list>

using namespace std;

struct candidato
{
	int nodo;
	vector<pair<int,int> > aristas;
	~candidato(){aristas.clear();}
};


class Algoritmo
{
private:
	Problema p;

public:
	Algoritmo(){ p = Problema();}
	Algoritmo(const Problema &recubrimiento);
	Algoritmo(const Algoritmo &alg);
	Algoritmo &operator=(const Algoritmo &alg);
	
	/**
	* @brief: Método que resuelve el problema del recubrimiento mínimo
	* de un gráfo, escogiendo para ello los nodos que conforman la solución.
	* @return: Retorna una solución al problema.
	*/
	Solucion Recubrimiento();
};

/**
* @brief: Sobrecarga del operador <
* @return: "true" si c1 es menor estricto que c2 o "else" en otro caso.
*/
bool operator<(const candidato &c1, const  candidato &c2);

/**
* @brief: Método para comprovar si una arista, pertecene
* a un conjunto de aristas.
* @return: "true" si encuentra la arista en el conjunto de aristas o "else" en caso contrario.
*/
bool EstaArista(const vector<pair<int,int> > &aristas,const pair<int,int> &arista);


#endif