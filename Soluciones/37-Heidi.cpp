// Nombre del alumno ALVARO BERZOSA TORDESILLAS
// Usuario del Juez E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct solucion {
	int maxLong;
	int numLlanos;
	std::vector<int> posLlanos;
};

// función que resuelve el problema
solucion resolver(const std::vector<int> &v, int longi) {
    
	solucion sol;
	sol.maxLong = 0;
	sol.numLlanos = 0;
	
	int max = v[v.size()-1];
	int cont = 1;
	int pos = 0;
	for (int i = v.size() - 1; i >= 1; i--) {
		if (v[i] >= max) {
			max = v[i];
			if (v[i] == v[i - 1]) {
				if (cont == 1)
					pos = i;
				cont++;
				if (cont == longi) {
					sol.numLlanos++;
					sol.posLlanos.push_back(pos);
					if (sol.maxLong <= cont)
						sol.maxLong = cont;
				}
				else if (cont > longi) {
					if (sol.maxLong <= cont)
						sol.maxLong = cont;
				}
			}
			else
				cont = 1;
		}
	}

	return sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam;
	int longi;

	std::cin >> tam;
    if (! std::cin)
        return false;

	std::cin >> longi;
	std::vector<int> v(tam);

	for (int i = 0; i < tam; i++) {
		std::cin >> v[i];
	}
    
    solucion sol = resolver(v, longi);
    
	std::cout << sol.maxLong << " " << sol.numLlanos << " ";
	for (int i = 0; i < sol.posLlanos.size(); i++) {
		std::cout << sol.posLlanos[i] << " ";
	}
	std::cout << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
	
	while (resuelveCaso());

	return 0;
}
