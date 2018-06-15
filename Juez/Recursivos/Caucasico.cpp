#include<iostream>
using namespace std;

bool isPaired(int v[], int ini, int end, int &even);
bool solveCase();

bool isPaired(int v[], int ini, int end, int &even)
{
	if (end - ini == 0)
	{
		if (v[ini] % 2 == 0)
			even = 1;
		else
			even = 0;

		return true;
	}

	int middle = (ini + end) / 2;

	bool caucasicoLeft = isPaired(v, ini, middle, even);

	int left = even;

	bool caucasicoRight = isPaired(v, middle + 1, end, even);

	int right = even;

	if ((abs(left - right) <= 2) && caucasicoLeft && caucasicoRight)
	{
		even = left + right;
		return true;
	}
	else
		return false;
}

bool solveCase()
{
	int n;
	int even = 0, total = 0;

	cin >> n;

	int* v = new int[n];

	if (n == 0)
		return false;

	if (n == 1)
		cout << "YES" << endl;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	bool caucasico = isPaired(v, 0, n - 1, even);

	if (caucasico)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return true;
}

int main()
{
	while (solveCase())
	{

	}

	return 0;
}