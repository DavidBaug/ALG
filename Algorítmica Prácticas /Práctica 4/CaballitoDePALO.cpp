#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Coordenada
{
	int fil ,col;
};


struct Nodo
{
	Coordenada cord;
	int mov_siguiente;

	Nodo():mov_siguiente(0){}
};



const int TAMANIO = 8;
const int cordFilCab = 0;
const int cordColCab = 0;
vector<vector<bool> > Tablero(TAMANIO, vector<bool>(TAMANIO,false));
vector <Coordenada> movimientos;

/**
* @brief : Método para generar los posibles movimiento que puede realizar el
* caballo en el tablero
*/
void inicializaOperaciones(){
    Coordenada posicion;
    
    posicion.fil=1;
    posicion.col=-2;
    movimientos.push_back(posicion);
    
    posicion.fil=1;
    posicion.col=2;
    movimientos.push_back(posicion);
    
    posicion.fil=2;
    posicion.col=-1;
    movimientos.push_back(posicion);
    
    posicion.fil=2;
    posicion.col=1;
    movimientos.push_back(posicion);
    
    posicion.fil=-1;
    posicion.col=-2;
    movimientos.push_back(posicion);
    
    posicion.fil=-1;
    posicion.col=2;
    movimientos.push_back(posicion);
    
    posicion.fil=-2;
    posicion.col=-1;
    movimientos.push_back(posicion);
    
    posicion.fil=-2;
    posicion.col=1;
    movimientos.push_back(posicion);
    
}

/**
* @brief : Método que genera el siguiente movimiento del caballo, si es posible.
* @pos : padre.mov_siguiente es actualizado en el método (se incrementa en 1).
* @param  : padre es el nodo sobre el que aplico el siguiente movimiento posible del caballo.
* @param : hijo es el nodo que se genera como resultado de aplicar el movimiento al Nodo padre. 
* @return: Devuelve "true" si se pudo generar un movimiento para el Nodo padre o "false" en caso
* contrario.
*/
bool GenerarMovimiento(Nodo &padre, Nodo &hijo ){
   
    
    bool encontrado = false;


    
    for(int i = padre.mov_siguiente; i < 8 && !encontrado; i++){
        if(((padre.cord.fil + movimientos[i].fil) >= 0) && ((padre.cord.fil + movimientos[i].fil) < TAMANIO)) {
            if(((padre.cord.col + movimientos[i].col) >= 0) && ((padre.cord.col + movimientos[i].col) < TAMANIO)){
                if((Tablero[movimientos[i].fil+padre.cord.fil][movimientos[i].col+padre.cord.col]) == false){
                    encontrado = true;
                    
                 	padre.mov_siguiente = i+1; 
                    
                    hijo.cord.fil = padre.cord.fil + movimientos[i].fil;
                    hijo.cord.col = padre.cord.col + movimientos[i].col;
            	    }
        	}            
    	}
	}

    return encontrado;
}


vector<Coordenada> Algoritmo()
{
	stack<Nodo> vivos;
	vector<Coordenada> solucion;
	Nodo padre;
	Nodo hijo;
	int casillasCubiertas = 1;

	Tablero[cordFilCab][cordColCab] = true;
	padre.cord.fil = cordFilCab;
	padre.cord.col = cordColCab;
	vivos.push(padre);


	while((casillasCubiertas < (TAMANIO*TAMANIO)) && !vivos.empty())
	{
		if (GenerarMovimiento(vivos.top(), hijo)){
			Tablero[hijo.cord.fil][hijo.cord.col] = true;
			casillasCubiertas++; 
			vivos.push(hijo);
		}
		else{
			Tablero[vivos.top().cord.fil][vivos.top().cord.col] = false;
			casillasCubiertas--;
			vivos.pop();
		}
	}

	if (casillasCubiertas == TAMANIO*TAMANIO)
		while(!vivos.empty()){
			solucion.insert(solucion.begin(), vivos.top().cord);
			vivos.pop();
		}

	return solucion;
}




int main(int argc, const char *argv[])
{
	clock_t t_antes, tiempoEmpleado;

	inicializaOperaciones();

	t_antes = clock();
	vector<Coordenada> solucion = Algoritmo();
	tiempoEmpleado = clock() - t_antes;

	if (solucion.empty())
		cout << "No se ha encontrado solucion" << endl;
	else{
		cout << "Solucion para un Tablero de tamaño " << TAMANIO << " Partiendo desde la posicion: (" << cordFilCab << ", " << cordColCab 
		<< ")" << "\n\n";
		for (int i = 0; i < solucion.size(); ++i)
			cout << "(" << solucion[i].fil << ", " << solucion[i].col << ")\t" ;
	}

	cout <<"\n\nTiempo Empleado: " << tiempoEmpleado/(double)CLOCKS_PER_SEC << " segundos" <<endl;


	return 0;
}