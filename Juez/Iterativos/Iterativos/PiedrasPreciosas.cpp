#include<iostream>
#include <vector>
using namespace std;

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

int piedras(vector<piedrasPreciosas> v, int numpiedras, int secuencia, piedrasPreciosas piedra1, int numPiedra1, piedrasPreciosas piedra2, int numPiedra2);
void solveCase();


istream& operator>> (istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

void solveCase()
{
	int casos;
	int numpiedras, secuencia;
	int numtipo1, numtipo2;
	piedrasPreciosas tipo1, tipo2;

	cin >> casos;

	for (int i = 0; i < casos; i++)
	{
		cin >> numpiedras;
		vector<piedrasPreciosas> v(numpiedras);
		cin >> secuencia >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
		for (piedrasPreciosas& p : v)
		{
			cin >> p;
		}
		cout << piedras(v, numpiedras, secuencia, tipo1, numtipo1, tipo2, numtipo2) << endl;
	}
}

int piedras(vector<piedrasPreciosas> v, int numpiedras, int secuencia, piedrasPreciosas piedra1, int numPiedra1, piedrasPreciosas piedra2, int numPiedra2)
{
	int primera = 0, segunda = 0;
	int result = 0;

	for (int i = 0; i < secuencia; i++)
		if (v[i] == piedra1)
			primera++;
		else if (v[i] == piedra2)
			segunda++;

	if ((primera >= numPiedra1) && (segunda >= numPiedra2))
		result++;

	for (int i = secuencia; i < numpiedras; i++)
	{
		if (v[i - secuencia] == piedra1)
		{
			primera--;
		}
		else if (v[i - secuencia] == piedra2)
		{
			segunda--;
		}
		if (v[i] == piedra1)
			primera++;
		else if (v[i] == piedra2)
			segunda++;
		if ((primera >= numPiedra1) && (segunda >= numPiedra2))
			result++;
	}
	return result;
}

int main()
{
	solveCase();
	return 0;
}