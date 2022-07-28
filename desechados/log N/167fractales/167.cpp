#include <iostream>
#include <fstream>
using namespace std;
/*
https://www.aceptaelreto.com/problem/mysubmissions.php?id=167

a = 1 llamada recursiva
b = 2 (division entre 2 de los datos)
k = 0 (parte no recursiva contstante)

a = b ^ k   ==>   O(n^k * log n) = O( log n) */

int fractal(int l) {
	if (l == 1)
		return 4;
	else
		return 4 * l + 4*fractal(l / 2);
}

bool resuelveCaso() {

	int l;
	cin >> l;

	if (!std::cin)
		return false;
	cout << fractal(l) <<endl;

	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
