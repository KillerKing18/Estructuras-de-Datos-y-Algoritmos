#include<iostream>
using namespace std;

void generar(int k, int n, int d, int e, int sol[], int veces[]);
void solveCase();

void generar(int k, int n, int d, int e, int sol[], int veces[])
{
	for (int i = sol[k - 1]; i <= sol[k - 1] + 1; i++)
	{
		if (veces[i - e] < d) // Satisfactibilidad
		{
			sol[k] = i;
			veces[i - e]++; // Marcaje
			
			if (k == n - 1) // Es Solución
			{
				for (int j = 0; j < n - 1; j++)
					cout << sol[j] << " ";
				cout << sol[n - 1] << endl;
			}
			else
				generar(k + 1, n, d, e, sol, veces);

			veces[i - e]--; // Desmarcaje
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
	int m = 0, n = 0, d = 0, e = 0;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> n >> d >> e;
		int* sol = new int[n];
		int* veces = new int[n];
		for (int j = 0; j < n - 1; j++)
			veces[j] = 0;
		sol[0] = e;
		veces[0] = 1;
		if (n == 1)
			cout << e << endl;
		else
			generar(1, n, d, e, sol, veces);
	}
}