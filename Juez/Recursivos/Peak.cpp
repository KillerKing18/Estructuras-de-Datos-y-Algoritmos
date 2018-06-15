#include <iostream>
using namespace std;

void peak(int n);
int output(int v[], int a, int b);

int main()
{
	int num = -1;
	cin >> num;
	
	while (num != 0)
	{
		peak(num);
		cin >> num;
	}
	return 0;
}

void peak(int n)
{
	int *v = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << output(v, 0, n - 1) << endl;
}

// P: {(For All u : a <= u < p : v[u] < v[u + 1]) ^ (For All w : p < w < n : v[w - 1] > v[w])}
int output(int v[], int a, int b)
{
	int middle = (a + b) / 2;
	int result = middle;

	if (middle - 1 >= a)
	{
		if (v[middle - 1] > v[middle])
		{
			result = output(v, a, middle - 1);
		}
	}
	if (middle + 1 <= b)
	{
		if (v[middle + 1] > v[middle])
		{
			result = output(v, middle + 1, b);
		}
	}
	return result;
}
// Q : {result = w : a <= w < b : max w : a <= w <= b : v[w]}
// Complexity : O(log n)