// ALVARO BERZOSA TORDESILLAS
// E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste O(n) ya que se usa la mitad del vector
// función que resuelve el problema
int resolver(const std::vector<int> &v, int ini, int fin) {
    
	int s;
	if(ini + 1 == fin)
		return v[ini];
	else{
		int mitad = (ini + fin) / 2;
		int izq = resolver(v, ini, mitad);
		int der = resolver(v, mitad, fin);
		if(izq <= der)
			s = izq;
		else
			s = der;
	}
	return s;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
    if (! std::cin)
        return false;
	std::vector<int> v(n);
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
	
    std::cout << resolver(v, 0, v.size()) << "\n";
    
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
