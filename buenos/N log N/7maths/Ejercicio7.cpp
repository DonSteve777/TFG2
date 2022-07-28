//septiembre 2014
#include <iostream>
using namespace std;

int algoritmo(int valores[], int inicio, int fin) {
	cout << inicio << " " << fin << endl;
	if (inicio == fin) {
		if (inicio != 0)
		{
			if (valores[inicio] < valores[inicio - 1]) return valores[inicio];
			return valores[inicio - 1];
		}
		return valores[0];
	}
	else {
		int mitad = (inicio + fin) / 2;
		if (valores[mitad] > valores[inicio]) {
			return algoritmo(valores, inicio, mitad);
		}
		return algoritmo(valores, mitad+1, fin);
	}
}

void iniciar(int n) {
	int valores[1000];
	for (int i = 0; i < n; i++) cin >> valores[i];
	
	cout<<algoritmo(valores, 0, n - 1 )<<endl;
	
}


int main() {
	int n;

	cin >> n;
	while (n != 0) {
		iniciar(n);
		cin >> n;
	}
	return 0;
}