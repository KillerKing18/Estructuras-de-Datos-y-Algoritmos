#include<iostream>
using namespace std;

void reinas(int k, int n, int sol[], int &result, int m[][9], int fichas[]);
void solveCase();
bool isValidQueen(int sol[], int k, int m[][9]);

void reinas(int k, int n, int sol[], int &result, int m[][9], int fichas[])
{
	for (int i = 0; i < n; i++)
	{
		sol[k] = i;
		m[k][i] = 1;
		if ((isValidQueen(sol, k, m)) && (fichas[0] > 0)) 
		{
			fichas[0]--;
			if (k == n - 1)
				result++;
			else
				reinas(k + 1, n, sol, result, m, fichas);
			fichas[0]++;
		}

		m[k][i] = 2;
		if ((isValidQueen(sol, k, m)) && (fichas[1] > 0))
		{
			fichas[1]--;
			if (k == n - 1)
				result++;
			else
				reinas(k + 1, n, sol, result, m, fichas);
			fichas[1]++;
		}
	}
}

bool isValidQueen(int sol[], int k, int m[][9])
{
	bool correcto = true;
	int i = 0;
	while (i < k && correcto) {
		if ((sol[i] == sol[k]) || ((abs(sol[k] - sol[i]) == k - i) && ((m[k][sol[k]] == 1) || (m[i][sol[i]] == 1))))
			correcto = false;
		i++;
	}

	return correcto;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int t, r, n, result;
	int fichas[2];
	int m[9][9];

	cin >> t >> r;
	while ((t != 0) || (r != 0))
	{
		n = t + r;
		fichas[0] = r;
		fichas[1] = t;
		result = 0;
		int* sol = new int[n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = 0;
		reinas(0, n, sol, result, m, fichas);
		cout << result << endl;
		cin >> t >> r;
	}
}