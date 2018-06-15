#include<iostream>
#include<string>
#include<algorithm>
#include"Pelicula.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void solveCase(int cases);


int main() {
	int cases;
	cin >> cases;
	while (cases != 0) {
		solveCase(cases);
		cin >> cases;
	}
	return 0;
}

void solveCase(int cases) {
	Pelicula *v = new Pelicula[cases];
	Hora horaComienzo, duracion;
	string titulo;
	char espacio;

	for (int i = 0; i < cases; i++) {
		cin >> horaComienzo >> duracion;
		cin.get(espacio);
		getline(cin, titulo);
		v[i] = Pelicula(titulo, horaComienzo, duracion);
	}

	sort(v, v + cases);

	Hora suma;
	for (int i = 0; i < cases; i++) {
		suma = v[i]._inicio + v[i]._duracion;
		cout << suma << " " << v[i]._titulo << endl;
	}
	cout << "---" << endl;
	delete[]v;
	v = NULL;
}