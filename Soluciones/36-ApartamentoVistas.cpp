//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Alvaro Berzosa Tordesillas
// Gasan Nazer
// Usuario del juez de clase
// Alvaro- E09
// Gasan- E53
// Usuario del juez de examen que has utilizado en la prueba de hoy
// E38
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


//*******************************
// Aqui especificación de la función que resuelve el problema. 
// P: { edificios > 0 && pt k 0 <= k < v.size(): v[k].altura > 0 && ptk 0 <= k < v.size(): v[k].piso > 0}
// vector<tDatos> sol = # k:v.size() - 2 >= k >= 0: tieneVista(v, k)
// Q: {sol.size() > 0}
//
// tieneVista(v,i) === v[i].piso > v[i + 1].altura
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// coste de la solución: O(n) donde n es el numero de edificios. Recorremos los edificios solo una vez 
// El coste de las operaciones de dentro del bucle es constante y por tanto no influye en el coste final de la solución.
// 
//*******************************

struct tDatos {
	std::string id;
	int altura;
	int piso;
};


// Aqui la función implementada por el alumno
vector<tDatos> resolver(std::vector<tDatos> const& v) {
	vector<tDatos> sol;
	int altMax = v[v.size()-1].altura;
	if (v[v.size() - 1].piso >= 0) {
		sol.push_back(v[v.size() - 1]);
	}

	for (int i = v.size() - 2; i >= 0 ; i--)
	{
		if(altMax < v[i + 1].altura)
			altMax = v[i + 1].altura;
		if (v[i].piso > altMax) {
			if(v[i].piso > 0)
				sol.push_back(v[i]);
		}
	}

	return sol;
}



bool resuelveCaso() {
	int numEdificios;
	std::cin >> numEdificios;
	if (numEdificios == 0) return false;
	std::vector<tDatos> edificios(numEdificios);
	for (int i = 0; i < numEdificios; ++i) {
		std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
	}


	// LLamada a la funcion que resuelve el problema
	vector < tDatos> sol = resolver(edificios);

	// Escribir el resultado
	if (sol.size() == 0)
		cout << "Ninguno" << endl;
	else {
		cout << sol.size() << endl;
		for (int i = 0; i < sol.size(); i++)
		{
			cout << sol[i].id << " ";
		}
		cout << endl;
	}

	return true;
}


int main() {
	
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
