// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	int pos;
	int botin;
};

// Coste: O(n) siendo n el numero de vagones
// función que resuelve el problema
sol resolver(const std::vector<int> & v, int m) {
    
	sol s = {0, 0};
	for(int i = 0; i < m; i++)
		s.botin = s.botin + v[i];
	
	int aux = s.botin;
	for(int j = 1; j < v.size() - m+1; j++){
		aux = aux - v[j - 1];
		aux = aux + v[j + m - 1];
		
		if(aux >= s.botin){
			s.botin = aux;
			s.pos = j;
		}
	}
	return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n, m;
	std::cin >> n >> m;
	std:: vector<int> tren(n);
	
	for(int i = 0; i < tren.size(); i++)
		std::cin >> tren[i];
	
    sol s = resolver(tren, m);
    // escribir sol
	std::cout << s.pos << " " << s.botin << "\n";
	
}

int main() {
	
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
	
    return 0;
}
