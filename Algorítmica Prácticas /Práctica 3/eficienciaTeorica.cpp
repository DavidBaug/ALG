Solucion Algoritmo::Recubrimiento()
{
	list<candidato> candidatos;
	candidato n;
	Solucion sol;
	vector<pair<int,int> >aristas_usadas;
	int n_aristas = 0;

	//INICIALIZAMOS CANDIDATOS
	for (int i = 0; i < p.getTamanio(); ++i){ //O(n)
		n.nodo = i;// O(1)
		for (int k = 0; k < p.getTamanio(); ++k){//O(n)
			if ( p.getElemento(i,k) == 1)//O(1)
				n.aristas.push_back(pair<int,int>(i,k));//O(1)
		}
		candidatos.push_back(n);//O(1)
		n.aristas.clear();//O(1)
	}

	candidatos.sort();//O(nlogn)
	candidatos.reverse(); //O(n)

	//OPERACIÓN
	while(aristas_usadas.size() < num_aristas){//O(n)
		n =  candidatos.front(); //O(1)
		
		for (int i = 0; i < n.aristas.size(); ++i){ //O(n)
			if (!EstaArista(aristas_usadas, n.aristas[i])) //O(n) (EstaArista eficiencia)
				aristas_usadas.push_back(n.aristas[i]);//O(1)
			else n_aristas++;//O(1)
		}

		if (!(n_aristas == n.aristas.size()))//O(1)
			sol.aniadirNodo(n.nodo);//O(1)(anadirNodo eficiencia)

		candidatos.pop_front();//O(1)

		n_aristas = 0;
	}



	return sol;
}