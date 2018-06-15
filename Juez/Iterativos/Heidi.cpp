#include <iostream>
using namespace std;

bool solveCase();
void output(int v[], int m, int n, int &longitud, int &veces);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int m = 0, n = 0, longitud = 0, veces = 0;
	int* v = new int[1000000];
	if (cin >> m >> n)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> v[i];
		}
		output(v, m, n, longitud, veces);
		cout << longitud << " " << veces;
		if (veces != 0)
			for (int i = 0; i < veces; i++)
				cout << " " << v[i];
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void output(int v[], int m, int n, int &longitud, int &veces)
{
	int highest = -1, llanos = 0, j = 0, primero = 0;
	int* w = new int[m];
	for (int i = m - 1; i >= 0; i--)
	{
		if (v[i] > highest)
		{
			highest = v[i];
			llanos = 1;
			primero = i;
		}
		else if (v[i] == highest)
		{
			llanos++;
		}
		else
			llanos = 0;
		if (llanos == n)
		{
			veces++;
			w[j] = primero;
			j++;
		}
		if (llanos > longitud && llanos >= n)
			longitud = llanos;
	}
	for (int i = 0; i < veces; i++)
	{
		v[i] = w[i];
	}
}