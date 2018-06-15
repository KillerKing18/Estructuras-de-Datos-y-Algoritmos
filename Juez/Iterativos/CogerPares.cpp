#include<iostream>
using namespace std;

int paresCreciente(int v[], int n);
void solveCase();

int paresCreciente(int v[], int n)
{
	bool todoPares = false;
	int contadorProximoPar = 0, pares = 0;
	int contadorActual = 0;
	while (contadorActual < n)
	{
		if (v[contadorActual] % 2 == 0)
		{
			v[contadorProximoPar] = v[contadorActual];
			contadorActual++;
			contadorProximoPar++;
			pares++;
		}
		else
		{
			contadorActual++;
		}
	}
	return pares;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m, n, pares;
	int* v = new int[1100000];

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		pares = paresCreciente(v, n);
		int k = 0;
		if (pares > 0) 
		{
			while (k < pares - 1)
			{
				cout << v[k] << " ";
				k++;
			}
			cout << v[k];
		}
		cout << endl;
	}
}