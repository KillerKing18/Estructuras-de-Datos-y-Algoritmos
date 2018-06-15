#include<iostream>
using namespace std;

void solveCase();
void mergeSort(int v[], int ini, int end, long long int &result);
void merge(int v[], int ini, int middle, int end, long long int &result);

void merge(int v[], int ini, int middle, int end, long long int &result)
{
	int i, j, k;
	int n1 = middle - ini + 1;
	int n2 = end - middle;

	int* izq = new int[n1];
	int* der = new int[n2];

	for (i = 0; i < n1; i++)
		izq[i] = v[ini + i];
	for (j = 0; j < n2; j++)
		der[j] = v[middle + 1 + j];

	i = 0; 
	j = 0; 
	k = ini;
	while (i < n1 && j < n2)
	{
		if (izq[i] <= der[j])
		{
			v[k] = izq[i];
			i++;
		}
		else
		{
			v[k] = der[j];
			j++;
			result += n1 - i;
		}
		k++;
	}

	while (i < n1)
	{
		v[k] = izq[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		v[k] = der[j];
		j++;
		k++;
	}
}

void mergeSort(int v[], int ini, int end, long long int &result)
{
	if (ini < end)
	{
		int middle = ini + (end - ini) / 2;

		mergeSort(v, ini, middle, result);
		mergeSort(v, middle + 1, end, result);

		merge(v, ini, middle, end, result);
	}
}


int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int* v = new int[1100000];
	int m, n;
	long long int result;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		result = 0;
		if (n > 0) mergeSort(v, 0, n - 1, result);
		cout << result << endl;
	}
}