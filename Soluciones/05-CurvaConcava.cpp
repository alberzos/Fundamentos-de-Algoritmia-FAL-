//ALVARO BERZOSA TORDESILLAS
//E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//O(log n)
// función que resuelve el problema
int resolver(const std::vector<int> &v, int ini, int fin) {
    
	if(ini == fin)
		return v[ini];
	if(ini + 1 == fin){
		if(v[ini] < v[fin])
			return v[ini];
		else
			return v[fin];
	}
	int mitad = (ini + fin) / 2;
	if(v[mitad-1] > v[mitad] && v[mitad] < v[mitad+1])
		return v[mitad];
	else if(v[mitad-1] > v[mitad] && v[mitad] > v[mitad+1])
		return resolver(v, mitad+1, fin);
	else
		return resolver(v, ini, mitad);
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector<int> v(n);
    if (! std::cin)
        return false;
	for(int i = 0; i < n; i++)
		std::cin >> v[i];
	
    std::cout << resolver(v, 0, v.size() - 1) << std::endl;
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

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
