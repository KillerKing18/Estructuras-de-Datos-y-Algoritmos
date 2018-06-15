#include<iostream>
#include<string>

using namespace std;

const int MAXLENGTH = 100000;

// PRE: 0 <= length <= MAXLENGTH AND length(v) >= length

bool solution(int v[], int length)
{
	bool result = true;
	bool orden = true;
	int i = 1;
	// INVARIANT: i >= 1
	while ((i < length - 1) && orden && (i > 0))
	{
		if (((v[i - 1] <= v[i]) && (v[i] >= v[i + 1])) || ((v[i - 1] >= v[i]) && (v[i] <= v[i + 1])))
		{
			orden = false;
		}
		i++;
	}

	result = orden;

	return result;
}

// POST: For all i: 1 <= i < length - 1: (((v[i - 1] <= v[i]) && (v[i] >= v[i + 1])) || ((v[i - 1] >= v[i]) && (v[i] <= v[i + 1])))

void solveCase(int length)
{
	int v[MAXLENGTH];
	bool result;
	string finalSolution = "DESCONOCIDOS";

	for (int i = 0; i < length; i++) cin >> v[i];

	result = solution(v, length);

	if (result)
	{
		finalSolution = "DALTON";
	}

	cout << finalSolution << endl;
}

int main()
{
	int length = 0;
	cin >> length;
	while (length != 0)
	{
		solveCase(length);
		cin >> length;
	}

	return 0;
}