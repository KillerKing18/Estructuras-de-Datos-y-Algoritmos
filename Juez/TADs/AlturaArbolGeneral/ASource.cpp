#include<iostream>
#include"Arbin.h"
#include<string>
#include<algorithm>

using namespace std;

void solveCase();
void calcularAltura(int altura, int & maxAltura);

int main() {
	solveCase();
	return 0;
}

void solveCase() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		int altura = 1;
		int maxAltura = 1;
		calcularAltura(altura, maxAltura);
		cout << maxAltura << endl;
	}
}

void calcularAltura(int altura, int & maxAltura) {

	int raiz;

	cin >> raiz;

	if (raiz == 0)
		maxAltura = max(altura, maxAltura);
	else
		for (int i = 0; i < raiz; i++)
			calcularAltura(altura + 1, maxAltura);
}