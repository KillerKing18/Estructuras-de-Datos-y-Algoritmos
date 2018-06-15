#include<iostream>
using namespace std;

bool estaBalanceado(int &peso);
void solveCase();

int main()
{
	solveCase();
	return 0;
}

bool estaBalanceado(int &peso)
{
	bool balanceadoIzquierda = true, balanceadoDerecha = true;
	int distanciaIzquierda, distanciaDerecha;
	int pesoIzquierda, pesoDerecha;

	cin >> pesoIzquierda >> distanciaIzquierda;
	cin >> pesoDerecha >> distanciaDerecha;
	
	if (pesoIzquierda == 0)
		balanceadoIzquierda = estaBalanceado(pesoIzquierda);
	
	if(pesoDerecha == 0)
		balanceadoDerecha = estaBalanceado(pesoDerecha);

	peso = pesoIzquierda + pesoDerecha;

	if (((distanciaIzquierda * pesoIzquierda) == (distanciaDerecha * pesoDerecha))
		&& balanceadoIzquierda && balanceadoDerecha)
		return true;
	else
		return false;
}

void solveCase()
{
	bool sol;
	int n, peso = 0;
	
	cin >> n;

	for (int j = 0; j < n; j++)
	{
		sol = estaBalanceado(peso);
		if (sol)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
}