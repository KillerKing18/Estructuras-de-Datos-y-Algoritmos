#include<set>
#include<string>
#include<iostream>

using namespace std;

bool solveCase();


int main() {
	while (solveCase()) {

	}
	return 0;
}

bool solveCase() {
	char c;
	int elementos;
	if (cin >> c) {
		cin >> elementos;
		if (c == 'N') {
			int number;
			set<int> setInt;
			cin >> number;
			while (number != -1) {
				setInt.insert(number);
				cin >> number;
			}
			while (setInt.size() != elementos)
				setInt.erase(setInt.begin());
			for (auto it = setInt.cbegin(); it != setInt.cend(); it++)
				cout << *it << " ";
		}
		else if (c == 'P') {
			string str;
			set<string> setStr;
			cin >> str;
			while (str != "FIN") {
				setStr.insert(str);
				cin >> str;
			}
			while (setStr.size() != elementos)
				setStr.erase(setStr.begin());
			for (auto it = setStr.cbegin(); it != setStr.cend(); it++)
				cout << *it << " ";
		}
		cout << endl;
		return true;
	}
	else
		return false;
}