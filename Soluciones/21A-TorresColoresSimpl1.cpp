// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct pieza{
	int azul = 0;
	int rojo = 0;
	int verde = 0;
};

// función que resuelve el problema
void resolver(pieza piezas, pieza &marcas, std::vector<int> &sol, int etapa, bool &ok) {
    
	for(int i = 0; i < 3; i++){
		sol[etapa] = i;
		// Marcar
		if(i == 0)
			marcas.azul++;
		else if(i == 1)
			marcas.rojo++;
		else if(i == 2)
			marcas.verde++;
		
		if(etapa == sol.size() - 1){
			// Escribir la solucion
			for(int i = 0; i < sol.size(); i++){
				if(sol[i] == 0)
					std::cout << "azul" << " ";
				else if(sol[i] == 1)
					std::cout << "rojo" << " ";
				if(sol[i] == 2)
					std::cout << "verde" << " ";
				ok = true;
			}
			std::cout << "\n";
		}
		else
			resolver(piezas, marcas, sol, etapa + 1, ok);
		// Desmarcar
		if(i == 0)
			marcas.azul--;
		else if(i == 1)
			marcas.rojo--;
		else if(i == 2)
			marcas.verde--;
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	pieza marcas, piezas;
	bool ok = false;
	
	std::cin >> altura;
	piezas.azul = altura;
	piezas.rojo = altura;
	piezas.verde = altura;
	std::vector<int> sol(altura);

	if (altura == 0)
        return false;
	
   resolver(piezas, marcas, sol, 0, ok);
	if(!ok)
		std::cout << "SIN SOLUCION " << "\n";
    // escribir sol
	std::cout << "\n";
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
