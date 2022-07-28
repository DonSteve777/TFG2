//O (1 / N^2)
#include <fstream>
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)
//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=666



bool resuelveCaso() {

	int n;
    std::cin >> n;
	// if (scanf("%d", &n) == 1 && n) {
    if (n)
    {
		bool solution = false;
		for (int fghij = 1234; fghij <= 98765 / n; fghij++) {
			int abcde = fghij * n;
			int tmp, used = (fghij < 10000); //flag que indica si ya he usado el 0 en el digito f. used es una macascara de bits, en la que cada bit indica si se ha suda el digito en la posicion del bit
			// voy marcando cada digito del numero, y si luego resulta que falta alguno sin usar(o lo que es lo mismo, se ha usado alguno 2 o mas veces), significa que no ha habido suerte
			tmp = abcde; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
			tmp = fghij; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
			if (used == (1 << 10) - 1) {	// == 0011 1111 1111
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
				solution = true;
			}
		}
		if (!solution)
			printf("There are no solutions for %d.", n);
		printf("\n\n");
        
        return true;
	}
    else
        return false;
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