#include<iostream>

using namespace std;

void solveCase();
void torre(int k, int n, int &azules, int &rojas, int &verdes, int sol[], int maxazules, int maxrojas, int maxverdes, bool &solucion);
void imprimir(int sol[], int n);

int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int altura, maxazules, maxrojas, maxverdes, azules, rojas, verdes;
	bool solucion;
	cin >> altura >> maxazules >> maxrojas >> maxverdes;

	while (altura != 0 || maxazules != 0 || maxrojas != 0 || maxverdes != 0){
		int* sol = new int[altura];
		solucion = false;
		azules = 0;
		rojas = 1;
		verdes = 0;
		sol[0] = 1;

		torre(1, altura, azules, rojas, verdes, sol, maxazules, maxrojas, maxverdes, solucion);

		if (!solucion)
			cout << "SIN SOLUCION" << endl;
		cout << endl;
		cin >> altura >> maxazules >> maxrojas >> maxverdes;
	}
}

void torre(int k, int n, int &azules, int &rojas, int &verdes, int sol[], int maxazules, int maxrojas, int maxverdes, bool &solucion){
	for (int i = 0; i <= 2; i++)
	{
		if (((i == 2) && (sol[k - 1] != 2) && (verdes < azules) && (maxverdes > verdes)) ||
			((i == 1) && (maxrojas > rojas)) ||
			((i == 0) && (maxazules > azules)))
		{
			sol[k] = i;

			if (i == 2) verdes++;
			if (i == 1) rojas++;
			if (i == 0) azules++;

			if ((k == n - 1) && (rojas > azules + verdes)){ //EsSolucion
				solucion = true;
				imprimir(sol, n);
			}
			else if (k < n - 1)
				torre(k + 1, n, azules, rojas, verdes, sol, maxazules, maxrojas, maxverdes, solucion);

			if (i == 2) verdes--;
			if (i == 1) rojas--;
			if (i == 0) azules--;
		}
	}
}

void imprimir(int sol[], int n) {
	for (int j = 0; j < n - 1; j++) {
		if (sol[j] == 0)
			cout << "azul ";
		else if (sol[j] == 1)
			cout << "rojo ";
		else
			cout << "verde ";
	}
	if (sol[n - 1] == 0)
		cout << "azul" << endl;
	else if (sol[n - 1] == 1)
		cout << "rojo" << endl;
	else
		cout << "verde" << endl;
}