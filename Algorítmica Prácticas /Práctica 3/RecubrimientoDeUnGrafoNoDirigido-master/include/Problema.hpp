#ifndef _PROBLEMA_HPP_
#define _PROBLEMA_HPP_

#include <ostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Problema
{
private:
  vector<vector<int> > m;//matriz Triangular
  int n;//tamaño filas/columnas matriz Triangular

public:
  /*CONSTRUCTORES*/
  Problema();
  Problema(const Problema &pr);
  Problema &operator=(const Problema &pr);
  ~Problema();
  
  /*ACCESO A VARIABLES MIEMBRO*/
  /**
  * @brief: Obtiene un elemento de la matriz triangular, se le pueden pasar
  * pasar posiciones como si la matriz fuese completa, el método se encarga
  * de hacer la conversión de filas y columnas
  * @pre: fil  y col deben ser números positivos comprendidos entre 0 y n-1
  */
  int getElemento(int fil, int col) const;

  /**
  * @brief: Obtiene el número de filas que tiene la matriz triangular
  *
  */
  int getTamanio() const;

  /*OTRAS OPERACIONES*/
  /**
  * @brief: Carga desde un fichero la representación del grafo
  * que es resuelto en el problema.
  * @pos: si el nombre del fichero, no es valido y falla en la apertura
  * aborta el programa.
  */
  void CargarDesdeFichero(const char* file_name);


  friend ifstream &operator>>(ifstream &in, Problema &pr);
  friend ostream &operator<<(ostream &out, const Problema &pr);
};

ifstream &operator>>(ifstream &in, Problema &pr);
ostream &operator<<(ostream &out, const Problema &pr);


#endif