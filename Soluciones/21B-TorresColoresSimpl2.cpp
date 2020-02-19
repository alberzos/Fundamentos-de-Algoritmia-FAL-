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

bool esValida(const std::vector<int> &sol, int etapa){
	
	if(etapa > 0){
		if(sol[etapa] == 2){
			if(sol[etapa - 1] == 2) // Nunca coloca dos piezas verdes juntas
				return false;
		}
	}
	return true;
	
}

// función que resuelve el problema
void resolver(pieza piezas, std::vector<int> &sol, int etapa) {
    
	for(int i = 0; i < 3; i++){
		sol[etapa] = i;
		if(esValida(sol, etapa)){
			
			if(etapa == sol.size() - 1){
				// Escribir la solucion
				for(int i = 0; i < sol.size(); i++){
					if(sol[i] == 0)
						std::cout << "azul" << " ";
					else if(sol[i] == 1)
						std::cout << "rojo" << " ";
					else if(sol[i] == 2)
						std::cout << "verde" << " ";
				}
				std::cout << "\n";
			}
			else
				resolver(piezas, sol, etapa + 1);
			
		}
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	pieza piezas;
	
	std::cin >> altura;
	piezas.azul = altura;
	piezas.rojo = altura;
	piezas.verde = altura;
	std::vector<int> sol(altura);

	if (altura == 0)
        return false;
	
    sol[0] = 1;
	if (altura == 1)
		std::cout << "rojo" << std::endl;
	else
		resolver(piezas, sol, 1);
	
    // escribir sol
	std::cout << "\n";
    return true;
    
}

int main() {
	
	
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   /* #ifndef DOMJUDGE
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
