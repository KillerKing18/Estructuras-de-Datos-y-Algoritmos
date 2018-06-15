#include<iostream>

using namespace std;

void numChapters(int n);
bool output(long long int v[], int members);

int main()
{
	int chapters = -1;

	cin >> chapters;

	while (chapters != 0)
	{
		numChapters(chapters);
		cin >> chapters;
	}

	return 0;
}

void numChapters(int n)
{
	long long int *v = new long long int[n];
	bool result = false;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	result = output(v, n);

	if (result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

bool output(long long int v[], int members)
{
	int FibMinusTwo = 0, FibMinusOne = 1, fib;

	if (v[0] < 0)
		return false;

	if ((v[1] < 1) && (members > 1))
		return false;

	for (int i = 2; i < members; i++)
	{
		fib = FibMinusOne + FibMinusTwo;

		if (v[i] < fib)
			return false;

		FibMinusTwo = FibMinusOne;
		FibMinusOne = fib;
	}

	return true;
}