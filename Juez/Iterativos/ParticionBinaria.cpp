#include<iostream>
using namespace std;

int particion(long long int v[], long long int n);
void solveCase();

int particion(long long int v[], long long int n)
{
	bool cambiado = false;
	long long int positiveCounter = 0, aux, pos = 0;
	long long int negativeCounter = n - 1;
	while ((positiveCounter < n) && (positiveCounter != negativeCounter + 1))
	{
		cambiado = false;
		if (v[positiveCounter] >= 0)
		{
			positiveCounter++;
			pos = positiveCounter;
		}
		else
		{
			while (!cambiado && (positiveCounter != negativeCounter + 1))
			{
				if (v[negativeCounter] >= 0) // Hemos encontrado un número positivo al final del array
				{
					aux = v[positiveCounter];
					v[positiveCounter] = v[negativeCounter]; 
					v[negativeCounter] = aux;	// Intercambiamos el número positivo del final del array por el número negativo del principio del array
					negativeCounter--;
					cambiado = true;
				}
				else // Al final del array hay un número negativo, así que seguimos buscando un número positivo de derecha a izquierda
					negativeCounter--;
			}
		}
	}
	return pos;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	long long int m, n, pos;
	long long int* v = new long long int[1100000];

	cin >> m;
	for (long long int j = 0; j < m; j++)
	{
		cin >> n;
		for (long long int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		pos = particion(v, n);
		long long int k = 0;
		if (n > 0)
		{
			while (k < n - 1)
			{
				cout << v[k] << " ";
				k++;
			}
			cout << v[k];
		}
		cout << endl << pos << endl;
	}
}