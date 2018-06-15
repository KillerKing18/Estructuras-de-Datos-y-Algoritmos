#include"Queue.h"
#include<iostream>

using namespace std;

bool solveCase();

int main() {
	while (solveCase()){
	}
	return 0;
}

bool solveCase() {
	int number;
	Queue<int> cola;
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