// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol{
	int n = -1;
	bool  ok = false;
};

//Coste O(log(n))
// función que resuelve el problema
sol resolver(const std::vector<int> &v, int ini, int fin, const int cantado) {
    
	sol s;
	
	if(ini + 1 == fin){
		if(v[ini] == cantado + ini){
			s.n = v[ini];
			s.ok = true;
		}
		else if(v[fin] == cantado + fin){
			s.n = v[fin];
			s.ok = true;
		}
	}
	else{
		int mitad = (ini + fin) / 2;
		if(v[mitad] == cantado + mitad){
			s.n = v[mitad];
			s.ok = true;
		}
		else{
			if(v[mitad] > cantado + mitad)
				s = resolver(v, ini, mitad, cantado);
			else
				s = resolver(v, mitad, fin, cantado);
		}
	}
	
	return s;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n, cantado;
	std:: cin >> n >> cantado;
	std::vector<int> v(n);
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
    
	sol s = resolver(v, 0, v.size(), cantado);
	if(s.ok)
		std::cout << s.n << "\n";
	else
		std::cout << "NO \n";

    // escribir sol
    
    
}

int main() {
	
    // Para la entrada por fichero.
    // Comentar para acepta el reto
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
