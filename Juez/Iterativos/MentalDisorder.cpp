#include<iostream>

using namespace std;

const int MAXLENGTH = 10000;

int countStacks(int v[], int length)
{
	int result = 0;

	for (int i = 0; i < length; i++)
		if (v[i] % 2 == 0)
			result++;

	return result;
}

void solveCase()
{
	int length = 0, v[MAXLENGTH];

	cin >> length;

	for (int i = 0; i < length; ++i) cin >> v[i];

	int result = countStacks(v, length);

	cout << result << endl;
}

int main()
{
	int numCases;

	cin >> numCases;

	for (int i = 0; i < numCases; ++i)
		solveCase();

	return 0;
}