#include<iostream>
using namespace std;

char fugado(char v[], char ini, char end, int first, int last);
void solveCase();

char fugado(char v[], char ini, char end, int first, int last)
{
	int middle = (first + last) / 2;
	int result = v[middle];
	char letra;
	char middleChar = v[middle];
	char iniChar = v[first];

	if (first == last)
	{
		if (iniChar == ini + middle)
			return toascii(iniChar + 1);
		else
			return toascii(iniChar - 1);
	}		

	if (middleChar == ini + middle)
		return fugado(v, ini, end, middle + 1, last);
	else 
		return fugado(v, ini, end, first, middle);
}

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	char* v = new char[1100000];
	int m;
	char ini, end;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ini >> end;
		for (int j = 0; j < end - ini; j++)
			cin >> v[j];
		cout << fugado(v, ini, end, ini - ini, end - ini - 1) << endl;
	}
}