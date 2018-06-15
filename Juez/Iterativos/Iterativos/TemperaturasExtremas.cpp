#include<iostream>

using namespace std;

const int MAXLENGTH = 10000;

// PRE: (0 < length <= MAXLENGTH) AND (length(v) >= length) AND (ForAll w : 0 <= w < length : -50 <= v[w] <= 60)

int picos(int v[], int length)
{
	int result = 0;

	// I: #i: 1 <= w < i: (v[w - 1] < v[w] > v[w + 1]) ^ (0 < i < length) es length y no (length - 1) porque en la última iteración del bucle i = length - 1
	for (int i = 1; i < length - 1; i++)
	{
		if ((v[i - 1] < v[i]) && (v[i + 1] < v[i]))
		{
			result++;
		}
	}
	// COTA: length - i

	return result;
}

// POST: #i: 1 <= i < length - 1: (v[i - 1] < v[i] > v[i + 1])

// PRE: (0 < length <= MAXLENGTH) AND (length(v) >= length) AND (ForAll w : 0 <= w < length : -50 <= v[w] <= 60)

int valles(int v[], int length)
{
	int result = 0;
	
	// I: #i: 1 <= w < i: (v[w - 1] > v[w] < v[w + 1]) ^ (0 < i < length) es length y no (length - 1) porque en la última iteración del bucle i = length - 1
	for (int i = 1; i < length - 1; i++)
	{
		if ((v[i - 1] > v[i]) && (v[i + 1] > v[i]))
		{
			result++;
		}
	}
	// COTA: length - i

	return result;
}

// POST: #i: 1 <= i < length - 1: (v[i - 1] > v[i] < v[i + 1])

void solveCase()
{
	int length = 0, v[MAXLENGTH];

	cin >> length;

	for (int i = 0; i < length; ++i) cin >> v[i];

	int numPicos = picos(v, length);

	int numValles = valles(v, length);

	cout << numPicos << " " << numValles << endl;
}

int main()
{
	int numCases;

	cin >> numCases;

	for (int i = 0; i < numCases; ++i)
	{
		solveCase();
	}

	return 0;
}