//*****************
// IMPORTANTE
//
// ALVARO BERZOSA
// Usuario del juez de clase E09
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo empleado
// Coste del algoritmo. Incluye recurrencia y desplegado de la recurrencia
//
// Y no olvides poner comentarios en el codigo
//*******************************

// Aqui las funciones implementadas por el alumno

struct sol {
	bool ok = false;
	int pCorte;
	int pos;
	int pos2;
};

//T(n) = T(n/2) + c1 - > O(logn) Solo usa la mitad de los elementos

sol resolver(const std::vector<int>& v1, const std::vector<int>& v2, int ini, int fin) {

	sol s;

	if (ini == fin) {
		if (v1[ini] == v2[ini]) {
			s.ok = true;
			s.pCorte = ini;
			s.pos = -1;
			s.pos2 = -1;
		}
		else {
			s.ok = false;
			s.pCorte = -1;
			s.pos = 0;
			s.pos2 = 1;
		}
	}
	else if (ini + 1 == fin) {
		if (v1[ini] == v2[ini]) {
			s.ok = true;
			s.pCorte = ini;
			s.pos = -1;
			s.pos2 = -1;
		}
		else if(v1[fin] == v2[fin]) {
			s.ok = true;
			s.pCorte = fin;
			s.pos = -1;
			s.pos2 = -1;
		}
		else if(v1[ini] > v2[ini]) {
			s.ok = false;
			s.pCorte = -1;
			s.pos = ini + 1;
			s.pos2 = fin;
		}
		else{
			s.ok = false;
			s.pCorte = -1;
			s.pos = ini;
			s.pos2 = fin;
		}
	}
	else {
		int mitad = (ini + fin) / 2;
		
		if (v1[mitad] == v2[mitad]) {
			s.ok = true;
			s.pCorte = mitad;
			s.pos = -1;
			s.pos2 = -1;
		}
		else if (v1[mitad] > v2[mitad]) {
			s = resolver(v1, v2, ini, mitad);
		}
		else {
			s = resolver(v1, v2, mitad, fin);
		}
	}
	return s;

}

bool resuelveCaso()
{
	int numElem;
	std::cin >> numElem;
	if (numElem == 0) return false;
	std::vector<int> v1(numElem);
	std::vector<int> v2(numElem);
	for (int& i : v1) std::cin >> i;
	for (int& i : v2) std::cin >> i;

	// Aqui codigo del alumno
	sol s;
	if(v1[numElem - 1] < v2[numElem - 1]){
		s.ok = false;
		s.pos = numElem - 1;
		s.pos2 = numElem;
	}
	else if(v1[0] > v2[0]){
		s.ok = false;
		s.pos = -1;
		s.pos2 = 0;
	}
	else{
		s = resolver(v1, v2, 0, v1.size() - 1);
	}
	
	if (s.ok)
		std::cout << "SI " << s.pCorte << "\n";
	else
		std::cout << "NO " << s.pos << " " << s.pos2 << "\n";

	return true;

}

int main() {
	while (resuelveCaso())
		;

	return 0;
}
