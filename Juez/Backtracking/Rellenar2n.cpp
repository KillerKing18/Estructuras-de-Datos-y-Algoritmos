#include<iostream>
using namespace std;

void rellenar(int k, int n, int sol[], int posiciones[], int &soluciones);
void solveCase();

void rellenar(int k, int n, int sol[], int posiciones[], int &soluciones)
{
	int anterior;
	for (int i = 1; i <= n; i++)
	{
		if ((posiciones[i] == -1) || (k - posiciones[i] == i + 1)) // Satisfactibilidad
		{
			sol[k] = i;
			if (posiciones[i] == -1) // -1 = todavia no lo he puesto
				posiciones[i] = k;
			else  // lo he puesto 1 vez
			{
				anterior = posiciones[i];
				posiciones[i] = -2;	// -2 = ya lo he puesto dos veces
			}
			if (k == (2 * n) - 1) // Es Solución
			{
				soluciones++;
				for (int j = 0; j < (2 * n) - 1; j++)
					cout << sol[j] << " ";
				cout << sol[(2 * n) - 1] << endl;
			}
			else
				rellenar(k + 1, n, sol, posiciones, soluciones);
			if (posiciones[i] == -2)
				posiciones[i] = anterior;
			else
				posiciones[i] = -1;
		}
	}
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m = 0, n = 0;
	int k, soluciones;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> n;
		int* sol = new int[2 * n];
		int* posiciones = new int[n];
		for (int j = 1; j <= n; j++)
			posiciones[j] = -1;
		k = 0;
		soluciones = 0;
		rellenar(k, n, sol, posiciones, soluciones);
		cout << "Soluciones: " << soluciones << endl;
	}
}