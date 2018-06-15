#include"Hora.h"
#include"List.h"
#include<iostream>

using namespace std;

void solveCase();
void calcularTrenes(List<Hora> listaTrenes, Hora h);

int main() {
	solveCase();
	return 0;
}

void solveCase() {
	int numTrenes, numConsultas;
	Hora h;
	List<Hora> listaTrenes;
	cin >> numTrenes >> numConsultas;
	while (numConsultas != 0 || numTrenes != 0) {
		listaTrenes = List<Hora>();
		for (int i = 0; i < numTrenes; i++) {
			cin >> h;
			listaTrenes.push_back(h);
		}
		for (int j = 0; j < numConsultas; j++) {
			try {
				cin >> h;
				calcularTrenes(listaTrenes, h);
			}
			catch (int a){
				cout << "ERROR" << endl;
			}
		}	
		cout << "---" << endl;
		cin >> numTrenes >> numConsultas;
	}
}

void calcularTrenes(List<Hora> listaTrenes, Hora h) {
	bool pasado = false;
	auto it = listaTrenes.cbegin();
	Hora horaActual;
	bool encontrado = false;
	while (!pasado && it != listaTrenes.cend()) {
		horaActual = it.elem();
		if (!(horaActual < h))
			pasado = true;
		it.next();
	}
	if (pasado) {
		cout << horaActual << endl;
	}
	else
		cout << "NO" << endl;
}