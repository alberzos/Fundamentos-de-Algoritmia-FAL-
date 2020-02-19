// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Coste O(2en) --> 2t(n-1) + c
// función que resuelve el problema
void resolver(std::vector<std::vector<int>> &v, int a, int b) {
    
	if(v[a][b] == -1){
		if(a == 0 || b == 0)
			v[a][b] = 1;
		else if( a == b)
			v[a][b] = 1;
		else{
			resolver(v, a - 1, b - 1);
			resolver(v, a - 1, b);
			v[a][b] = v[a - 1][b - 1] + v[a - 1][b];
		}
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int a, b;
	std::cin >> a;
    if (! std::cin)
        return false;
	std::cin >> b;
	std::vector<std::vector<int>> v(a + 1, std::vector<int>(b + 1));
	
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			v[i][j] = -1;
		}
	}
	resolver(v, a, b);
	std:: cout << v[a][b] << "\n";
    
    
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
