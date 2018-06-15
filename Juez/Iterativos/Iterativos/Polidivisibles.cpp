#include<iostream>
using namespace std;

void escribePolidivisibles(long long raiz, long long maxDigitos);
bool poliRec(long long n, long long digActual, long long digFinal, long long digInicial);
bool solveCase();


int main()
{
	while (solveCase())
	{

	}
	return 0;
}

void escribePolidivisibles(long long raiz, long long maxDigitos)
{
	long long digInicial = 1, raizAux = raiz;
	while ((raizAux / 10) > 0)
	{
		raizAux = raizAux / 10;
		digInicial++;
	}
	poliRec(raiz, digInicial, maxDigitos, digInicial);
}

bool poliRec(long long n, long long digActual, long long digFinal, long long digInicial)
{
	if (digActual == digInicial)
	{
		cout << n << endl;
		poliRec(n * 10, digActual + 1, digFinal, digInicial);
	}
	else
	{
		for (long long i = 0; i < 10; i++)
		{
			if (digActual > digFinal)
				return true;
			else
			{
				if ((n + i) % digActual == 0)
				{
					cout << n + i << endl;
					poliRec((n + i) * 10, digActual + 1, digFinal, digInicial);
				}
			}
		}
	}
	return true;
}

bool solveCase()
{
	long long n;
	long long m;

	if (cin >> n >> m)
	{
		escribePolidivisibles(n, m);
		cout << "---" << endl;
		return true;
	}
	else
		return false;
}