//ALVARO BERZOSA TORDESILLAS
//E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//O(n)
// función que resuelve el problema
int resolver(const std::vector<int> &v, const std::vector<int> &w, int ini, int fin) {
    
	if(ini == fin)
		return v[ini];
	if(ini + 1 == fin){
		if(v[ini] != w[ini])
			return v[ini];
		if(v[fin - 1] == w[fin - 1])
			return v[fin];
	}
	else{
		int mitad = (ini + fin) / 2;
		if(v[mitad] < w[mitad])
			return resolver(v, w, ini, mitad);
		else
			return resolver(v, w, mitad, fin);
	}
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int nElem;
	std::cin >> nElem;
	std::vector<int> v;
	std::vector<int> w;
	for(int j = 0; j < nElem; j++){
		int elem;
		std::cin >> elem;
		v.push_back(elem);
	}
	for(int p = 0; p < nElem-1; p++){
		int elem;
		std::cin >> elem;
		w.push_back(elem);
	}
	std::cout << resolver(v, w, 0, v.size()-1) << std:: endl;

    
    // escribir sol
    
    
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
		#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
	
	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	
    return 0;
}
