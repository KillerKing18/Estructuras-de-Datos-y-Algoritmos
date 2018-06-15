#include<iostream>
#include<string>
using namespace std;

int unique(int v[], int ini, int end);
void solveCase();

int unique(int v[], int ini, int end)
{
	if (end == 0) return 0;
	int middle = (ini + end) / 2;

	if (ini == end) return ini;
	if ((middle % 2) == 0)
	{
		if (v[middle] == v[middle + 1])
			return unique(v, middle + 2, end);
		else
			return unique(v, ini, middle);
	}
	else
	{
		if (v[middle] == v[middle - 1])
			return unique(v, middle + 1, end);
		else
			return unique(v, ini, middle - 1);
	}
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int* v = new int[1100000];
	int m, n;
	int beg, end;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cout << unique(v, 0, n - 1) << endl;
	}
}