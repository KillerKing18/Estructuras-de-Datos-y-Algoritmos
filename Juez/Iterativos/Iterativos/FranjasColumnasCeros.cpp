#include<iostream>
using namespace std;

const int MAX = 100;

int algoritmo(int v[MAX][MAX], int n, int m, int k, int y, int x);
bool solveCase();

int algoritmo(int v[MAX][MAX], int n, int m, int k, int y, int x)
{
	int numCeros = 0;
	int result = 0;
	bool primeraCumple = false;
	int numColumnasValidas = 0;
	bool* w = new bool[m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[j][i] == 0)
				numCeros++;
		}
		if (numCeros >= x)
		{
			numColumnasValidas++;
			w[i] = true;
		}
		else
			w[i] = false;
		if ((numColumnasValidas >= y) && (i >= k - 1))
			result++;
		if (i >= k - 1 && w[i - (k - 1)])
			numColumnasValidas--;
		numCeros = 0;
	}

	return result;
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
	int pos;
	int v[MAX][MAX];
	int n, m, k, y, x;
	if (cin >> n >> m >> k >> y >> x)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				cin >> v[j][i];
			}
		}
		cout << algoritmo(v, n, m, k, y, x) << endl;
		return true;
	}
	else
		return false;
}