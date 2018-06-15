#include<iostream>
using namespace std;

void maximos(int n, int &num, int &max);
void solveCase();

void maximos(int n, int &num, int &max)
{
	int actual;
	cin >> max;
	num = 1;
	for (int i = 1; i < n; i++)
	{
		cin >> actual;
		if (actual == max)
			num++;
		else if (actual > max)
		{
			max = actual;
			num = 1;
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
	int m, n;
	int num, max;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		maximos(n, num, max);
		cout << max << " " << num << endl;
	}
}