#include<iostream>
#include"Arbin.h"
#include<string>

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);
int calcularArbol(Arbin<int> arbol, int & nodos, int & hojas);

Arbin<int> readTree(istream& in) {
	char c;
	in >> c;
	if (c == '.') 
		return Arbin<int>();
	else if (c == '*') {
		Arbin<int> iz = readTree(in);
		Arbin<int> dr = readTree(in);
		return Arbin<int>(iz, 1, dr);
	}
}

int main() {
	solveCase();
	return 0;
}

void solveCase() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		resolverArbol(readTree(cin));
	}
}

void resolverArbol(Arbin<int> arbol) {
	int nodos, hojas;
	calcularArbol(arbol, nodos, hojas);
	cout << arbol.numNodos() << " " << arbol.numHojas() << " " << arbol.talla() << endl;
}

int calcularArbol(Arbin<int> arbol, int & nodos, int & hojas) {
	if (arbol.esVacio())
		return 0;
	if (arbol.hijoDr().esVacio() && arbol.hijoIz().esVacio()) {
		nodos += 1;
		hojas += 1;
		return 1;
	}
	nodos++;
	int i = calcularArbol(arbol.hijoIz(), nodos, hojas);
	int d = calcularArbol(arbol.hijoDr(), nodos, hojas);

	if (i > d)
		return i;
	else 
		return d;
}