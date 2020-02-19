//ALVARO BERZOSA TORDESILLAS
//E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct solucion{
	int suma;
	bool ok;
};

// O(log n)
// función que resuelve el problema
solucion resolver(const std::vector<int> &v, int ini, int fin) {
    
	solucion sol, solDer, solIzq;
	solDer.ok = true;
	solDer.suma = 0;
	solIzq.ok = true;
	solIzq.suma = 0;
	
	if(ini + 1 == fin){
		sol.ok = true;
		sol.suma = v[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		solIzq = resolver(v, ini, mitad);
		solDer = resolver(v, mitad, fin);
		sol.suma = solIzq.suma + solDer.suma;
		sol.ok = solIzq.ok && solDer.ok && solIzq.suma < solDer.suma;
	}
	
	return sol;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
	int filas, columnas;
	
	std::cin >> filas;
    if (! std::cin)
        return false;
    
	std::cin >> columnas;
	
	std::vector<int> v(columnas);
	int cont = 0;
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++)
			std::cin >> v[j];
		if(resolver(v, 0, v.size()).ok)
			cont++;
	}
	
	if(cont == filas)
		std::cout << "SI \n";
	else
		std::cout << "NO \n";
	
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
