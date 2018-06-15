#include<iostream>

using namespace std;

void numCases(int n);
int output(int v[], int ladders);

int main()
{
	int levels = 0, ladders = 0;

	cin >> levels;

	for (int i = 0; i < levels; i++)
	{
		cin >> ladders;
		numCases(ladders);
	}

	return 0;
}

void numCases(int n)
{
	int *v = new int[n];

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int result = output(v, n);

	cout << result << endl;
}

int output(int v[], int ladders)
{
	int result = 0, sum = 0;

	for (int i = ladders - 1; i >= 0; i--)
	{
		if (v[i] == sum)
			result++;

		sum += v[i];
	}

	return result;
}