#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


using namespace std;
#define MAX_N 100000
#define MAX_ESTUDIANTES_PAIS 1000000000

class argsException : public exception
{
	virtual const char* what() const throw()
	{
		return "El programa debe recibir un parametro por linea de comandos, que es el tamanio de los datos";
	}

	virtual const char* que() const throw()
	{
		return "[1, 100000]";
	}

} myex;
/*
Alvaro Abad de Donesteve

Generador de casos para el problema Erasm�s 242 de aceptaelreto
https://www.aceptaelreto.com/problem/statement.php?id=242

** argumento por linea de comandos : tamnio del caso [1, 100000]

*/
int main(int argc, char *argv[]) {
	int n;
	srand(time(0)); //seeds the rand() function
	LPSTR cl = GetCommandLineA();
	/*try
	{
		if (argc != 2)
			throw myex;
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}*/

	n = atoi(cl);
	//n = atoi(argv[1]);	
	ofstream file;
	file.open("casos.txt");
	if (n < 1 || n > MAX_N) {
		cout << "Error n out of range: [1, 100000]\n n = " << n;
		exit(-1);
	}

	file << n << '\n';

	for (int i = 0; i < n; i++) {
		int num = 1 + rand() % MAX_ESTUDIANTES_PAIS;
		file << num << " ";
	}
	file << '\n' << 0;

	return 0;
}
