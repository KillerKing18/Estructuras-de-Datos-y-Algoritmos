#include<iostream>
#include"Arbin.h"
#include<string>
#include<algorithm>

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);
int calcularArbol(Arbin<int> arbol, int & tramos);
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
	int tramos = 0;
	calcularArbol(arbol, tramos);
	cout << tramos << endl;
}

int calcularArbol(Arbin<int> arbol, int & tramos) {
	if (arbol.esVacio())
		return 0;

	if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio())
		return 1;

	int raiz = arbol.raiz();

	int izquierda = calcularArbol(arbol.hijoIz(), tramos);
	if (izquierda >= 3)
		tramos++;
	int derecha = calcularArbol(arbol.hijoDr(), tramos);
	if (derecha >= 3)
		tramos++;

	int res = izquierda + derecha - raiz;

	if (res < 0)
		return 0;
	else
		return res;
}