#include<iostream>
#include<string>
using namespace std;

int unique(int v[], int n);
void solveCase();

int unique(int v[], int n)
{
	if (n == 1) return 0;
	int beg = 0;
	int middle = (beg + n) / 2;
	while (true)
	{
		if (beg == middle) return beg;
		if ((middle % 2) == 0)
		{
			if (v[middle] == v[middle + 1])
			{
				beg = middle + 2;
				middle = (beg + n) / 2;
			}
			else
			{
				n = middle;
				middle = (beg + n) / 2;
			}
		}
		else
		{
			if (v[middle] == v[middle - 1])
			{
				beg = middle + 1;
				middle = (beg + n) / 2;
			}
			else
			{
				n = middle - 1;
				middle = (beg + n) / 2;
			}
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
	int m, n;
	int beg, end;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cout << unique(v, n) << endl;
	}
}