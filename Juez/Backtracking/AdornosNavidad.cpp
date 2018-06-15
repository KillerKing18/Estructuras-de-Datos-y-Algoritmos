#include<iostream>

using namespace std;

bool solveCase();
void adornos(int k, int n, int &presupuesto, int &super, int &max_super, int costes[], int superficie[], int mejor_caso[]);

int main() {

	while (solveCase())
	{
	}

	return 0;
}

bool solveCase()
{
	int objetos, presupuesto;

	if (cin >> objetos >> presupuesto)
	{
		int* costes = new int[objetos];
		int* superficie = new int[objetos];
		int* mejor_caso = new int[objetos];

		for (int i = 0; i < objetos; i++)
			cin >> costes[i];

		for (int i = 0; i < objetos; i++)
			cin >> superficie[i];

		mejor_caso[objetos - 1] = superficie[objetos - 1];
		for (int i = objetos - 2; i >= 0; i--)
			mejor_caso[i] = superficie[i] + mejor_caso[i + 1];

		int super = 0, max_super = 0;

		adornos(0, objetos, presupuesto, super, max_super, costes, superficie, mejor_caso);
		cout << max_super << endl;
		return true;
	}
	else
		return false;
}

void adornos(int k, int n, int &presupuesto, int &super, int &max_super, int costes[], int superficie[], int mejor_caso[])
{
	for (int i = 0; i < 2; i++)
	{
		if ((i == 0) || ((i == 1) && (presupuesto - costes[k] >= 0)))
		{
			if (i == 1) {
				super = super + superficie[k];
				presupuesto = presupuesto - costes[k];
			}
			if (k == n - 1) 
			{
				if (super > max_super)
					max_super = super;
			}
			else
			{
				if (super + mejor_caso[k + 1] > max_super)
					adornos(k + 1, n, presupuesto, super, max_super, costes, superficie, mejor_caso);
			}
			if (i == 1) {
				super = super - superficie[k];
				presupuesto = presupuesto + costes[k];
			}
		}
	}
}