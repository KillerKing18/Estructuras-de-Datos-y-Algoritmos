#include<iostream>
#include<string>
using namespace std;

string bandera(string &palabra, int r, int w, int b);
void solveCase();

string bandera(string &palabra, int r, int w, int b)
{
	if (w == b)
		return palabra;
	else
	{
		if (palabra[w] == 'w')
		{
			w++;
		}
		else if (palabra[w] == 'r')
		{
			palabra[w] = palabra[r];
			palabra[r] = 'r';
			w++;
			r++;
		}
		else
		{
			palabra[w] = palabra[b - 1];
			palabra[b - 1] = 'b';
			b--;
		}
		bandera(palabra, r, w, b);
	}
	return palabra;
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m, n;
	string palabra;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		if (n != 0)
		{
			cin >> palabra;
			int r = 0, w = 0, b = n;
			cout << bandera(palabra, r, w, b);
		}
		cout << endl;
	}
}