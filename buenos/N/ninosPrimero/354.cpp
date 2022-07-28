#include<iostream>
#include<fstream>
using namespace std;

int ninos(int v[], int n) {
	int i = 1;
	int numNinos = 1;
	int max = v[0];
	int altura = v[0];
	while (i < n) {
		if (v[i] <= altura) { //Si la persona que pasa tiene una altura <= que la primera que pasó
			numNinos = i+1;			//se añade un niño y se actualiza la altura maxima para que se le considere un niño
			altura = max;
		}
		else if (v[i] > max) max = v[i]; //Actualiza la maxima altura de las personas que van pasando

		i++;
	}
	return numNinos;
}


bool resuelveCaso() {
    // Leer datos
    int n;
    cin >> n;
    if (n == 0)
        return false;

    int v[200000];
    for (int i=0; i<n; i++)
        cin >> v[i];

    cout <<  ninos(v, n) << endl;
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


/*
N = 10
i = 1 | N = 10 | seconds = 0.012331800
--------------------------------------------
--------------------------------------------
N = 100000
i = 2 | N = 100000 | seconds = 0.359261100
--------------------------------------------
--------------------------------------------
N = 200000
i = 3 | N = 200000 | seconds = 0.809386500
--------------------------------------------
--------------------------------------------

Buenos tiempos

*/