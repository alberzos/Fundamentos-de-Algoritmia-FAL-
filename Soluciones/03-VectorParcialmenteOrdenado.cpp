// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct solucion{
	bool ok;
	int min = 0;
	int max = 0;
};

//O(log n)
// función que resuelve el problema
solucion resolver(const std::vector<int> &v, int ini, int fin) {
    
	solucion sol, izq, der;
	
	if(ini + 1 == fin){
		sol.ok = true;
		sol.min = v[ini];
		sol.max = v[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		izq = resolver(v, ini, mitad);
		der = resolver(v, mitad, fin);
		
		if(izq.min <= der.min && izq.max <= der.max && izq.ok && der.ok){
			sol.ok = true;
			sol.min = izq.min;
			sol.max = der.max;
		}
		else
			sol.ok = false;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::vector<int> v;
	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	
	while(n != 0){
		v.push_back(n);
		std::cin >> n;
	}
    
    if(resolver(v, 0, v.size()).ok)
		std::cout << "SI \n";
	else
		std::cout << "NO \n";
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   
    
    
    while (resuelveCaso())
        ;

    
    
    return 0;
}
