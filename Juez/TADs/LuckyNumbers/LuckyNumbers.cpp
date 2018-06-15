#include<queue>
#include<iostream>

using namespace std;

void solveCase(int number);
void deleteNumbers(queue<int> &cola, int number);

int main() {
	int number;
	cin >> number;
	while (number != 0) {
		solveCase(number);
		cin >> number;
	}
	return 0;
}

void deleteNumbers(queue<int> &cola, int number) {
	/*int i = 0;
	while (i < cola.size) {

		i += number - 1;
	}*/
	int size = cola.size();
	int final;
	for (int i = size - 1; i >= 0; i--) {
		if (i % number != 0) {
			final = cola.front();
			cola.push(final);
			cola.pop();
		}
		else {
			cola.pop();
		}
	}
}

void solveCase(int number) {
	queue<int> cola;

	for (int i = number; i >= 1; i--) {
		cola.push(i);
	}
	int remove = 2;
	while (cola.size() >= remove) {
		deleteNumbers(cola, remove);
		remove++;
	}
	int size = cola.size();
	cout << number << ": ";
	for (int i = 0; i < size; i++) {
		cout << cola.front() << " ";
		cola.pop();
	}
	cout << endl;
}