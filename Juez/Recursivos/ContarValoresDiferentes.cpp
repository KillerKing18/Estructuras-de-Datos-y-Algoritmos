#include<iostream>
using namespace std;

int diferentes(int v[], int ini, int end, int &anterior);
bool solveCase();

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

int diferentes(int v[], int ini, int end, int &anterior)
{
	int diferentesLeft = 0, diferentesRight = 0;
	int middle = (ini + end) / 2;
	
	if (anterior == v[end])
		return 0;

	if (end - ini == 0)
	{
		if (v[ini] == anterior)
			return 0;
		else 
		{
			anterior = v[ini];
			return 1;
		}
	}
	else
	{
		diferentesLeft = diferentes(v, ini, middle, anterior);
		diferentesRight = diferentes(v, middle + 1, end, anterior);
		return diferentesLeft + diferentesRight;
	}
}

bool solveCase()
{
	int n, primerValor, ultimoValor, anterior;
	int* v = new int[1100000];

	if (cin >> n)
	{
		cin >> v[0];
		primerValor = v[0];
		primerValor--;
		for (int i = 1; i < n - 1; i++)
			cin >> v[i];
		if (n > 1) {
			cin >> v[n - 1];
			ultimoValor = v[n - 1];
		}
		else
			ultimoValor = primerValor;
		anterior = primerValor + ultimoValor + 3;
		cout << diferentes(v, 0, n - 1, anterior) << endl;
		return true;
	}
	else
		return false;
}