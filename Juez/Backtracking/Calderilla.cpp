#include<iostream>

using namespace std;

void solveCase();
void calderilla(int k, int &coins, int &mejor_valor, int &objetivo, int monedas[], int valor[], bool &solucion, int &restantes, int &total);


int main()
{
	solveCase();
	return 0;
}

void solveCase()
{
	int m, objetivo, mejor_valor, cantidad, restantes, coins, total;
	bool solucion, impares;
	int monedas[8];
	int valor[8];

	valor[0] = 1;
	valor[1] = 2;
	valor[2] = 5;
	valor[3] = 10;
	valor[4] = 20;
	valor[5] = 50;
	valor[6] = 100;
	valor[7] = 200;

	cin >> m;

	for (int i = 0; i < m; i++) {

		cin >> objetivo;
		total = 0;
		restantes = 0;
		impares = false;

		for (int j = 0; j < 8; j++) {
			cin >> cantidad;
			if ((j == 0 || j == 2) && !impares) {
				if (cantidad > 0)
					impares = true;
			}
			total = total + (cantidad * valor[j]);
			restantes = restantes + cantidad;
			monedas[j] = cantidad;
		}

		mejor_valor = 0;
		coins = 0;
		solucion = false;
		if (total > objetivo) { // Cota : Imposible llegar al objetivo si no tenemos el dinero suficiente
			if ((impares && (objetivo % 2 != 0)) || (objetivo % 2 == 0)) // Cota : Imposible llegar al objetivo si nuestro objetivo es impar y no tenemos ningun tipo de moneda impar
				calderilla(0, coins, mejor_valor, objetivo, monedas, valor, solucion, restantes, total);
		}

		if (solucion)
			cout << mejor_valor << endl;
		else
			cout << "IMPOSIBLE" << endl;
	}
}

void calderilla(int k, int &coins, int &mejor_valor, int &objetivo, int monedas[], int valor[], bool &solucion, int &restantes, int &total) {
	bool no_seguir;
	for (int i = 0; i <= monedas[k]; i++)
	{
		no_seguir = false;
		if (objetivo - (i * valor[k]) >= 0) // Satisfactibilidad : No tiene sentido coger monedas de más si te vas a pasar de tu objetivo
		{
			objetivo = objetivo - (i * valor[k]);
			coins = coins + i;
			monedas[k] = monedas[k] - i;
			restantes = restantes - i; // Cota
			total = total - (i * valor[k]); // Cota

			if ((objetivo % 2 != 0) && (k == 2)) // Cota : Si el objetivo que nos queda es impar y ya estamos el el nivel 2 (monedas de 5 centimos), sera imposible que lleguemos a un objetivo impar en los siguientes niveles
				no_seguir = true;				// con monedas de 10, 20, 50, 100 0 200 centimos, pues son pares

			if (objetivo == 0) { // EsSolucion
				if (coins > mejor_valor) { //EsMejorSolucion
					solucion = true;
					mejor_valor = coins;
				}
			}
			else if ((restantes > 0) && // Cota: Solo bajamos de nivel si quedan monedas
						(coins + restantes > mejor_valor) && // Cota : Solo bajamos de nivel si es posible encontrar una solucion mejor
							(!no_seguir) && // Cota : Explicada en la linea 79
								(objetivo - total <= 0) && // Cota : Solo bajamos de nivel si va a ser posible llegar a nuestro objetivo (si sabemos que no nos vamos a quedar cortos)
									(k <= 6)) // Solo hacemos llamada recursiva si no estamos en el ultimo nivel
				calderilla(k + 1, coins, mejor_valor, objetivo, monedas, valor, solucion, restantes, total);

			objetivo = objetivo + (i * valor[k]);
			coins = coins - i;
			monedas[k] = monedas[k] + i;
			restantes = restantes + i; // Cota
			total = total + (i * valor[k]); // Cota
		}
	}
}