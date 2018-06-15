#include<iostream>
#include<string>
using namespace std;

void rescate(int v[], int n, int t, int &beg, int &end);
void solveCase();

void rescate(int v[], int n, int t, int &beg, int &end)
{
	int begAux = -1;
	int endAux = -1;
	int veces = 0;
	int vecesAux = 0;
	bool mayor = false;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > t)
		{
			if (mayor)
			{
				vecesAux++;
				endAux = i;
			}
			else
			{
				mayor = true;
				begAux = i;
				endAux = i;
				vecesAux = 1;
			}
			if (vecesAux > veces)
			{
				veces = vecesAux;
				beg = begAux;
				end = endAux;
			}
		}
		else
		{
			mayor = false;
			vecesAux = 0;
		}
	}
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int* v = new int[1000000];
	int m, n, t;
	int beg, end;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n >> t;
		beg = -1;
		end = -1;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		rescate(v, n, t, beg, end);
		cout << beg << " " << end << endl;
	}
}