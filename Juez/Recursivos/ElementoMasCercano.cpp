#include<iostream>

using namespace std;

void solveCase();
int cercano(int v[], int ini, int end, int x);

int main() {

	solveCase();

	return 0;
}

void solveCase()
{
	int m, n, x;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cin >> n;
		int* v = new int[n];
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cout << cercano(v, 0, n - 1, x) << endl;
	}
}

int cercano(int v[], int ini, int end, int x)
{
	if (end - ini == 0)
		return v[ini];
	else
	{
		int middle = (ini + end) / 2;

		if (v[middle] == x)
			return v[middle];

		if (abs(x - v[middle + 1]) < abs(x - v[middle]))
			return cercano(v, middle + 1, end, x);
		else
			return cercano(v, ini, middle, x);
	}
}