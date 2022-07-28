#include <iostream>

using namespace std;

long long int ordenar(int v[], int ini, int fin) {

	int w[100000];
	int mitad = (ini + fin) / 2;
	long long int inversiones = 0;

	for (int i = ini; i <= fin; i++) w[i] = v[i];

	int i = ini;
	int j = mitad + 1;
	int aux = ini;

	while (i < mitad + 1 && j < fin + 1) {

		if (w[i] <= w[j]) {
			v[aux] = w[i];
			++i;
		}
		else {
			v[aux] = w[j];
			++j;
			inversiones += mitad + 1 - i;
		}
		++aux;
	}

	while (i < mitad + 1) {
		v[aux] = w[i];
		++i;
		++aux;
	}
	while (j <= fin) {
		v[aux] = w[j];
		++j;
		++aux;
	}

	return inversiones;
}

// si longitud(v) es < 2 siempre va a ser 0 ya que o esta vacio o no existe otro dato con el cual comparar
long long int numInversiones(int v[], int ini, int fin) {

	int longitud = fin - ini + 1;

	if (longitud < 2) return 0;

	if (longitud == 2) {
		if (v[ini] > v[fin]) {
			swap(v[ini], v[fin]);
			return 1;
		}
		else return 0;
	}

	int mitad = (ini + fin) / 2;
	long long int resultado = 0;
	resultado = numInversiones(v, ini, mitad) + numInversiones(v, mitad + 1, fin) + ordenar(v, ini, fin);

	return resultado;

}

int main() {
	int n;
	int v[100000];
	cin >> n;

	while (n > 0) {

		for (int i = 0; i < n; i++) cin >> v[i];
		cout << numInversiones(v, 0, n - 1) << endl;
		cin >> n;
	}

	return 0;
}