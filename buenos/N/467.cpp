#include <iostream>
#include <string>

using namespace std;

bool sonIguales(string palabra1, string palabra2) {

	bool ret = true;
	int i = 0;

	while (i < palabra1.size() && ret) {

		if (tolower(palabra1[i]) == tolower(palabra2[i])) ++i;
		else ret = false;
	}

	return ret;
}

bool resuelve(int numCasos) {

	if (numCasos == 0) return false;

	string palabra1, aux, palabra2;
	cin >> palabra1 >> aux >> palabra2;

	if (palabra1.size() == palabra2.size() && sonIguales(palabra1, palabra2)) cout << "TAUTOLOGIA" << endl;
	else cout << "NO TAUTOLOGIA" << endl;

	return true;
}

int main() {

	int numCasos;
	cin >> numCasos;

	while (resuelve(numCasos)) --numCasos;
	return 0;
}