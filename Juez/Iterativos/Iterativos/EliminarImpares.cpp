#include<iostream>
using namespace std;

int eliminarImpares(int v[], int &n);
bool solveCase();

int eliminarImpares(int v[], int &n)
{
	int finaln = n;
	int actual = 0;
	for (int i = 0; i < n; i++)
		if (v[i] % 2 == 0)
		{
			v[actual] = v[i];
			actual++;
		}
		else
			finaln--;
	return finaln;
}

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int* v = new int[1000000];
	int n, pares;
	cin >> n;

	if (n != -1)
	{
		for (int i = 0; i < n; i++)
			cin >> v[i];
		pares = eliminarImpares(v, n);
		for (int j = 0; j < pares - 1; j++)
		{
			cout << v[j] << " ";
		}
		if (pares > 0)
			cout << v[pares - 1];
		cout << endl;
		return true;
	}
	else
		return false;
}