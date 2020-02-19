// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct juguete{
	int unidades;
	std::string tipo;
};

// Las etapas son los niños y las ramas los juguetes

bool esValida(std::vector<int> &sol, int etapa, int i, std::vector<juguete> &v,
			  const std::vector<std::vector<int>> &matriz, int satisfaccion){
	
	if(v[i].unidades < 0)
		return false;
	if(etapa > 0 && etapa % 2 != 0 && (matriz[etapa / 2][sol[etapa - 1]] + matriz[etapa / 2][sol[etapa]] < satisfaccion))
		return false;
	// No entregaran a un nino dos juguetes del mismo tipo
	if(etapa > 0 && etapa % 2 != 0 && (v[i].tipo == v[sol[etapa - 1]].tipo))
		return false;
	// El identificador del primer juguete sea menor que el identificador del segundo
	if(etapa > 0 && etapa % 2 != 0 && (sol[etapa] < sol[etapa - 1]))
		return false;

	return true;
	
}

// función que resuelve el problema
void resolver(std::vector<int> &sol, int etapa, std::vector<juguete> &v,
			  const std::vector<std::vector<int>> &matriz, int satisfaccion, bool &ok) {
    
	for(int i = 0; i < v.size(); i++){
		sol[etapa] = i;
		// Marcar
		v[i].unidades--;
		if(esValida(sol, etapa, i, v, matriz, satisfaccion)){
			if(etapa == sol.size() - 1){
				for(int x = 0; x < sol.size(); x++)
					std::cout << sol[x] << " ";
				std::cout << "\n";
				ok = true;
			}
			else
				resolver(sol, etapa + 1, v, matriz, satisfaccion, ok);
		}
		// Desmarcar
		v[i].unidades++;
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nJuguetes, nNinios, minSatis;
	std::cin >> nJuguetes >> nNinios >> minSatis;
	
	std::vector<std::vector<int>> matriz(nNinios, std::vector<int>(nJuguetes));
	std::vector<juguete> v(nJuguetes);
	std::vector<int> sol(nNinios * 2);
	bool ok = false;
	
    if (! std::cin)
        return false;
	
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i].unidades;
	for(int i = 0; i < v.size(); i++)
		std::cin >> v[i].tipo;
	
	for(int i = 0; i < nNinios; i++){
		for(int j = 0; j < nJuguetes; j++){
			std::cin >> matriz[i][j];
		}
	}
	
	resolver(sol, 0, v, matriz, minSatis, ok);
	
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
