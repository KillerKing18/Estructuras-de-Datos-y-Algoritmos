#include<iostream>

using namespace std;

void solveCase();
void funcionarios(int k, int n, int sol[], int &coste, int &coste_min, int tiempos[][20], int tiempo_min[]);

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int n, coste, coste_min, tiempo;
	int m[20][20];
	int sol[20];
	int tiempo_min[20];

	cin >> n;
	while (n != 0)
	{
		coste = 0;
		coste_min = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> tiempo;
				if (i == 0)
					tiempo_min[j] = tiempo;
				else
					if (tiempo < tiempo_min[j])
						tiempo_min[j] = tiempo;
				m[i][j] = tiempo;
				coste_min += tiempo;
			}
		}

		for (int k = n - 2; k >= 0; k--)
			tiempo_min[k] = tiempo_min[k] + tiempo_min[k + 1];

		for (int i = 0; i < n; i++)
			sol[i] = 0;

		funcionarios(0, n, sol, coste, coste_min, m, tiempo_min);

		cout << coste_min << endl;

		cin >> n;
	}
}

void funcionarios(int k, int n, int sol[], int &coste, int &coste_min, int tiempos[][20], int tiempo_min[])
{
	for (int i = 0; i < n; i++) {
		if (sol[i] == 0) {
			sol[i] = 1;
			coste = coste + tiempos[k][i];
			if (k == n - 1) { // EsValido
				if (coste < coste_min) // EsMejorSolucion
					coste_min = coste;
			}
			else
				if (coste + tiempo_min[k + 1] < coste_min) // Mejor poda
					funcionarios(k + 1, n, sol, coste, coste_min, tiempos, tiempo_min);
			sol[i] = 0;
			coste = coste - tiempos[k][i];
		}
	}
}