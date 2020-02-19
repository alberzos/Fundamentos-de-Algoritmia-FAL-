// ALVARO BERZOSA TORDESILLAS
// E09


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct solucion{
	int pos;
	bool encontrado;
};

//O(n) porque solo va a un lado del vector
// función que resuelve el problema
solucion resolver(const std::vector<char> &v, int ini, int fin) {
    
	solucion sol = {-1, false};
	
	if(ini + 1 == fin){
		if(v[fin] - v[ini] > 1){
			sol.pos = ini;
			sol.encontrado = true;
		}
	}
	else{
		int mitad = (ini + fin) / 2;
		solucion izq = resolver(v, ini, mitad);
		if(izq.encontrado)
			return izq;
		solucion der = resolver(v, mitad, fin);
		if(der.encontrado)
			return der;
	}
	
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	solucion sol;
	sol = {-1, false};
	char ini, fin;
	std::string prisionero;
	std::vector<char> v;
	
	std::cin >> ini >> fin;
	std::cin.ignore(256, '\n');
	std::getline(std::cin, prisionero);
	
	for(int i = 0; i < prisionero.size(); i++){
		if(prisionero[i] != ' ')
			v.push_back(prisionero[i]);
	}
	
	if(ini != v[0]){
		sol.encontrado = true;
		std:: cout << ini << '\n';
	}
	
	if(fin != v[v.size() - 1]){
		sol.encontrado = true;
		std:: cout << fin << '\n';
	}
	
	if(!sol.encontrado){
		sol = resolver(v, 0, v.size() - 1);
		char aux = v[sol.pos];
		aux++;
		std::cout << aux << '\n';
	}
	
	
    
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
