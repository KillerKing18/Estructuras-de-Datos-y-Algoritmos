#include<iostream>
using namespace std;

int tamSegmentoMaximo(int v[], int n);
bool solveCase();

int tamSegmentoMaximo(int v[], int n)
{
	int result = 0;
	int longitud = 0;
	bool iguales = false;
	for (int j = 1; j < n; j++)
	{
		if (v[j] == v[j - 1])
		{
			if (iguales)
			{
				longitud++;
			}
			else
			{
				iguales = true;
				longitud = 1;
			}
			if (longitud > result)
				result = longitud;
		}
		else
			iguales = false;
	}
	return result;
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
	int v[100000];
	int i = 0;
	cin >> v[i];
	if (v[i] != -1)
	{
		while (v[i] != -1)
		{
			i++;
			cin >> v[i];
		}
		int result = tamSegmentoMaximo(v, i);
		if (result == 0)
			cout << "HOY NO COMEN" << endl;
		else
			cout << result << endl;
		return true;
	}
	return false;
}