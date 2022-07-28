#include <iostream>
#include <fstream>
using namespace std;

//https://www.aceptaelreto.com/problem/statement.php?id=242

#define MAX_ELEMS 200000
int v[MAX_ELEMS];

//{Pre: 0<= n <= longitud(v)
long long erasmus(int v[], int n) {
	long long suma=0, resul=0;
	int i = 0;
/*
(0 <= i <=n) 
^ ret = Sum a,b : 0 <= a < b < i : v[a] + v[b] 
^ suma = Sum a: 0 <= a < i : v[i]
*/
    long long x;
    long long y = 27;
    long long z;

	//const long long qw = 99999999;
	//const long long qw = 199999999;
	const long long qw = 1999999;
	//long long vx[qw];
    for(long long k = 0; k < qw; k++){
        x = qw - k;
		y = k;
		z += x * y;
		cout << "";
		// for(long long j = 0; j < qw; j++)
		// 	cout << "";
    }

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