#include<iostream>
using namespace std;

bool faded(int v[], int ini, int end, int& sum);
bool solveCase();

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool faded(int v[], int ini, int end, int& sum)
{
	int sumLeft, sumRight;
	bool fadedLeft, fadedRight;
	int middle = (ini + end) / 2;
	if (end - ini == 0)
	{
		sum = v[ini];
		return true;
	}
	else
	{
		fadedLeft = faded(v, ini, middle, sum);
		sumLeft = sum;
		fadedRight = faded(v, middle + 1, end, sum);
		sumRight = sum;
	}
	if ((sumLeft < sumRight) && fadedLeft && fadedRight)
	{
		sum = sumLeft + sumRight;
		return true;
	}
	else
		return false;
}

bool solveCase()
{
	bool sol = true;
	int m, n;
	int sum = 0;
	int* v = new int[1100000];



	if (cin >> m >> n)
	{
		for (int j = 0; j < m; j++)
			{
				for (int i = 0; i < n; i++)
				{
					cin >> v[i];
				}
				if (sol) sol = faded(v, 0, n - 1, sum);
			}
		if (sol)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		return true;
	}
	else
		return false;
}