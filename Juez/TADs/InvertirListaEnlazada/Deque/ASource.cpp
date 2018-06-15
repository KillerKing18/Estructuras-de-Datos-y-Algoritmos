#include<iostream>
#include"Deque.h"

using namespace std;

bool solveCase();

int main() {
	while (solveCase()){
	}
	return 0;
}

bool solveCase() {
	int number;
	Deque<int> cola;
	if (cin >> number) {
		while (number != 0) {
			cola.push_back(number);
			cin >> number;
		}
		cola.invert();
		cola.display();
		cout << endl;
		return true;
	}
	return false;
}