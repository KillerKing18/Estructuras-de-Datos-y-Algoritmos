#include<iostream>

using namespace std;

void solveCase();
void supermercados(int k, int n, int m,int sol[], int mejor_caso[],
	int &coste,int sol_mejor[], int &coste_min, 
	int supers[], int costes[][21], bool &solucion);

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m, num_supers, productos, coste, coste_min;
	bool solucion;
	int costes[60][21];
	int sol[60];
	int sol_mejor[60];
	int mejor_caso[60]; // Utilizado en la mejor poda para almacenar el sumatorio del precio minimo de los productos que quedan por comprar
	int supers[21];
	int precio;
	//int min; // Precio minimo de caulquier producto de cualquier supermercado en la primera poda
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num_supers >> productos;
		solucion = false;
		coste = 0;
		coste_min = 0;
		for (int j = 0; j < num_supers + 1; j++)
			supers[j] = 0;
		for (int l = 1; l < num_supers + 1; l++) {
			for (int k = 0; k < productos; k++) {
				cin >> precio;
				//if (l == 1 && k == 0)
					//min = precio;
				//else
					//if (precio < min)
						//min = precio;
				if (l == 1)
					mejor_caso[k] = precio;
				else
					if (precio < mejor_caso[k])
						mejor_caso[k] = precio;
				costes[k][l] = precio;
				coste_min += precio;
			}
		}
		
		for (int x = productos - 2; x >= 0; x--) { 
			mejor_caso[x] = mejor_caso[x] + mejor_caso[x + 1];
		}// En cada nivel, el array tendra el sumatorio del precio minimo de los productos desde el nivel en el que esta hasta el ultimo nivel

		supermercados(0, productos, num_supers, sol, mejor_caso, coste,
			sol_mejor, coste_min, supers, costes, solucion);

		if (solucion)
			cout << coste_min << endl;
		else
			cout << "Sin solucion factible" << endl;
	}
}

void supermercados(int k, int n, int m, int sol[], int mejor_caso[],
	int &coste, int sol_mejor[], int &coste_min, 
	int supers[], int costes[][21], bool &solucion) {
	for (int i = 1; i <= m; i++) {
		if (supers[i] < 3) {
			sol[k] = i;
			supers[i]++;
			coste = coste + costes[k][i];
			if (k == n - 1) { // EsValido
				if (coste < coste_min) { // EsMejorSolucion
					coste_min = coste;
					solucion = true;
					for (int j = 0; j < n; j++)
						sol_mejor[j] = sol[j];
				}
			}
			else {
				//if (coste + (n - (k + 1)) * min < coste_min) // Poda
				if (coste + mejor_caso[k + 1] < coste_min) // Mejor poda
				supermercados(k + 1, n, m, sol, mejor_caso, coste,
					sol_mejor, coste_min, supers, costes, solucion);
			}
			supers[i]--;
			coste = coste - costes[k][i];
		}
	}
}