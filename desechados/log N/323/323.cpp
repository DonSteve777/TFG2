
// busqueda binaria
// O log N

#include <iostream>
#include <fstream>
using namespace std;

int cuentaDigitos(int x) {
	if (x < 10)
		return 1;
	else if (x < 100)
		return 2;
	else if (x < 1000)
		return 3;
	else if (x < 10000)
		return 4;
	else if (x < 100000)
		return 5;
	else if (x < 1000000)
		return 6;
	else
		return 7;
}

// first es el primer numero de [i-1] digitos
int first[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

// dado un intervalo calcula el numero de digitos a transcribir
int transcribir(int ini, int fin) {
	int a = cuentaDigitos(ini);
	int b = cuentaDigitos(fin);
	int counter = 0;
	int anterior = ini;

	for (int i = a; i <= b; i++) {
		if (i == b)	//
			counter += (fin + 1 - anterior)*i;
		else
			counter += (first[i] - anterior)* i ;	// cuento los digitos de los numeros desde el actual hasta first
		anterior = first[i];
	}
	return counter;
}

// 99 102  a == b = 100
// 1 5		a == b   2

//problema para casos de fin <= 9
int conteoDeLaRosa(int ini, int fin, int a, int b) {
	if (ini + 1 == fin)
		return ini;

	if (a >= b)
		return a;
	
	int mid = (b + a) / 2;
	int digitsIzq = transcribir(ini, mid);
	int digitsDer = transcribir(mid + 1, fin);	//tengo que anadirle lo de antes

	if (digitsDer == digitsIzq )
		return mid;
	else if (digitsDer > digitsIzq) {
		
		if (a == mid) {
			// Adso hasta b
			int dIb = transcribir(ini, b);
			int dDb = transcribir(b+1, fin);
			
			if (dDb < dIb)
				return a;
			if (digitsDer - digitsIzq < dDb - dIb)
				return a;
			else
				return b;
		}
		else
			return conteoDeLaRosa(ini, fin, mid, b);
	}
	else {	
		return conteoDeLaRosa(ini, fin, a, mid-1);
	}
	
	return mid;
}


bool resuelveCaso() {
	int ini, fin;
	cin >> ini >> fin;
	if (ini == 0 && fin == 0)
		return false;
	cout << conteoDeLaRosa(ini, fin, ini, fin) << "\n";
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

