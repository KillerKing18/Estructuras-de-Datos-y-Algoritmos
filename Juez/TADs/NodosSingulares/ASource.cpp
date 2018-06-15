#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

int resolverArbol(Arbin<int> arbol, int arriba, int & abajo);

Arbin<int> readTree(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = readTree(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = readTree(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	
	while (cin.peek() != EOF) {
		int abajo;
		cout << resolverArbol(readTree(cin), 0, abajo);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}

int resolverArbol(Arbin<int> arbol, int arriba, int & abajo) {
	if (arbol.esVacio())
		return 0;

	int raiz = arbol.raiz();

	if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
		abajo = raiz;
		if (arriba == 0)
			return 1;
		else
			return 0;
	}

	int abajoIzq = 0;
	int abajoDer = 0;
	int singularesIzq = 0;
	int singularesDer = 0;

	singularesIzq = resolverArbol(arbol.hijoIz(), arriba + raiz, abajoIzq);
	singularesDer = resolverArbol(arbol.hijoDr(), arriba + raiz, abajoDer);

	abajo = abajoIzq + abajoDer + raiz;

	if (abajoIzq + abajoDer == arriba)
		return singularesIzq + singularesDer + 1;
	else
		return singularesIzq + singularesDer;
}