#include<string>
#include<iostream>
#include"TreeMap.h"
#include"Exceptions.h"

using namespace std;

class Banco {
private:
	TreeMap<string, int> map;
public:
	void transfiere(int number, string origen, string destino, int cantidad){
		if (origen != "*" && !map.contains(origen)){
			map.insert(origen, 0);
		}
		if (destino != "*" && !map.contains(destino)){
			map.insert(destino, 0);
		}
		int funds = (origen == "*") ? 0 : map.at(origen);
		if (origen == "*" && destino != "*")	// * 200 Hola
			map.insert(destino, map.at(destino) + cantidad);
		else if (destino == "*" && origen != "*" && funds >= cantidad) // Hola 200 *
			map.insert(origen, funds - cantidad);
		else if (funds >= cantidad) {
			map.insert(origen, funds - cantidad);
			map.insert(destino, map.at(destino) + cantidad);
		}
		else{
			int falta = (cantidad - funds);
			cout << number;
			cout << " ";
			cout << origen;
			cout << " necesita ";
			cout << falta;
			cout << " de ";
			cout << cantidad;
			if (cantidad > 1)
				cout << " Euros";
			else
				cout << " Euro";
			cout << endl;
		}
	}

	void muestraEstado(){
		for (TreeMap<string, int>::ConstIterator iterador = map.cbegin(); iterador != map.cend(); iterador.next()){
			int dinero = iterador.value();
			if (dinero != 0){
				cout << iterador.key() + " ";
				cout << dinero << endl;
			}
		}
		cout << endl;
	}
};