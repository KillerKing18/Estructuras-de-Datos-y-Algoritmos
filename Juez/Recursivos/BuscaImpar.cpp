#include<iostream>

using namespace std;

bool solveCase();
int buscaImpar(int v[], int ini, int end);

int main() {

	while (solveCase())
	{

	}

	return 0;
}

bool solveCase()
{
	int n;
	if (cin >> n)
	{
		int* v = new int[n];
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << buscaImpar(v, 0, n - 1) << endl;
		return true;
	}
	else
		return false;
}

int buscaImpar(int v[], int ini, int end)
{
	if (end - ini == 0)
		return v[ini];
	else
	{
		int middle = (ini + end) / 2;

		if (v[middle] % 2 != 0)
			return v[middle];

		if (v[middle] == v[ini] + 2 * (middle - ini))
			return buscaImpar(v, middle + 1, end);
		else
			return buscaImpar(v, ini, middle);
	}
}