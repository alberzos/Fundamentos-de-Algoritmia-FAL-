// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(const std:: vector<int> &v, int pos) {
    
	int maxMitadIzq = v[0];
	for(int i = 1; i <= pos; i++){
		if(maxMitadIzq < v[i])
			maxMitadIzq = v[i];
	}
	int minMitadDer = maxMitadIzq + 1;
	for(int i = pos + 1; i < v.size(); i++){
		if(v[i] < minMitadDer)
			minMitadDer = v[i];
	}
	
	return (maxMitadIzq < minMitadDer);
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int tam, pos;
	std::cin >> tam >> pos;
	
	std::vector<int> v(tam);
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
    
     if(resolver(v, pos))
		std::cout << "SI \n";
	else
		std::cout << "NO \n";
    // escribir sol
    
    
}

int main() {
	/*
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    */
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	
    return 0;
}
