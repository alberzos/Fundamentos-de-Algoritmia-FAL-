// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct sol {
	int ini;
	int fin;
};

//Coste lineal o(n) siendo n el numero de edificios
// función que resuelve el problema
sol resolver(const std:: vector<int> &v, int altura) {
	
	sol s = {0, -1};
	int longAct = 0, longMax = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > altura)
			longAct++;
		else
			longAct = 0;
		if(longMax < longAct){
			s.ini = i + 1 - longAct;
			s.fin = i;
			longMax = longAct;
		}
	}
	return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int tam, altura;
	std::cin >> tam >> altura;
	
	std::vector<int> v(tam);
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
    
	sol s = resolver(v, altura);

	
	std::cout << s.ini << " " << s.fin << "\n";
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
