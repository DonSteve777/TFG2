#include <iostream>

using namespace std;

//Puede haber como maximo 24 de peso de las uvas que te puedes comer y uvas que puedes tener.
const int MAX = 24;

int v[MAX];
//int solParcial[MAX];

int posibles(int k, int pesoAcumulado, int uvasAcumuladas, int n, int peso) {
	if (uvasAcumuladas == 12) return 1;
	if (k == n) return 0;

	int numPosibles = 0;
	int pesoActual = v[k];
	pesoActual += pesoAcumulado;

	if (pesoActual <= peso) numPosibles += posibles(k + 1, pesoAcumulado + v[k], uvasAcumuladas + 1, n, peso); //Mientras no se supere el peso.
	numPosibles += posibles(k + 1, pesoAcumulado, uvasAcumuladas, n, peso); //Caso en el que no se coje la uva v[k].

	return numPosibles;
}

int main() {

	int peso, n;
	cin >> peso >> n;

	while (peso != 0 && n != 0)
	{
		for (int i = 0; i < n; ++i)	cin >> v[i];
		cout << posibles(0, 0, 0, n, peso) << endl;
		cin >> peso >> n;
	}

	return 0;
}

