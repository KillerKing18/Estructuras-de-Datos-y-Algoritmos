#include<iostream>

using namespace std;

bool solveCase();
int calcularPrecarios(int altura, int number);

int main() {
	while (solveCase()) {
	}
	return 0;
}

bool solveCase() {
	int number;
	if (cin >> number) {
		int altura = 0;
		cout << calcularPrecarios(altura, number) << endl;
		return true;
	}
	return false;
}

int calcularPrecarios(int altura, int number) {

	int raiz;

	cin >> raiz;

	int precarios = 0;

	if (raiz == 0 && altura >= number)
		precarios = 1;
	else
		for (int i = 0; i < raiz; i++)
			precarios = precarios + calcularPrecarios(altura + 1, number);
	return precarios;
}