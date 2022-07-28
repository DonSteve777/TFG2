#include <iostream>
#include <fstream>
using namespace std;

//https://www.aceptaelreto.com/problem/statement.php?id=242

#define MAX_ELEMS 200000
int v[MAX_ELEMS];

//{Pre: 0<= n <= longitud(v)
long long erasmus(int v[], int n) {
	long long suma=0, resul=0;

	for (int i = 0; i < n; i++){
		for (int j = i+1; j< n; j++)
			resul += v[i]*v[j];
	}
	return resul;
}
//{Pos: Sum a,b : 0 < a < b < n: v[a]+v[b]}

bool resuelveCaso() {
	int n;	

	cin >> n;
	if (n == 0)
		return 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << erasmus(v, n) << "\n";

	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
#endif
	return 0;
}