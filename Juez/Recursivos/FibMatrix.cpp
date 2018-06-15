#include<iostream>
using namespace std;

const int DIM = 2;

typedef struct {
	long long int m[DIM][DIM];
} Matrix;

Matrix empty();
Matrix emptyMatrix();
Matrix prod(Matrix m1, Matrix m2);
Matrix fibo(long long int ini, long long int end, Matrix mActual);
void solveCase();


Matrix empty()
{
	Matrix matrix;
	matrix.m[0][0] = 0;
	matrix.m[0][1] = 1;
	matrix.m[1][0] = 1;
	matrix.m[1][1] = 1;

	return matrix;
}

Matrix emptyMatrix()
{
	Matrix matrix;
	for (long long int i = 0; i < DIM; i++)
		for (long long int j = 0; j < DIM; j++)
			matrix.m[i][j] = 0;

	return matrix;
}

Matrix prod(Matrix m1, Matrix m2)
{
	Matrix m3 = emptyMatrix();

	m3.m[0][0] = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) % 46337;
	m3.m[0][1] = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) % 46337;
	m3.m[1][0] = m3.m[0][1];
	m3.m[1][1] = m3.m[0][1] + m3.m[0][0];
	return m3;
}

Matrix fibo(long long int  ini, long long int  end, Matrix mActual)
{
	if (end - ini == 1)
		return prod(empty(), mActual);
	else if (ini == end)
		return empty();
	else
	{
		long long int  middle = (ini + end) / 2;
		
		Matrix mIzquierda = fibo(ini, middle, mActual);
		if (((end - ini) % 2) != 0)
			return  prod(mIzquierda, mIzquierda);
		else
		{
			Matrix mDerecha = fibo(middle + 1, end, mActual);

			return prod(mIzquierda, mDerecha);
		}
	}	
}

void solveCase()
{
	long long int  n = 1;
	cin >> n;
	while (n != 0)
	{
		Matrix m1 = empty();
		m1 = fibo(0, n - 1, m1);
		cout << m1.m[0][1] % 46337 << endl;
		cin >> n;
	}
}

int main() {
	solveCase();
	return 0;
}