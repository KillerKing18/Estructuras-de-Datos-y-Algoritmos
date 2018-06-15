#include<iostream>
#include"LinkedListStack.h"

using namespace std;

template<typename T>
void resolver(int number, int elements);


void solveCases();


void resolver(int number, int elements) {
	int elem;
	LinkedListStack<int> s1, s2;
	// Read
	for (int i = 0; i < number; i++) {
		cin >> elem;
		s2.push(elem);
	}
	for (int i = 0; i < number; i++) {
		elem = s2.top();
		s2.pop();
		s1.push(elem);
	}
	// Solve
	s1.invertBase(elements);
	// Display
	for (int i = 0; i < number; i++) {
		cout << s1.top();
		s1.pop();
		if (i < number - 1)
			cout << " ";
	}
}

void solveCases() {
	int number, elements;
	
	cin >> number;
	while (number != -1) {
		cin >> elements;
		resolver(number, elements);
		cout << endl;
		cin >> number;
	}
}

int main() {
	solveCases();
	return 0;
}