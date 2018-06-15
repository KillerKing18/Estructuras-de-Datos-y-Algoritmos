#include<iostream>
using namespace std;

bool alg(int v[], int d, int n);
void solveCase();

// P: {n >= 0 && d > 0}
bool alg(int v[], int d, int n)
{
	bool valido = true;
	int vecesRepetido = 1;
	int i = 1;
	// I: {(0 <= i < n) && valido}
	// valido = ((For All w : 1 <= w < i : ((v[w] = v[w - 1]) || (v[w] = v[w-1] + 1))) && (vecesRepetido = #j : 0 < j < i : v[j] = v[j - 1]))}
	// Cota = n - i
	while (i < n && valido)
	{
		if (v[i - 1] == v[i])
			vecesRepetido++;
		else
			vecesRepetido = 1;

		if ((vecesRepetido > d) || ((v[i] != v[i - 1] + 1) && (v[i] != v[i - 1])))
			valido = false;
		i++;
	}
	return valido;
}
// Q: {valido = ((For All w : 1 <= w < n : ((v[w] = v[w - 1]) || (v[w] = v[w-1] + 1))) && ((#j : 0 < j < n : v[j] = v[j - 1]) <= d))}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	bool sol;
	int m, d, n;
	int j = 0;
	int* v = new int[1000000];

	cin >> m;
	while (j < m)
	{
		cin >> d >> n;
		for (int k = 0; k < n; k++)
		{
			cin >> v[k];
		}
		sol = alg(v, d, n);
		if (sol)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		j++;
	}
}