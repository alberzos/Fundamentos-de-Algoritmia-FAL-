// ALVARO BERZOSA TORDESILLAS
// E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//Coste: O(log n)
bool resolver(const std::vector<int> &v, int ini, int fin, int k) {
	
	if(ini+1 == fin) //Caso base
		return true;
	int mitad = (ini + fin) / 2;
	
	bool ok1 = resolver(v, ini, mitad, k);
	bool ok2 = resolver(v, mitad, fin, k);
	
	return ok1 && ok2 && abs(v[ini] - v[fin - 1]) >= k;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tiradas;
	std::cin >> tiradas;
	if (! std::cin)
		return false;
	
	int dispersion;
	std::cin >> dispersion;
	
	std::vector<int> v(tiradas);
	for(int i=0; i<v.size(); i++)
		std::cin >> v[i];
	
	bool sol = resolver(v, 0, v.size(), dispersion);
	if(sol)
		std::cout << "SI \n";
	else
		std::cout << "NO \n";
	// escribir sol
	
	
	return true;
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

 #ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	
	while (resuelveCaso())
		;
	
	//system("PAUSE");
	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
