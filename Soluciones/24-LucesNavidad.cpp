// Alvaro Berzosa Tordesillas
// E09

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <cstdlib>

bool esValida(int etapa, const std::vector<int> & sol, const std::vector<int> &marcas, int i) {
	
	// No haya mas de dos luces seguidas del mismo color
	if (etapa > 2 && sol[etapa] == sol[etapa - 1] && sol[etapa - 2] == sol[etapa])
		return false;
	if(etapa + 1 - marcas[i] < (etapa + 1) / 2)
		return false;
	return true;
	
}

void resolver(const std::vector<int> &consumo, std::vector<int> &marcas, int etapa, int &numSoluciones,
			  int consumoActual, int consumoMax, std::vector<int> & sol) {
	
	for (int i = 0; i < consumo.size(); i++) {
		sol[etapa] = i;
		consumoActual = consumoActual + consumo[i];
		//Marcar
		marcas[i]++;
		if(esValida(etapa, sol, marcas, i) && consumoActual <= consumoMax) {
			if (etapa == sol.size() - 1)
				numSoluciones++;
			else
				resolver(consumo, marcas, etapa + 1, numSoluciones, consumoActual, consumoMax, sol);
		}
		consumoActual = consumoActual - consumo[i];
		// Desmarcar
		marcas[i]--;
	}

}


bool resuelveCaso() {
	
	int longitud, numColores, consumoMax;
	int consumoActual = 0, numSoluciones = 0;
	std::cin >> longitud >> numColores >> consumoMax;

	if (longitud == 0 || !std::cin) return false;
	
	std::vector<int> consumo(numColores);
	std::vector<int> marcas(numColores);
	std::vector<int> sol(longitud);
	
	for (int i = 0; i < consumo.size(); i++)
		std::cin >> consumo[i];
	

	resolver(consumo, marcas, 0, numSoluciones, consumoActual, consumoMax, sol);

	std::cout << numSoluciones << std::endl;

	return true;
	
}

int main() {
	
	/*
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
*/

	while (resuelveCaso())
		;

	/*
	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
	 */

	return 0;
}
