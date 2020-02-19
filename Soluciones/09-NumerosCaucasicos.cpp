// ALVARO BERZOSA TORDESILLAS
//E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol{
	bool ok;
	int n;
};

//O(n)
// función que resuelve el problema
sol resolver(const std::vector<int> &v, int ini, int fin) {
    
	sol s;
	s = {false, 0};
	if(ini + 1 == fin){
		s.ok = true;
		if(v[ini] % 2 == 0)
			s.n++;
	}
	else{
		int mitad = (ini + fin) / 2;
		sol izq = resolver(v, ini, mitad);
		if(izq.ok == true){
			sol der = resolver(v, mitad, fin);
			if(der.ok == true && abs(izq.n - der.n) <= 2){
				s.ok = true;
				s.n = izq.n + der.n;
			}
		}
	}
	return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
    if (n == 0)
        return false;
    
	std::vector<int> v(n);
	for(int i=0; i<n; i++)
		std::cin >> v[i];
	
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
