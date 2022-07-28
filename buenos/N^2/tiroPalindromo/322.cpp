//
//  Matriz.h
//
//  Implementación de matrices (arrays bidimensionales)
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020  Alberto Verdejo
//


#include <vector>
#include <ostream>


template <typename Object>
class Matriz {
public:
    // crea una matriz con fils filas y cols columnas,
    // con todas sus celdas inicializadas al valor e
    Matriz(int fils = 0, int cols = 0, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}
    
    // operadores para poder utilizar notación M[i][j]
    std::vector<Object> const& operator[](int f) const {
        return datos[f];
    }
    std::vector<Object> & operator[](int f) {
        return datos[f];
    }
    
    // métodos que lanzan una excepción si la posición no existe
    Object const& at(int f, int c) const {
        return datos.at(f).at(c);
    }
    Object & at(int f, int c) {
        return datos.at(f).at(c);
    }
    
    int numfils() const { return datos.size(); }
    int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }
    
    bool posCorrecta(int f, int c) const {
        return 0 <= f && f < numfils() && 0 <= c && c < numcols();
    }
    
private:
    std::vector<std::vector<Object>> datos;
};

template <typename Object>
inline std::ostream & operator<<(std::ostream & out, Matriz<Object> const& m) {
   for (int i = 0; i < m.numfils(); ++i) {
      for (int j = 0; j < m.numcols(); ++j) {
         out << m[i][j] << ' ';
      }
      out << '\n';
   }
   return out;
}


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/*
palindromo(i,j)=tama�o del palindromo m�s grande que se puede contruir a partir de la palabra con letras de i a j
palindromo(i,j) = palindromo(i+1,j-1)+2 si letra(i)==letra(j)
				  max(palindromo(i+1,j),palindromo(i,j-1)) si letra(i)!=letra(j)			
CB:
palindromo(i,j) = 1 cuando i==j
*/
string palindromo(const string &palabra){
	int N = palabra.size()-1;
	Matriz<int> tabla(N + 1, N + 1, 0);

	for (int d = 1; d <= N - 1; d++)
		tabla[d][d] = 1;

	for (int d = 1; d <= N - 1; d++){
		for (int i = 1; i <= N - d; i++){
			int j = i + d;

			if (palabra[i] == palabra[j]){
				//sumamos +2 porque ser�an la misma letra dos veces la que escribiriamos
				tabla[i][j] = tabla[i + 1][j - 1] + 2;
			}
			else{
				tabla[i][j] = max(tabla[i+1][j], tabla[i][j-1]);
			}
		}
	}

	int tamanio = tabla[1][N];
	string pal(tabla[1][N]+1, ' ');
	int a = 1, b = N;
	int x = 1, y = tamanio;
	
	while (tamanio > 0){
		if (tamanio == 1){
			pal[x] = palabra[b];
			tamanio--;
		}
		else if (palabra[a] == palabra[b]){
			pal[x] = palabra[a];
			pal[y] = palabra[b];
			//se colocan dos letras, por lo que reducimos dos veces el tama�o de lo que nos queda por formar del palindromo
			tamanio--;
			tamanio--;
			a++; x++;
			b--; y--;
		}
		else{
			if (tabla[a][b - 1] > tabla[a + 1][b]){
				b--;
			}
			else{
				a++;
			}
		}
	}
	
	pal = pal.substr(1, pal.size() - 1);

	return pal;
}

bool resuelveCaso() {
	string palabra;
	
	cin >> palabra;
	palabra = ' ' + palabra;

	if (!std::cin)  // fin de la entrada
		return false;

	cout << palindromo(palabra) << "\n";

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