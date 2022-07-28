/////////////////////////////////////////
// cases generator and time chrono for 349 problem in aceptaelreto.com (jan el olvidado)
// https://www.aceptaelreto.com/problem/statement.php?id=349
// Linux version
//	O (2^N)
// Alvaro Abad de Donesteve

// Entrada tipo: 
// num casos
// caso 1
// caso 2
// ...
// caso n
////////////////////////////////////////////


#include "../../utils.h"
#include <vector>


using namespace std;
using namespace std::chrono;


#define MIN_CASOS 1
#define MAX_CASE_SIZE 21474836	//int c++ range
#define MAX_DATO 21474836
#define OBSERVATIONS 3		//lo casos prefabricados de los que dispongo para este problma
#define REPETITIONS 10	//for decrease the process creation noise, each case is being repeated to stablish an average time measure


template <std::size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == nullptr));

  return execvp(file, const_cast<char* const*>(argv));
}

/*
para cada observacion o tamanio del problema
	generar caso tamanio n
		escribir datos en casos.txt
	ejecutar erasmus.exe
	escribir tiempo de ejecucion en el .csv
fin
*/

int main(int argc, char* argv[] )
{
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	string observations[OBSERVATIONS] = { "+ 3 4", "/ - 3 4 + 5 2", "+ * - / * 8 7 2 * + 7 5 4 3 1"};
	// string observations[OBSERVATIONS] = { "+ 3 4", "- 3 * 4 5", "* + 3 4 5", "/ - 3 4 + 5 2", "+ * - / * 8 7 2 * + 7 5 4 3 1"};
	int tamanios[OBSERVATIONS] = {1, 3, 7};
	// int tamanios[OBSERVATIONS] = {1, 2, 2, 3, 7};

	try{
		csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		for(int i = 0; i < OBSERVATIONS-1; i++ )	
			csvFile << "N,seconds,";

		if (argc > 1 && std::string(argv[1]) == "-t"){
			csvFile << "N,seconds,tipo\n";
		}
	
		else
			csvFile << "N,seconds\n";
		
		

	// 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++) {	
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		currentN = tamanios[i];
		casosFile << REPETITIONS << "\n";
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function
		int num;
		
		// generating data of current case
		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << observations[i];
			if (k < REPETITIONS -1)
				casosFile << "\n";
		}
		casosFile.close();
		// fork a child process to execute erasmus.exe
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"olvidado.exe", nullptr};
			if (execvp("./olvidado.exe", argx ) == -1)
				exit(EXIT_FAILURE);
		} else {
			std::cout << std::fixed << std::setprecision(9) << std::left;
			auto start = steady_clock::now();

			if ((pid = wait(&status)) == -1)
				exit(EXIT_FAILURE);
			else{
				auto end = steady_clock::now();
				std::chrono::duration<double> diff = end - start;
				cout << "i = " << i + 1 << " | N = " << currentN << " | seconds = " << std::setw(9) << diff.count() << '\n';
				cout << "--------------------------------------------\n";
				cout << "--------------------------------------------\n";

				csvFile << currentN << "," << diff.count() / REPETITIONS;
				if (i < OBSERVATIONS-1)
					csvFile << ",";
				
			}
			casosFile.close();
		}

	}
		if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< DOSN;
	csvFile.close();
	return 0;
}

/*N = 1
i = 1 | N = 1 | seconds = 0.017696300
--------------------------------------------
--------------------------------------------
N = 2
i = 2 | N = 2 | seconds = 0.015498200
--------------------------------------------
--------------------------------------------
N = 2
i = 3 | N = 2 | seconds = 0.013414200
--------------------------------------------
--------------------------------------------
N = 3
i = 4 | N = 3 | seconds = 0.015512600
--------------------------------------------
--------------------------------------------
N = 7
i = 5 | N = 7 | seconds = 0.012875200
--------------------------------------------
--------------------------------------------

No se aprecia ningun cambio
*/


    // meter a mano los casos del ejemplo y medirlos