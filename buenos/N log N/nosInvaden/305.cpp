
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MAX_N 100000
#define MAX_EFECTIVOS 1000000


//O(nlogn). Mejor coste para ordenación
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int> & arr, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	// Create temp arrays
	vector<int> L(n1), R(n2);
	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	// Merge the temp arrays back into arr[l..r]
	// Initial index of first subarray
	int i = 0;
	// Initial index of second subarray
	int j = 0;
	// Initial index of merged subarray
	int k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> & v, int l, int r) {
	if (l >= r) {
		return;//returns recursively
	}
	int m = (l + r - 1) / 2;
	mergeSort(v, l, m);
	mergeSort(v, m + 1, r);
	merge(v, l, m, r);
}

int voraz(vector<int> const& invasores, vector<int> const& defensores, int N) {
	int ret = 0;
	int i = 0, d = 0;
	while (d < N) {
		int def = defensores[d];
		int inv = invasores[i];
		if (def >= inv) {
			ret++;
			i++;
		}
		d++;
	}
	return ret;
}



bool resuelveCaso() {
	int N;	//ciudades y equipos de defensa

	cin >> N;
	if (!std::cin)
		return false;

	vector<int> invasores(N);
	vector<int> defensores(N);

	for (int i = 0; i < N; i++) {
		cin >> invasores[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> defensores[i];
	}
	mergeSort(invasores, 0, N - 1);
	mergeSort(defensores, 0, N - 1);

	cout << voraz(invasores, defensores, N) << '\n';
	 


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
#endif
	return 0;
}