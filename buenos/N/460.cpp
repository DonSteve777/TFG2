#include <iostream>
#include <string>

using namespace std;

bool resuelve() {

	string num;
	cin >> num;

	if (!cin) return false;

	cout << num[0];
	int i = 1;
	while (i < num.size()) {

		cout << "0" << num[i];
		++i;
	}

	cout << endl;

	return true;
}

int main() {

	while (resuelve());
	return 0;
}