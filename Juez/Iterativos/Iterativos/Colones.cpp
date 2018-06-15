#include<iostream>

using namespace std;

const int MAX = 100000;

void numCases(int n);
int output(int v[], int ladders);

int main()
{
	int cases = 0, people = 0;

	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		cin >> people;
		numCases(people);
	}

	return 0;
}

void numCases(int n)
{
	int v[MAX];

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int result = output(v, n);

	cout << result << endl;
}


// PRE: {1 < n <= 100000} 
int output(int v[], int n)
{
	int i = n - 1;
	int colones = 0;
	int referencia = v[n - 1];
	// INVARIANT: {colones = #w : i < w < n: Exists u: w < u < n : v[w] > v[u] ^ (-1 <= i < n) ^ (referencia = min z : i <= z < n : v[z])}
	while (i >= 0)
	{
		if (v[i] > referencia)
		{
			colones++;
		}
		else
		{
			referencia = v[i];
		}
		i--;
	}

	return colones;
}
// POST: {colones = #w : 0 <= w < n: Exists u: w < u < n : v[w] > v[u]}
// COMPLEXITY = O(n)