#include<iostream>
using namespace std;

void reinas(int k, int n, int sol[], int &result);
void solveCase();
bool isValid(int sol[], int k);

void reinas(int k, int n, int sol[], int &result)
{
	for (int i = 0; i < n; i++)
	{
		sol[k] = i;
		if (isValid(sol, k)) 
			if (k == n - 1) 
				result++;
			else
				reinas(k + 1, n, sol, result);
	}
}

bool isValid(int sol[], int k)
{
	bool correcto = true;
	int i = 0;
	while (i < k && correcto) {
		if ((sol[i] == sol[k]) || (abs(sol[k] - sol[i]) == k - i))
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
	int m = 0, n = 0, result;

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> n;
		result = 0;
		int* sol = new int[n];
		reinas(0, n, sol, result);
		cout << result << endl;
	}
}