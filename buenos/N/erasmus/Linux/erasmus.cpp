#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ELEMS 100000
//https://www.aceptaelreto.com/problem/statement.php?id=242

int v[MAX_ELEMS];
std::ofstream output;


//{Pre: 0<= n <= longitud(v)
long long erasmus(int v[], int n) {
	long long suma=0, resul=0;
	int i = 0;
/*
(0 <= i <=n) 
^ ret = Sum a,b : 0 <= a < b < i : v[a] + v[b] 
^ suma = Sum a: 0 <= a < i : v[i]
*/
	while (i < n){
		resul += v[i] * suma;
		suma += v[i];
		++i;
	}
	return resul;
}
//{Pos: Sum a,b : 0 < a < b < n: v[a]+v[b]}

bool resuelveCaso() {
	int n;	
	cin >> n;
	if (n == 0)
		return 0;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	
	cout << erasmus(v, n) << '\n';

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