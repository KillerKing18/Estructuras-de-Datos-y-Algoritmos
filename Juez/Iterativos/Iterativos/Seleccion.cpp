#include <iostream>
using namespace std;

bool solveCase();
void output(int v[], int n, int &racha, int &veces, int &tiempo);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int n = -1, racha = 0, veces = 0, tiempo = 0;
	int* v = new int[1000000];
	if (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		output(v, n, racha, veces, tiempo);
		cout << racha << " " << veces << " " << tiempo << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void output(int v[], int n, int &racha, int &veces, int &tiempo)
{
	int rachaAux = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > 0)
		{
			rachaAux++;
			if (rachaAux > racha)
			{
				racha = rachaAux;
				veces = 1;
				tiempo = i + 1;
			}
			else if (rachaAux == racha)
			{
				veces++;
				tiempo = i + 1;
			}
		}
		else
		{
			rachaAux = 0;
		}
	}
	if (tiempo != 0)
		tiempo = n - tiempo;
	else
		tiempo = n;
}