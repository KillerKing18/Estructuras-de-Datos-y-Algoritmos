#include<stack>
#include<iostream>

using namespace std;

void solveCase();
void dehesa(int order[], int n);

int main() {
	solveCase();
}

void solveCase() {
	int number = 1;
	cin >> number;
	int order[100000];
	for (int i = 0; i < number; i++) {
		cin >> order[i];
	}
	while (number != 0) {
		dehesa(order, number);
		cin >> number;
		for (int i = 0; i < number; i++) {
			cin >> order[i];
		}
	}
}

void dehesa(int order[], int n) {
	int i = 1;
	int j = 0;
	bool posible = true;
	stack<int> pila;
	while (i <= n) {
		cout << "Wagon " << i << " in" << endl;
		pila.push(i);
		while (j < n && pila.size() > 0 && order[j] == pila.top()) {
			cout << "Wagon " << pila.top() << " out" << endl;
			pila.pop();
			j++;
		}
		i++;
	}
	while (pila.size() > 0 && j < n && posible) {
		if (order[j] == pila.top()) {
			cout << "Wagon " << pila.top() << " out" << endl;
			pila.pop();
			j++;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
			posible = false;
		}
	}
	if (j == n)
		cout << "POSSIBLE" << endl;
}