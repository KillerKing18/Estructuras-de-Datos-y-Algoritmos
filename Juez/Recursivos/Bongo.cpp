#include<iostream>
using namespace std;

int bongo(int v[], int ini, int end, int cantado);
void solveCase();

int bongo(int v[], int ini, int end, int cantado)
{
	int middle = (ini + end) / 2;
	int result = v[middle];

	if (ini > end)
		return -1;
	else if (v[middle] == middle + cantado)
		return v[middle];
	else if (v[middle] > middle + cantado)
		return bongo(v, ini, middle - 1, cantado);
	else
		return bongo(v, middle + 1, end, cantado);
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int* v = new int [1100000];
	int m, n, cantado, result = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n >> cantado;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		result = bongo(v, 0, n - 1, cantado);
		if (result != -1)
			cout << result;
		else
			cout << "NO";
		cout << endl;
	}
}