#include<iostream>
using namespace std;

bool alg(int v[], int ini, int end);
void solveCase();

bool alg(int v[], int ini, int end)
{
	if (ini == end)
		return true;

	if (v[end] - v[ini] > end - ini)
		return false;

	if (end - ini == 1)
	{
		if (v[ini] > v[end] || v[end] - v[ini] > 1)
			return false;
		else
			return true;
	}

	bool crecienteIzquierda, crecienteDerecha;

	int m = (ini + end) / 2;

	if ((v[m] > v[m + 1] || v[m + 1] - v[m] > 1))
		return false;

	crecienteIzquierda = alg(v, ini, m);

	if (!crecienteIzquierda) 
		return false;

	crecienteDerecha = alg(v, m + 1, end);

	if (!crecienteDerecha) 
		return false;

	return true;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	bool sol;
	int m, n;
	int j = 0;
	int* v = new int[1000000];

	cin >> m;
	while (j < m)
	{
		cin >> n;
		for (int k = 0; k < n; k++)
		{
			cin >> v[k];
		}
		sol = alg(v, 0, n - 1);
		if (sol)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		j++;
	}
}