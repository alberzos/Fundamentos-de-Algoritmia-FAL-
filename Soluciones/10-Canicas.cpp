// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct jugador{
	std::string nombre;
	int canicas;
};

//Coste O(n) porque es 2T(n/2) + c1
// función que resuelve el problema
jugador resolver(const std::vector<jugador> &v, int ini,int fin) {
	jugador s;
	if(ini + 2 == fin){ // Caso base con dos elementos
		if(v[ini].canicas >= v[ini + 1].canicas){
			s.nombre = v[ini].nombre;
			s.canicas = v[ini].canicas + (v[ini + 1].canicas / 2);
		}
		else{
			s.nombre = v[ini + 1].nombre;
			s.canicas = v[ini + 1].canicas + (v[ini].canicas / 2);
		}
	}
	else{
		int mitad = (ini + fin) / 2;
		jugador izq = resolver(v, ini, mitad);
		jugador der = resolver(v, mitad, fin);
		if(izq.canicas >= der.canicas){
			s.nombre = izq.nombre;
			s.canicas = izq.canicas + (der.canicas / 2);
		}
		else{
			s.nombre = der.nombre;
			s.canicas = der.canicas + (izq.canicas / 2);
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
    if (! std::cin)
        return false;
	std::vector<jugador> v(n);

	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i].nombre >> v[i].canicas;
	
	jugador sol;
	sol = resolver(v, 0, v.size());
	std::cout << sol.nombre << " " << sol.canicas << "\n";
    
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
