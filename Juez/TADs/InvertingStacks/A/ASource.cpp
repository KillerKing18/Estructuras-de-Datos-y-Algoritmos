#include<iostream>
#include"Stack.h"

using namespace std;

template<typename T>
void resolver(int number, int elements);

template <typename T>
void invertBase(Stack<T> &s, int m);

void solveCases();

template <typename T>
void invertBase(Stack<T> &s, int m) {
	int index = 0;

	Stack<T> intermedia;
	Stack<T> finalStack;
	while (index < m && s.size() != 0) {
		intermedia.push(s.top());
		s.pop();
		index++;
	}
	while (s.size() != 0) {
		finalStack.push(s.top());
		s.pop();
		index++;
	}
	for (int i = 0; intermedia.size() != 0; i++) {
		finalStack.push(intermedia.top());
		intermedia.pop();
	}
	s = finalStack;
}

void resolver(int number, int elements) {
	int elem;
	Stack<int> s1, s2;
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
	invertBase(s1, elements);
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