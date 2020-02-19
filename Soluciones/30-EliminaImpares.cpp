// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> &v) {
    
	int y = 0;
	for (int i = 0; i < v.size(); i++){
		if(v[i] % 2 == 0){
			v[y] = v[i];
			y++;
		}
	}
	v.resize(y);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long long int tam;
	std::cin >> tam;
	
	std::vector<int> v(tam);
	for(int i = 0; i< v.size(); i++)
		std::cin >> v[i];
    
	resolver(v);
	for(int i = 0; i< v.size(); i++)
		std::cout << v[i] << " ";
	std:: cout << "\n";
    
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
