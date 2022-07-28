//https://www.aceptaelreto.com/problem/statement.php?id=357

using namespace std;
// Nombre y Apellidos

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>


// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// division de los datos en 2 mitades -> b = 2
// una sola llamada recursiva -> a = 1
// coste constante de la parte no recursiva -> k = 0
// estamos en el caso		O (n ^ k log n )   si  a = b ^ k
// O(log N)


int resolver(int cajas) {
	if (cajas == 1)
		return 1;
	else {
		int mitad = cajas / 2;
		
		return 1+ resolver(mitad);
	}
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	int cajas;
	// leer los datos de la entrada
	cin >> cajas;
	if (!std::cin)  // fin de la entrada
		return false;

	cout << resolver(cajas) << "\n";

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif
	return 0;
}
