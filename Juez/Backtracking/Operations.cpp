#include<iostream>

using namespace std;

bool solveCase();
bool output(int k, int n, int res, int v[], int& operation);

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

bool output(int k, int n, int res, int v[], int& operation) {
	bool division = false, multiplicacion_cero = false;
	int anterior_mult;
	for (int j = 0; j < 4; j++)
	{
		// Operar
		if (j == 0)
			operation = operation + v[k];
		else if (j == 1)
			operation = operation - v[k];
		else if (j == 2) {
			if (v[k] == 0) 
			{
				anterior_mult = operation;
				multiplicacion_cero = true;
			}				
			operation = operation * v[k];
		}
		else if ((j == 3) && (v[k] != 0) && (operation % v[k] == 0)) {
			operation = operation / v[k];
			division = true; // Marcaje
		}

		if (k == n - 1) { //esValida
			if ((operation == res) && ((j != 3) || division)) //esSolucion
				return true;
		}
		else if ((j != 3) || division)
			if (output(k + 1, n, res, v, operation))
				return true;

		//Desmarcaje (deshacer operacion si se ha producido)
		if (j == 0)
			operation = operation - v[k];
		else if (j == 1)
			operation = operation + v[k];
		else if (j == 2)
			if (multiplicacion_cero)
				operation = anterior_mult;
			else
				operation = operation / v[k];
		else if (j == 3)
			if (division)
				operation = operation * v[k];
	}
	return false;
}