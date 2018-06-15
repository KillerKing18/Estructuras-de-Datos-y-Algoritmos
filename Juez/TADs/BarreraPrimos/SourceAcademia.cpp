#include<iostream>
#include<string>
#include<algorithm>
#include"Arbin.h"

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);
bool calcularArbol(Arbin<int> arbol, int & numero, int & mejorProfundidad, int nivel);
bool esPrimo(int number);
int ab_primosRecursivo(Arbin<int> arbol, int & altura);
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
	int nivelInicio = 1;

	int res = ab_primosRecursivo(arbol, nivelInicio);

	if(res != 1)
		cout << res << " " << nivelInicio << endl;
	else
		cout << "NO HAY" << endl;
}

bool calcularArbol(Arbin<int> arbol, int & numero, int & mejorProfundidad, int nivel) {
	if (arbol.esVacio() || esPrimo(arbol.raiz()))
		return false;

	int raiz = arbol.raiz();

	if (raiz % 7 == 0) {
		numero = raiz;
		mejorProfundidad = nivel;
		return true;
	}

	bool izq = false;

	if (mejorProfundidad > nivel + 1 || mejorProfundidad == -1) {
		izq = calcularArbol(arbol.hijoIz(), numero, mejorProfundidad, nivel + 1);
		if (!izq || (izq && mejorProfundidad > nivel + 1))
			calcularArbol(arbol.hijoDr(), numero, mejorProfundidad, nivel + 1);
	}

	return mejorProfundidad != -1;
}

int ab_primosRecursivo(Arbin<int> arbol, int & altura) {
	if (arbol.esVacio() || esPrimo(arbol.raiz()))
		return 1;
	else {
		int raiz = arbol.raiz();
		if (raiz % 7 == 0) {
			return raiz;
		}
		else {
			int altIzq = altura + 1;
			int altDer = altura + 1;
			int res1 = ab_primosRecursivo(arbol.hijoIz(), altIzq);
			int res2 = ab_primosRecursivo(arbol.hijoDr(), altDer);
			if (res1 != 1 && (altIzq <= altDer || res2 == 1)) {
				altura = altIzq;
				return res1;
			}
			else if (res2 != 1) {
				altura = altDer;
				return res2;
			}
			else 
				return 1;
		}
	}
}

bool esPrimo(int number) {
	bool isPrime = true;

	for (int i = 2; i <= number / 2; ++i)
	{
		if (number % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}