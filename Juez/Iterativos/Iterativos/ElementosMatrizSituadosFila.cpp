#include <iostream>
#include <vector>
using namespace std;

bool solveCase();
int output(vector<vector<int>> m, int filas, int columnas);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	int filas = 0, columnas = 0;
	if (cin >> filas >> columnas)
	{
		vector<vector<int>> m(filas, vector<int>(columnas));
		for (int i = 0; i < filas; i++)
			for (int j = 0; j < columnas; j++)
				cin >> m[i][j];
		cout << output(m, filas, columnas) << endl;	
		return true;
	}
	else
	{
		return false;
	}
}

int output(vector<vector<int>> m, int filas, int columnas)
{
	int counter = 0;
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			if (m[i][j] == i)
				counter++;
	return counter;
}