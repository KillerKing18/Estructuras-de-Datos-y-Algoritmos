#include <iostream>
#include<string>
using namespace std;

bool solveCase();
void canicas(int v[], int ini, int end, int &ganadorFinal);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int n;
	int* v = new int[1100000];
	string* p = new string[1100000];

	if (cin >> n)
	{
		int ganadorFinal = 0;
		for (int i = 0; i < n; i++)
			cin >> p[i] >> v[i];
		canicas(v, 0, n - 1, ganadorFinal);
		cout << p[ganadorFinal] << " "<< v[ganadorFinal] << endl;
		return true;
	}
	else
		return false;
}

void canicas(int v[], int ini, int end, int &ganadorFinal)
{
	int middle = (ini + end) / 2;
	if (end - ini == 1)
	{
		if (v[ini] >= v[end])
		{
			v[ini] += v[end] / 2;
			ganadorFinal = ini;
		}
		else
		{
			v[end] += v[ini] / 2;
			ganadorFinal = end;
		}
	}
	else
	{
		int ganadorIzquierda, ganadorDerecha;

		canicas(v, ini, middle, ganadorIzquierda);
		canicas(v, middle + 1, end, ganadorDerecha);

		if (v[ganadorIzquierda] >= v[ganadorDerecha])
		{
			v[ganadorIzquierda] += v[ganadorDerecha] / 2;
			ganadorFinal = ganadorIzquierda;
		}
		else
		{
			v[ganadorDerecha] += v[ganadorIzquierda] / 2;
			ganadorFinal = ganadorDerecha;
		}
	}
}