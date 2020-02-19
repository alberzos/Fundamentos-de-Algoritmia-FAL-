// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// --------- A MEDIAS ----------
struct sol{
	long int num;
	long int pot;
};

//O(log(n))
// función que resuelve el problema
sol complementario(const long int &n, const long int &pot) {
    
	if(n < 10)
		return {(9 - n) * pot, pot};
	else{
		sol s = complementario(n / 10, pot * 10);
		return {s.num + (9 - (n % 10)) * pot, s.pot};
	}
	
}

sol inverso(const int &n) {
    
	if(n < 10)
		return {n, 10};
	else{
		sol s = inverso(n / 10);
		return {s.num + (n % 10) * s.pot, s.pot * 10};
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long int n;
	
	std::cin >> n;
	sol comp = complementario(n, 1);
	sol inv = inverso(comp.num);
    
    // escribir sol
	std::cout << comp.num << " " << inv.num * (comp.pot / inv.pot)<< "\n";
    
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
