#include <iostream>
#include <string>

using namespace std;

bool solveCase();
int palabras(string linea);

int main()
{
	while (solveCase())
	{

	}
	return 0;
}

bool solveCase()
{
	string linea;

	if (getline(cin, linea))
	{
		cout << palabras(linea) << endl;
		return true;
	}
	else
		return false;
}

int palabras(string linea)
{
	int result = 0;
	int i = 1;
	
	for (i; i < linea.size(); i++)
	{
		if ((linea[i - 1] != ' ') && (linea[i] == ' '))
		{
			result++;
		}
	}
	
	if ((linea[i - 1] != ' ') && (linea.size() != 0))
		result++;

	return result;
}