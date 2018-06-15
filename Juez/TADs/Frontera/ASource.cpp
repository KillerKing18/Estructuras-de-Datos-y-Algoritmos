#include<iostream>
#include"Arbin.h"
#include<string>
#include<algorithm>

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);
void calcularArbol(Arbin<int> arbol);
Arbin<int> readTree();


Arbin<int> readTree() {
	int n;
	cin >> n;
	if (n == -1) return Arbin<int>();
	Arbin<int> izd = readTree();
	Arbin<int> dcha = readTree();
	return Arbin<int>(izd, n, dcha);
}

int main() {
	solveCase();
	return 0;
}

void solveCase() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		resolverArbol(readTree());
	}
}

void resolverArbol(Arbin<int> arbol) {
	calcularArbol(arbol);
	cout << endl;
}

void calcularArbol(Arbin<int> arbol) {
	if (arbol.esVacio())
		return;
	if (arbol.hijoDr().esVacio() && arbol.hijoIz().esVacio()) {
		cout << arbol.raiz() << " ";
		return;
	}
	if(!arbol.hijoIz().esVacio())
		calcularArbol(arbol.hijoIz());
	if (!arbol.hijoDr().esVacio())
		calcularArbol(arbol.hijoDr());
}