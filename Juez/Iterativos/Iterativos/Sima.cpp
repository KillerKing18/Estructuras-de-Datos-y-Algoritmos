#include <iostream>
using namespace std;

bool solveCase();
bool output(int v[], int n);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int n = -1;
	int* v = new int[1000000];
	if (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		cout << output(v, n) << endl;
		return true;
	}
	else
	{
		return false;
	}
}

// P: 
bool output(int v[], int n)
{
	bool result = true;
	bool mayor = false;
	int i = 1;
	bool mal = false;

	for (; (i < n) && !mayor; i++)
	{
		if (v[i - 1] < v[i])
			mayor = true;
	}
	for (; (i < n) && !mal; i++)
	{
		if (v[i - 1] > v[i])
		{
			result = false;
			mal = true;
		}
	}
	return result;
}
// Q : 
// Complexity : O(n)