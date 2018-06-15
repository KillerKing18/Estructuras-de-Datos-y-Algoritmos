#include<iostream>
#include<string>
using namespace std;

void blancos(string v[], int n, int &beg, int &end);
bool solveCase();

void blancos(string v[], int n, int &beg, int &end)
{
	int begAux = -1;
	int endAux = -1;
	int veces = 0;
	int vecesAux = 0;
	bool ceros = false;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == "FFFFFF")
		{
			if (ceros)
			{
				vecesAux++;
				endAux = i;
			}
			else
			{
				ceros = true;
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
			ceros = false;
			vecesAux = 0;
		}
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
	string v[1000];
	int m, n, beg, end;
	if (cin >> m >> n)
	{	
		for (int i = 0; i < m; i++)
		{
			beg = 0;
			end = -1;
			for (int j = 0; j < n; j++)
				cin >> v[j];
			blancos(v, n, beg, end);
			cout << beg << " " << end << endl;
		}
		cout << endl;
		return true;
	}
	else
		return false;
}