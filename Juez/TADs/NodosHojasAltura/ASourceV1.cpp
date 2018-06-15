#include<iostream>
#include"Arbin.h"
#include<string>

using namespace std;

void solveCase();
void resolverArbol(Arbin<int> arbol);

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
	cout << arbol.numNodos() << " " << arbol.numHojas() << " " << arbol.talla() << endl;
}