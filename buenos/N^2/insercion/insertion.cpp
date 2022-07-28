/* C++ program for Insertion Sort 

N^2
*/
#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ELEMS 1000000
int v[MAX_ELEMS];

//ordenación por inserción: 
void ordenaIns (int v[], int num){ //coge un elemento, mira a su izquierda, lo inserta ordenado en esta parte y desplaza el resto
	int i, j, x;
	
	for (i=1; i < num; i++){
		x=v[i];
		j=i-1;
		while ((j>=0) && (v[j]> x)){ //va desplazando hacia la derecha los v[j] hasta encontrar un v[j]<v[i]
			v[j+1] =v[j];
			j=j-1;			
		}
		v[j+1]=x; //inserta el v[i]
	}
}	
			
void resuelveCaso() {
	int n;	
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	ordenaIns(v, n);

	// for (int i = 0; i < n; i++)
	// 	cout << " " << v[i];
	// cout << "\n";

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
