#include <iostream>
using namespace std;

bool solveCase();
int output(int v[100][100], int m, int n);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int m = 0, n = 0;
	int v[100][100];
	if (cin >> m >> n)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		cout << output(v, m, n) << endl;
		return true;
	}
	else
	{
		return false;
	}
}

int output(int v[100][100], int m, int n)
{
	int maxAux = 0, max = 0;
	for (int i = 0; i + n <= m; i++)
		for (int j = 0; j + n <= m; j++)
		{
			maxAux = 0;
			for (int k = i; k - i < n; k++)
				for (int l = j; l - j < n; l++)
				{
					maxAux += v[k][l];
				}
			if (maxAux > max)
				max = maxAux;
		}
	return max;
}