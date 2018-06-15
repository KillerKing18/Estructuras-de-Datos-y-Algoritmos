#include<iostream>
using namespace std;

void acumulados(int v[], int total, int n);
bool solveCase();

void acumulados(int v[], int total, int n)
{
	int aux = 0;
	for (int i = 0; i < n; i++)
	{
		aux = v[i];
		v[i] = total;
		total -= aux;
	}
}

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int* v = new int[1000000];
	int i = 0, n = 0;
	int total = 0;
	cin >> v[i];
	while (v[i] != 0)
	{
		n++;
		total += v[i];
		i++;
		cin >> v[i];
	}
	if (n > 0)
	{
		acumulados(v, total, n);
		int j = 0;
		while (j < n - 1)
		{
			cout << v[j] << " ";
			j++;
		}
		cout << v[j] << endl;
	}
	else
		return false;
	return true;
}