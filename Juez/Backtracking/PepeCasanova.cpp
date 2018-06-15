#include<iostream>

using namespace std;

void solveCase(int canciones);
void casanova(int k, int n, int &score, int &puntuacion_max, int duracion[], int puntuacion[], int &caraA, int &caraB, int mejor_caso[]);

int main() {

	int canciones;

	cin >> canciones;

	while (canciones != 0) {
		solveCase(canciones);
		cin >> canciones;
	}

	return 0;
}

void solveCase(int canciones)
{
	int score, puntuacion_max, cara, caraA, caraB;
	int duracion[25];
	int puntuacion[25];
	int mejor_caso[25];
	score = 0;
	puntuacion_max = 0;
	cin >> cara;
	caraA = cara;
	caraB = cara;
	for (int i = 0; i < canciones; i++)
	{
		cin >> duracion[i];
		cin >> puntuacion[i];
	}
	
	mejor_caso[canciones - 1] = puntuacion[canciones - 1];
	for (int i = canciones - 2; i >= 0; i--)
		mejor_caso[i] = puntuacion[i] + mejor_caso[i + 1];

	casanova(0, canciones, score, puntuacion_max, duracion, puntuacion, caraA, caraB, mejor_caso);

	cout << puntuacion_max << endl;
}

void casanova(int k, int n, int &score, int &puntuacion_max, int duracion[], int puntuacion[], int &caraA, int &caraB, int mejor_caso[])
{
	for (int i = 0; i < 3; i++)
	{
		if ((i == 0) || ((i == 1) && (caraA - duracion[k] >= 0)) || ((i == 2) && (caraB - duracion[k] >= 0)))
		{
			if (i == 1) {
				caraA = caraA - duracion[k];
				score = score + puntuacion[k];
			}
			if (i == 2) {
				caraB = caraB - duracion[k];
				score = score + puntuacion[k];
			}
			if (k == n - 1) 
			{
				if (score > puntuacion_max)
					puntuacion_max = score;
			}
			else
			{
				if (score + mejor_caso[k + 1] > puntuacion_max)
				casanova(k + 1, n, score, puntuacion_max, duracion, puntuacion, caraA, caraB, mejor_caso);
			}
			if (i == 1) {
				caraA = caraA + duracion[k];
				score = score - puntuacion[k];
			}
			if (i == 2) {
				caraB = caraB + duracion[k];
				score = score - puntuacion[k];
			}
		}
	}
}