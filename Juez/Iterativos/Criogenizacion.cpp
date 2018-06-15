#include<iostream>
using namespace std;

void criogenizacion(long long v[], int n, long long &mayor, long long &fMayor, long long &menor, long long &fMenor);
void solveCase();

void criogenizacion(long long v[], int n, long long &mayor, long long &fMayor, long long &menor, long long &fMenor)
{
	mayor = v[0];
	menor = v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i] == mayor)
		{
			fMayor++;
		}
		if (v[i] == menor)
		{
			fMenor++;
		}
		if (v[i] > mayor)
		{
			fMayor = 1;
			mayor = v[i];
		}
		if (v[i] < menor)
		{
			fMenor = 1;
			menor = v[i];
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
	long long v[10000];
	int m, n = 0;
	long long mayor = 0, menor = 0, fMayor = 0, fMenor = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		n = mayor = menor = fMayor = fMenor = 0;
		cin >> v[j];
		while (v[j] != 0)
		{
			n++;
			j++;
			cin >> v[j];
		}
		criogenizacion(v, n, mayor, fMayor, menor, fMenor);
		cout << menor << " " << fMenor << " " << mayor << " " << fMayor << endl;
	}
}