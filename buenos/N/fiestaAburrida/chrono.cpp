/////////////////////////////////////////
// cases generator and time chrono for 117 problem in aceptaelreto.com (FIesta aburrida)
// https://www.aceptaelreto.com/problem/statement.php?id=117
// Linux C++ version 
//	O (N)

// Entrada tipo: 
// num casos
// caso 1
// caso 2
// ...
// caso n
////////////////////////////////////////////

#include <cassert>
#include <cstring>
#include <numeric>
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>


using namespace std;
using namespace std::chrono;

#define MIN_CASOS 1
#define MAX_CASE_SIZE 21474836	//int c++ range
#define MAX_DATO 21474836
#define OBSERVATIONS 5		//lo casos prefabricados de los que dispongo para este problma
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

int main()
{
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	string observations[OBSERVATIONS] = { "Soy Lotario", "Soy Aldonza", "Soy Ender", "Soy alvaroabaddedonestevejimenezvelazquezgaztelu", "Soy Thanos"};
	int tamanios[OBSERVATIONS] = {1, 2, 2, 3, 7};

	try{
		csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		for(int i = 0; i < OBSERVATIONS-1; i++ )
			csvFile << "N,seconds,";
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
			// wait until erasmus.exe ends and finding out how much time a erasmus takes
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
				csvFile << currentN << "," << diff.count() / REPETITIONS << ',';
			}
			casosFile.close();
		}

	}
	csvFile.close();
	return 0;
}


    // meter a mano los casos del ejemplo y medirlos