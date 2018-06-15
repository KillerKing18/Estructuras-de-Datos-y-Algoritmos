#include <iostream>
using namespace std;

bool solveCase();
int curva(int v[], int ini, int end);

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
		cout << curva(v, 0, n - 1) << endl;
		return true;
	}
	else
		return false;
}

int curva(int v[], int ini, int end)
{
	int middle = (ini + end) / 2;
	int result = v[middle];

	if (middle - 1 >= ini)
	{
		if (v[middle - 1] < result)
		{
			result = curva(v, ini, middle - 1);
		}
	}
	if (middle + 1 <= end)
	{
		if (v[middle + 1] < result)
		{
			result = curva(v, middle + 1, end);
		}
	}
	return result;
}