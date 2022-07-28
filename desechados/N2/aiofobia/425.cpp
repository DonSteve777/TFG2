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

#include <fstream>
#include <iostream>

// Cuadratico
size_t resolver(const std::string& palabra) {

	size_t i;
	Matriz<size_t> espacioDeSoluciones(palabra.size(),palabra.size(),0);

	for(size_t d = 1 ; d < palabra.size() ; d++)
		for(size_t j = d ; j < palabra.size() ; j++) {
			i = j - d;
			if( palabra[i] == palabra[j] )
				espacioDeSoluciones[i][j] = espacioDeSoluciones[i+1][j-1];
			else
				espacioDeSoluciones[i][j] = 1 + std::min(espacioDeSoluciones[i][j-1],espacioDeSoluciones[i+1][j]);
		}
	return espacioDeSoluciones[0][palabra.size()-1];
}

bool resuelveCaso() {

	std::string palabra;
	std::cin >> palabra;

	if(!std::cin)
		return false;
	std::cout << resolver(palabra) << std::endl;
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