// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// Las etapas son los niños y las ramas los juguetes

bool esValida(std::vector<int> &sol, int etapa, int i, std::vector<std::string> &v){
	
	// No entregaran a un nino dos juguetes del mismo tipo
	if(etapa > 0 && etapa % 2 != 0 && (v[i] == v[sol[etapa - 1]]))
		return false;
	// El identificador del primer juguete sea menor que el identificador del segundo
	if(etapa > 0 && etapa % 2 != 0 && (sol[etapa] < sol[etapa - 1]))
		return false;

	return true;
	
}

// función que resuelve el problema
void resolver(std::vector<int> &sol, int etapa, std::vector<std::string> &v, bool &ok) {
    
	for(int i = 0; i < v.size(); i++){
		sol[etapa] = i;;
		if(esValida(sol, etapa, i, v)){
			if(etapa == sol.size() - 1){
				for(int x = 0; x < sol.size(); x++)
					std::cout << sol[x] << " ";
				std::cout << "\n";
				ok = true;
			}
			else
				resolver(sol, etapa + 1, v, ok);
		}
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nJuguetes, nNinios;
	std::cin >> nJuguetes >> nNinios;
	
	std::vector<std::string> v(nJuguetes);
	std::vector<int> sol(nNinios * 2);
	bool ok = false;
	
    if (! std::cin)
        return false;
	
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i];
	
	resolver(sol, 0, v, ok);
	
	if(!ok)
		std::cout << "SIN SOLUCION \n";
	std::cout << "\n";
	
	
	
    
    
    // escribir sol
    
    
    return true;
    
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
    
    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	 
    return 0;
}
