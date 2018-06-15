#include<iostream>
using namespace std;

bool adecuado(int v[], int ini, int end, int &mayor, int &menor, int &total);
bool solveCase();

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool adecuado(int v[], int ini, int end, int &mayor, int &menor, int &total)
{
	int maxLeft, maxRight, minLeft, minRight, totalLeft, totalRight;
	int media;
	bool adecuadoLeft, adecuadoRight;
	int middle = (ini + end) / 2;
	if (end - ini == 0)
	{
		mayor = v[ini];
		menor = v[ini];
		total = v[ini];
		return true;
	}
	else
	{
		adecuadoLeft = adecuado(v, ini, middle, maxLeft, minLeft, totalLeft);
		adecuadoRight = adecuado(v, middle + 1, end, maxRight, minRight, totalRight);
		if (maxLeft > maxRight)
			mayor = maxLeft;
		else
			mayor = maxRight;
		if (minLeft < minRight)
			menor = minLeft;
		else
			menor = minRight;
	}
	total = totalLeft + totalRight;
	media = total / (end - ini + 1);
	if ((mayor <= media + (media / 2)) && 
		(menor >= media - (media / 2)) && 
		adecuadoLeft && adecuadoRight)
		return true;
	else
		return false;
}

bool solveCase()
{
	bool sol = true;
	int n;
	int* v = new int[1100000];

	if (cin >> n)
	{
		int mayor, menor, total;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		
		sol = adecuado(v, 0, n - 1, mayor, menor, total);

		if (sol)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
		return true;
	}
	else
		return false;
}