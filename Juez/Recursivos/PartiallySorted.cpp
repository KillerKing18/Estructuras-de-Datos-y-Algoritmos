#include<iostream>

using namespace std;

bool createArray();
bool output(int v[], int ini, int end, int &left, int &right);

int main()
{
	while (createArray());

	return 0;
}

bool createArray()
{
	int *v = new int[1000000];
	bool result = false;
	int i = 0;
	int input = -1;

	cin >> input;

	if (input == 0) return false;

	while (input != 0)
	{
		v[i] = input;
		cin >> input;
		i++;
	}

	int left;
	int right;

	result = output(v, 0, i, left, right);

	if (result)
	{
		cout << "SI" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return true;
}

// P: {end = 2 ^ n,s where n belongs to N Union {0}}
bool output(int v[], int ini, int end, int& left, int& right)
{
	bool result = false;

	int middle = (ini + end) / 2;

	if (end - ini == 1)
	{
		return true;
	}

	if (end - ini == 2)
	{
		if (v[ini] <= v[end - 1])
		{
			left = v[ini];
			right = v[end - 1];
			return true;
		}
		else
		{
			return false;
		}
	}


	bool isSortedLeft = output(v, ini, middle, left, right);
	int leftLeft = left;
	int leftRight = right;
	bool isSortedRight = output(v, middle, end, left, right);
	int rightLeft = left;
	int rightRight = right;

	if (isSortedLeft && isSortedRight && (leftLeft <= rightLeft) && (leftRight <= rightRight))
	{
		result = true;
	}

	left = leftLeft;
	right = rightRight;

	return result;
}
// Q : {result = isAlmostSorted(v, ini, end)}
// isAlmostSorted(v, ini, end) = (No exists i : middle <= i < end : v[i] < (min u : ini <= u < middle : v[u])) ^ (No exists w : ini <= w < middle : v[w] >(max k : middle <= k < end : v[k])) ^ isAlmostSorted(v, ini, (ini + end) / 2)) ^ isAlmostSorted(v, (ini + end) / 2, end))
// Complexity : O(log n)