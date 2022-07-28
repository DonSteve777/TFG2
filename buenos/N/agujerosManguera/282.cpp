#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int voraz(vector<int> const& v, int L) {
	int size = v.size();
	int parches = 1;
	int principioParcheActual = v[0];
	for (int i = 1; i < size; ++i) {
		if (principioParcheActual + L < v[i]) {
			principioParcheActual = v[i];
			parches++;
		}
	}
	return parches;
}

bool resuelveCaso() {
	int N, L; //agujeros, longitud parches

	cin >> N >> L;
	if (!std::cin)
		return false;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cout << voraz(v, L) << '\n';

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
	system("PAUSE");
#endif
	return 0;
}