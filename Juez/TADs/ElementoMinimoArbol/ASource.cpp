#include<iostream>
#include"Arbin.h"
#include<string>
#include<algorithm>

using namespace std;

bool solveCase();
template<class T>
T resolverArbol(Arbin<T> arbol);
Arbin<int> readIntegerTree();
Arbin<string> readStringTree();


Arbin<int> readIntegerTree() {
	int n;
	cin >> n;
	if (n == -1) return Arbin<int>();
	Arbin<int> izd = readIntegerTree();
	Arbin<int> dcha = readIntegerTree();
	return Arbin<int>(izd, n, dcha);
}

Arbin<string> readStringTree() {
	string s;
	cin >> s;
	if (s == "#") return Arbin<string>();
	Arbin<string> izd = readStringTree();
	Arbin<string> dcha = readStringTree();
	return Arbin<string>(izd, s, dcha);
}

int main() {
	while (solveCase()) {

	}
	return 0;
}

bool solveCase() {
	string str;
	if (cin >> str) {
		if (str == "N") {
			cout << resolverArbol(readIntegerTree()) << endl;
		}
		else if (str == "P") {
			cout << resolverArbol(readStringTree()) << endl;
		}
		return true;
	}
	else
		return false;
}

template<class T>
T resolverArbol(Arbin<T> arbol) {
	T izq, der, menor;
	menor = arbol.raiz();
	if (!arbol.hijoIz().esVacio()) {
		izq = resolverArbol(arbol.hijoIz());
		menor = min(izq, menor);
	}
	if (!arbol.hijoDr().esVacio()) {
		der = resolverArbol(arbol.hijoDr());
		menor = min(der, menor);
	}
	return menor;
}