#include<iostream>
#include<string>
#include"Banco.h"
#include"TreeMap.h"

using namespace std;

void solveCase();

int main(){
	solveCase();
	return 0;
}

void solveCase(){
	int n;
	while (cin >> n && n){
		TreeMap<int, int> mapa;
		Banco b;
		for (int i = 0; i < n; i++){
			string origen, destino;
			int cantidad;
			cin >> origen >> destino >> cantidad;
			b.transfiere(i + 1, origen, destino, cantidad);
		}
		b.muestraEstado();
	}
}