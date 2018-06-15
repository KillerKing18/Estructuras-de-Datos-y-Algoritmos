#include<iostream>
#include"Arbin.h"
#include<string>
#include<algorithm>

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);
int calcularArbol(Arbin<int> arbol, int & excursionistas, int & excursionistasMayor);
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
	int excursionistas = 0;
	int excursionistasMayor = 0;
	cout << calcularArbol(arbol, excursionistas, excursionistasMayor);
	cout << " " << excursionistasMayor << endl;
}

int calcularArbol(Arbin<int> arbol, int & excursionistas, int & excursionistasMayor) {
	if (arbol.esVacio())
		return 0;

	int raiz = arbol.raiz();

	int excursionistasIzq = 0;
	int excursionistasDer = 0;
	
	int izquierda = calcularArbol(arbol.hijoIz(), excursionistasIzq, excursionistasMayor);
	int derecha = calcularArbol(arbol.hijoDr(), excursionistasDer, excursionistasMayor);

	excursionistas = max(excursionistasIzq, excursionistasDer) + raiz;
	if (excursionistas > excursionistasMayor)
		excursionistasMayor = excursionistas;

	if (raiz != 0 && izquierda == 0 && derecha == 0)
		return izquierda + derecha + 1;
	else
		return izquierda + derecha;
}