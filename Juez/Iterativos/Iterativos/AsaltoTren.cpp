#include<iostream>
using namespace std;

int asalto(int v[], int n, int vagones, int &ganancia);
void solveCase();

int asalto(int v[], int n, int vagones, int &ganancia)
{
	ganancia = 0;
	int vagon = -1, vagonAux = 0;
	int gananciaAux = 0;
	for (int i = 0; i < n; i++)
	{
		if (i - vagonAux < vagones)
		{
			gananciaAux += v[i];
		}
		else
		{
			gananciaAux = gananciaAux - v[i - vagones] + v[i];
			vagonAux++;
		}
		if (gananciaAux >= ganancia)
		{
			ganancia = gananciaAux;
			vagon = vagonAux;
		}
	}
	return vagon;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int* v = new int[1000000];
	int m, n, vagones, ganancia = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n >> vagones;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cout << asalto(v, n, vagones, ganancia) << " ";
		cout << ganancia << endl;
	}
}