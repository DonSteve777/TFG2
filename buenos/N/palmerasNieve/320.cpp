#include <iostream>
#include <fstream>
using namespace std;


int palmeras(int v[], int n, int peso) {
	int depie = 0, ini = 0, max = 0, actual = 0;

	for (int i = 0; i< n; i++){
		if (v[i] < peso) { //La palmera no soporta el peso
			actual++;
		}
		else {	//Se mantiene
			if (depie < 5) {
				depie++;
				actual++;
			}
			else {	//Ya hay 5 palmeras en pie
				while (v[ini] < peso) { //Volvemos a la primera palmera en pie
					ini++;
					actual--;
				}
				ini++;
			}
		}
		if (actual > max) max = actual; //Actualizamos la maxima longitud de la franja
	}

	return max;
}

void resuelveCaso() {
    // Leer datos
    int n, peso;

    cin >> peso;
    cin >> n;
    int v[100000];
    for (int i=0; i<n; i++)
        cin >> v[i];
    // escribir resultado
    cout << palmeras(v, n, peso) << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    
    return 0;
}





