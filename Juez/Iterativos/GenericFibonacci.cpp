#include<iostream>
using namespace std;

int output(int v[], int n);
void solveCase();

int output(int v[], int n)
{
	int output = 0, outputAux = 2;
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (v[i] == v[i - 1] + v[i - 2])
				outputAux++;
			else
				outputAux = 2;
			if (outputAux > output)
				output = outputAux;
		}
	}
	return output;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m, n;
	int* v = new int[1000000];

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}
		cout << output(v, n) << endl;
	}
}