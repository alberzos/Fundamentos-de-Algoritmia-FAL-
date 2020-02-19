// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida(const std::vector<int> &precipitacion, const std::vector<int> &soportado,
			  int k, const std::vector<int> &sol, const std::vector<int> &marcas, int i){
	if(soportado[i] < precipitacion[k]) // El abrigo soporta la lluvia
		return false;
	if(k > 0 && sol[k] == sol[k - 1]) // No se pone el mismo dos veces seguidas
		return false;
	if(marcas[i] > 2 + k/3) // dias(a,i)≤2+i/3
		return false;
	
	return true;
}

// función que resuelve el problema
int resolver(const std::vector<int> &precipitacion, const std::vector<int> &soportado,
			 int k, std::vector<int> &sol, std::vector<int> &marcas) {
    
	int solucion = 0;
	for(int i = 0; i < soportado.size(); i++){
		sol[k] = i;
		// Marcas
		marcas[i]++;
		if(esValida(precipitacion, soportado, k, sol, marcas, i)){
			if(k == precipitacion.size() - 1){
				if(sol[0] != sol[k])
					solucion++;
			}
			else
				solucion = solucion + resolver(precipitacion, soportado, k+1, sol, marcas);
		}
		//Desmarcas
		marcas[i]--;
	}
	return solucion;
	
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nDias, nAbrigos;
	
	std::cin >> nDias >> nAbrigos;
    if (nDias == 0)
        return false;
	
	std::vector<int> precipitacion(nDias);
	std::vector<int> soportado(nAbrigos);
	std::vector<int> sol(nDias);
	std::vector<int> marcas(nAbrigos);
	
	for(int i = 0; i < precipitacion.size(); i++)
		std::cin >> precipitacion[i];
	for(int i = 0; i < soportado.size(); i++)
		std::cin >> soportado[i];
	
	int solucion = resolver(precipitacion, soportado, 0, sol, marcas);
	
	if(solucion == 0)
		std::cout << "Lo puedes comprar \n";
	else
		std::cout << solucion << "\n";
    
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
