// grafos: maxima componente conexa
// O (V+ E)


#include <iostream>
#include <vector>
#include <stdexcept>

using Adys = std::vector<int>;  // lista de adyacentes a un vértice

class Grafo {
   
   int _V;   // número de vértices
   int _E;   // número de aristas
   std::vector<Adys> _ady;   // vector de listas de adyacentes
   
public:
   
   /**
    * Crea un grafo con V vértices.
    */
   Grafo(int v) : _V(v), _E(0), _ady(_V) {}
   
   /**
    * Devuelve el número de vértices del grafo.
    */
   int V() const { return _V; }
   
   /**
    * Devuelve el número de aristas del grafo.
    */
   int E() const { return _E; }
   
   
   /**
    * Añade la arista v-w al grafo.
    * @throws invalid_argument si algún vértice no existe
    */
   void ponArista(int v, int w) {
      if (v >= _V || w >= _V)
         throw std::invalid_argument("Vertice inexistente");
      ++_E;
      _ady[v].push_back(w);
      _ady[w].push_back(v);
   }
   
   
   /**
    * Devuelve la lista de adyacencia de v.
    * @throws invalid_argument si v no existe
    */
   Adys const& ady(int v) const {
      if (v >= _V)
         throw std::invalid_argument("Vertice inexistente");
      return _ady[v];
   }
   
   
   /**
    * Muestra el grafo en el stream de salida o (para depurar)
    */
   void print(std::ostream & o = std::cout) const {
      o << _V << " vértices, " << _E << " aristas\n";
      for (auto v = 0; v < _V; ++v) {
         o << v << ": ";
         for (auto w : _ady[v]) {
            o << w << " ";
         }
         o << "\n";
      }
   }
   
};

/**
 * Para mostrar grafos por la salida estándar
 */
inline std::ostream & operator<<(std::ostream & o, Grafo const& g){
   g.print(o);
   return o;
}



#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


#include <vector>
using namespace std;


class MaximaComponenteConexa{

public: 
//O (V+E)
	MaximaComponenteConexa(Grafo const& G) : marked(G.V(), false), _maximo(0){

		for (int v = 0; v < G.V(); v++){
			if (!marked[v]){
				int tam = 0;
				dfs(G, v, tam);
				_maximo = max(_maximo, tam);
			}
		}
	}

	int maximo() const{
		return _maximo;
	}
private:
	vector<bool> marked;
	int _maximo;

	void dfs(Grafo const &G, int v, int &tam){

		marked[v] = true;
		tam++;

		for (int w : G.ady(v)){
			if (!marked[w]){
				dfs(G, w, tam);
			}
		}
	}

};

// resuelve un caso de prueba
void resuelveCaso() {
	int amigos, pares;
	cin >> amigos >> pares;

	Grafo grafo(amigos);

	for (int i = 0; i < pares; i++){
		int amigo1, amigo2;
		cin >> amigo1 >> amigo2;
		
		grafo.ponArista(amigo1 - 1, amigo2 - 1);
	}
	MaximaComponenteConexa mcc(grafo);
	cout << mcc.maximo() << endl;
}



int main() {

// 	// ajuste para que cin extraiga directamente de un fichero
// #ifndef DOMJUDGE
// 	std::ifstream in("casos.txt");
// 	auto cinbuf = std::cin.rdbuf(in.rdbuf());
// #endif

	int casos;
	std::cin >> casos;
	cin.get();
	for (int i = 0; i < casos; i++){
		resuelveCaso();
	}

// 	// restablecimiento de cin
// #ifndef DOMJUDGE
// 	std::cin.rdbuf(cinbuf);
// 	system("pause");
// #endif

	return 0;
}