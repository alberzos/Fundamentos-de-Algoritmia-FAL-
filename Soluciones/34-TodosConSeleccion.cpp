// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int maxRacha;
	int nVeces;
	int nUltimos;
};

// Coste lineal O(n) siendo n el numero de elementos del vector
// función que resuelve el problema
sol resolver(const std::vector<int> &v) {
    
	sol s = {0, 0, 0};
	int cont = 0;
	int pos = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > 0) { // Ganan
			cont++;
			if(s.maxRacha < cont){
				s.maxRacha = cont;
				s.nVeces = 1;
				pos = i + 1;
			}
			else if(s.maxRacha == cont){
				s.nVeces++;
				pos = i + 1;
			}
		}
		else
			cont = 0;
	}
	s.nUltimos = v.size() - pos;
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
	
    sol s = resolver(v);
	
	std::cout << s.maxRacha << " " << s.nVeces << " " << s.nUltimos << "\n";
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
