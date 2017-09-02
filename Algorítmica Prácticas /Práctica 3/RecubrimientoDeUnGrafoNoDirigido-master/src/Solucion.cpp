#include "Solucion.hpp"
#include <iostream>
using namespace std;



Solucion::Solucion(){
	
	vector<int> nodos(0,0);
	
}


Solucion::Solucion(const Solucion & s){
	if(nodos.size() > 0)
			nodos.clear();

		nodos = s.nodos;
}



Solucion & Solucion::operator=(const Solucion & s){
	if(this == &s)
		return *this;
	else{

		if(nodos.size() > 0)
			nodos.clear();

		nodos = s.nodos;

		return *this;
	}
}



void Solucion::aniadirNodo(int nodo){
	nodos.push_back(nodo);
}



int Solucion::coste(){
	return nodos.size();
}


int Solucion::getNodo(int num){
	return nodos[num];
}


void Solucion::imprimeSolucion(){

	cout << "Nodos que forman el recubrimiento: ";

	for (int i = 0; i < nodos.size(); ++i)
		cout << nodos[i] << " ";

	cout << endl;

	cout << "Coste de la solución: " << coste() << endl;
	
}