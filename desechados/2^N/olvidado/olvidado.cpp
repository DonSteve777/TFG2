#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/** 329 aceptaelreto
 O (2 ^ N)
 a = 2 llamdas
 b = 1 dato menos en cada llamada
**/
long charToOperator(char op, long x, long y) {
	long res;
	switch (op)
	{
	case '+':
		res = x + y;
		break;
	case '-':
		res = x - y;
		break;
	case '*':
		res = x * y;
		break;
	case '/':
		res = x / y;
		break;
	}
	return res;
}

long forgottenJanAux(string & expresion, int & index) {
	if (expresion[index] == ' ')
		index++;
	char c = expresion[index];

	if (c - '0' <= 9 && c - '0' >= 0) {
		return c - '0';
	}
	index++;
	long iz = forgottenJanAux(expresion, index);
	index++;
	long der = forgottenJanAux(expresion, index);

	return charToOperator(c, iz, der);
}


long forgottenJan(string expresion) {
	string expr = expresion;
	int index = 0;
	return forgottenJanAux(expr, index);
}

void resuelveCaso() {
	string expresion;
	
	getline(cin, expresion);
	cout << forgottenJan(expresion) << "\n";
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	unsigned int numCasos;
	string skip;
	std::cin >> numCasos;
	getline(cin, skip);
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}
