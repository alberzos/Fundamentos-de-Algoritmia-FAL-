// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Coste O(n) siendo n la longitud de la valla
// función que resuelve el problema
int resolver(const std:: vector<int> &v, int longitud) {
    
	int sol = -1;
	int contAct = 0;
	int contMax = 0;
	for(int i = 0; i < longitud; i++){
		if(v[i] == 0){
			contAct++;
			if(contAct >= contMax){
				contMax = contAct;
				sol = i - longitud + 1;
			}
		}
	}
	for(int i = longitud; i < v.size(); i++){
		if(v[i - longitud] == 0)
			contAct = contAct - 1;
		if(v[i] == 0){
			contAct++;
			if(contAct >= contMax){
				contMax = contAct;
				sol = i - longitud + 1;
			}
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, m;
	std::cin >> n;
    if (n == 0)
        return false;
	std::cin >> m;
	std::vector<int> v(n);
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
    
    int sol = resolver(v, m);
    
	if(sol == -1 || sol == n && m == 0)
		std:: cout << "No hace falta \n";
	else
		std::cout << sol << "\n";
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
