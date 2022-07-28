#include <iostream>
#include <fstream>
using namespace std;

// {Pre: 0 <= n <= longitud(v) } 
int abadias(int v[], int numPicos){
	int max, abadias = 1;
	
	max = v[numPicos - 1];
	
	for (int i = numPicos-2; i >= 0; --i) {
		if (v[i] >max) {
			max = v[i];
			abadias++;
		}
	}

	return abadias;
}

// {Post: r = #i: 0 <= i < n && (PT j: 0 <= i < j: v[i] > v[j]) }	r es el número de elementos mayores que todos sus posteriores	

bool caso() {
	int numPicos;
	int v[100000];
	cin >> numPicos;

	if (numPicos == 0)
		return false;

	for (int i = 0; i < numPicos; ++i) {
		cin >> v[i];
	}
	
	
	cout << abadias(v, numPicos) << endl;
	return true;
}

bool resuelveCaso() {
   int numPicos;
	int v[100000];
	cin >> numPicos;

	if (numPicos == 0)
		return false;
	for (int i = 0; i < numPicos; ++i) {
		cin >> v[i];
	}
	cout << abadias(v, numPicos) << endl;
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
