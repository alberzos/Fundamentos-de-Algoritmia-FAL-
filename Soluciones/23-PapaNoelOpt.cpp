// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Las etapas son los niños y las ramas los juguetes


// función que resuelve el problema
int resolver(std::vector<int> &sol, int etapa, std::vector<bool> &marcas,
			  const std::vector<std::vector<int>> &matriz, int sumSatis) {
    
	int mejorSol = -1000;
	for(int i = 0; i < marcas.size(); i++){
		sol[etapa] = i;
		if(!marcas[i]){
			// Marcar
			marcas[i] = true;
			sumSatis = sumSatis + matriz[etapa][i];
			if(etapa == sol.size() - 1){
				if(mejorSol < sumSatis)
					mejorSol = sumSatis;
			}
			else
				mejorSol = std::max(resolver(sol, etapa + 1, marcas, matriz,sumSatis), mejorSol);
			// Desmarcar
			marcas[i] = false;
			sumSatis = sumSatis - matriz[etapa][i];
		}
	}
	return mejorSol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nJuguetes, nNinios;
	std::cin >> nJuguetes >> nNinios;
	
	std::vector<std::vector<int>> matriz(nNinios, std::vector<int>(nJuguetes));
	std::vector<bool> marcas(nJuguetes, false);
	std::vector<int> sol(nNinios);
	int sumSatis = 0;
    if (! std::cin)
        return false;
	
	for(int i = 0; i < nNinios; i++){
		for(int j = 0; j < nJuguetes; j++){
			std::cin >> matriz[i][j];
		}
	}
	
	std:: cout << resolver(sol, 0, marcas, matriz, sumSatis) << "\n";
	
    // escribir sol
    
    
    return true;
    
}

int main() {
	
	/*
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    */
    
    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	 
    return 0;
}
