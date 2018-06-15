#include <iostream>
using namespace std;

bool solveCase();
int minimo(int v[], int ini, int end);

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

	if (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << minimo(v, 0, n - 1) << endl;
		return true;
	}
	else
		return false;
}

int minimo(int v[], int ini, int end)
{
	int middle = (ini + end) / 2;
	int result = v[middle];

	if (v[ini] >= v[end])
		return v[end];

	if (end - ini == 1)
		if (v[ini] < v[end])
			return v[ini];
		else
			return v[end];

	if (result < v[ini])
		result = minimo(v, middle, end);
	else
		result = minimo(v, ini, middle - 1);

	return result;
}