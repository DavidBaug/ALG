#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <bits/stdc++.h>

using namespace std;

unsigned int fuerzaBruta(unsigned int *v,unsigned int size){
    unsigned int inversiones = 0;

    for( unsigned int i = 0; i < size; i++){
        for( unsigned int j = i+1; j < size; j++){
            if( v[i] > v[j]){
                inversiones++;
            }
        }
    }
    return inversiones;
}

//*******************************************************************************************


unsigned int  _mergeSort(unsigned int arr[], unsigned int temp[], unsigned int left, unsigned int right);

unsigned int merge(unsigned int arr[], unsigned int temp[], unsigned int left, unsigned int mid, unsigned int right);




unsigned int mergeSort(unsigned int arr[], unsigned int array_size){
    unsigned int *temp = new unsigned int[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}




unsigned int _mergeSort(unsigned int arr[], unsigned int temp[], unsigned int left, unsigned int right)
{
  unsigned int mid, inv_count = 0;
  if (right > left)
  {
    // Divide el array y llama recursivamente al metodo merge
    mid = (right + left)/2;

    /* Se cuentan las inversiones para las dos mitades del array*/
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Mezcla las dos partes*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

/* Mezcla dos arrays ordenados y cuenta las inversiones*/
unsigned int merge(unsigned int arr[], unsigned int temp[], unsigned int left, unsigned int mid, unsigned int right)
{
  unsigned int i, j, k;
  unsigned int inv_count = 0;

  i = left; /* i indice array izquierdo*/
  j = mid;  /* j indice array derecho*/
  k = left; /* k indice array mezclado*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

      inv_count = inv_count + (mid - i);
    }
  }

  //Copia los elementos del array izquierdo al temporal
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  //Copia los elementos del array derecho al temporal
  while (j <= right)
    temp[k++] = arr[j++];

  //Copia los elementos mezclados al array original
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

bool Esta(unsigned int *v, unsigned int tam, unsigned int ele)
{
  bool encontrado = false;


  for (unsigned int i = 0; i < tam && !encontrado; ++i)
    if (v[i] == ele)
      encontrado = true;


  return encontrado;
}

//**********************************************************************************************

int main(int argc, char *argv[]){
    if(argc != 2){
        cerr << "Formato: ./"<< argv[0] << " tamVector " << endl;
        exit(-1);
    }

    unsigned int inversiones = 0;
    unsigned int tam = atoi(argv[1]);
    unsigned int n_random, i = 0;
	  unsigned int *v = new unsigned int[tam];

    for (unsigned int i = 0; i < tam; i++)
      v[i] = -1;

    srand(time(NULL));//iniciamos una semilla aleatoria.

    while (i < tam){
      n_random = rand()%tam;
      if (Esta(v, tam, n_random))
        n_random = rand()%tam;
      else{
        v[i] = n_random;
        //cout << "v["<< i <<"] = " << v[i] << endl;
        ++i;
      }
    }

    // Variables tiempo fuerza bruta
    clock_t antes, despues;
  	antes = clock();

    //Ejecucion algoritmo fuerza bruta
    inversiones = fuerzaBruta(v,tam);

	despues = clock();


    // Variables tiempo merge
    clock_t antes1, despues1;
    antes1 = clock();

    //Ejecucion algoritmo merge
    unsigned int inversiones2 = mergeSort(v,tam);

    despues1 = clock();




    //cout << tam << ' ';

    //Resultados
    cout << "Inversiones fuerza bruta: "<< inversiones << endl;
    cout << "Inversiones DyV: " << inversiones2 << endl;
    cout << "Tiempo ejecucion fuerza bruta: "<< (double) (despues-antes)/CLOCKS_PER_SEC << endl;
    cout << "Tiempo ejecucion Dyv: "<< (double) (despues1-antes1)/CLOCKS_PER_SEC << endl;


    return 0;
}
