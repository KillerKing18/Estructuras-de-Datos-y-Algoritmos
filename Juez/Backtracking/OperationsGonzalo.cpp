#include<iostream>

using namespace std;

bool solveCase();
bool output(int k, int n, int res, int v[], int operation);

int main()
{
	while (solveCase());
	return 0;
}

bool solveCase()
{
	int res;
	if (cin >> res) {
		int v[5];
		for (int i = 0; i < 5; i++)
			cin >> v[i];
		int operation = v[0];
		if (output(1, 5, res, v, operation))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return true;
	}
	else
		return false;
}

bool output(int k, int n, int res, int v[], int operation) {
	if (k == n)
		return operation == res;

	if (!output(k + 1, n, res, v, operation + v[k]))
		if (!output(k + 1, n, res, v, operation - v[k]))
			if (!output(k + 1, n, res, v, operation * v[k]))
				if ((!output(k + 1, n, res, v, operation / v[k])) || (v[k] == 0) || (operation % v[k] != 0))
					return false;
	return true;
}