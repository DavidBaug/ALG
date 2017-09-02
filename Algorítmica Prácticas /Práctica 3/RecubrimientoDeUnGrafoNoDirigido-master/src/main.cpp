#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Algoritmo.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
  Problema pr;
  Algoritmo alg;
  Solucion sol;
  ifstream is;

  if (argc != 2){
    cerr << "Uso:" << argv[0] << " <Fichero_Datos>" << endl;
    return 1;
  }


  is.open(argv[1], ifstream::in);
  is >> pr;//leemos los datos de un fichero, pasado como segundo argumento del programa.
  is.close();


  cout << "Nodos del problema: " << pr.getTamanio() << endl << pr;

  alg = Algoritmo(pr);
  sol = alg.Recubrimiento();//aplicamos la solución

  sol.imprimeSolucion();

  return 0;
}
