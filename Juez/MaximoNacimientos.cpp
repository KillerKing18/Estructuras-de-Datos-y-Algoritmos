#include<iostream>

using namespace std;

const int MAXLENGTH = 200000;

int maximoNacimientos(int v[], int nacimientos, int periodo);

void solveCase(int nacimientos, int periodo);

int main()
{
	int nacimientos = 0, periodo = 0;

	cin >> nacimientos;
	cin >> periodo;
	while ((nacimientos != 0) && (periodo != 0))
	{
		solveCase(nacimientos, periodo);
		cin >> nacimientos;
		cin >> periodo;
	}
	return 0;
}

int maximoNacimientos(int v[], int nacimientos, int periodo)
{
	int maximo = 0, actual = 0;

	int k = 1; int r = 1; int s = 0;
	while (k < nacimientos) {
		if (v[k] - v[s] < periodo)
		{
			actual = k - s + 1;
			if (actual > r)
			{
				r = actual;
			}
		}
		else
			while (v[k] - v[s] >= periodo) ++s;
		++k;
	}
	return r;
}

void solveCase(int nacimientos, int periodo)
{	
	int v[MAXLENGTH];

	for (int i = 0; i < nacimientos; i++)
	{
		cin >> v[i];
	}

	int maximo = maximoNacimientos(v, nacimientos, periodo);
	cout << maximo << endl;
}