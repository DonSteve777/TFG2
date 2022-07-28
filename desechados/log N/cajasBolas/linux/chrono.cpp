/////////////////////////////////////////
// cases generator and time chrono for 357 problem in aceptaelreto.com (el problema de las cajas y las bolas)
// https://www.aceptaelreto.com/problem/statement.php?id=357
// Linux version
//	O (log N)
// Alvaro Abad de Donesteve

// entrada tipo:
// 3
// 49
// 22
////////////////////////////////////////////
#include "../../../utils.h"

#define MIN_CASOS 1
#define MAX_DATO 1000000000
#define OBSERVATIONS 3
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
	int observaciones, status;
	long long currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	int observations[OBSERVATIONS] = { 1,  50, 99};
	// int observations[OBSERVATIONS] = { 1, 30, 50, 70, 99};

	try{
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile.open("tiemposT.csv", std::ofstream::trunc);
		else
			csvFile.open("tiempos.csv", std::ofstream::trunc);

		for(int i = 0; i < OBSERVATIONS-1; i++ )
			csvFile << "N,seconds,";
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile << "N,seconds,tipo\n";
		else
			csvFile << "N,seconds\n";
		
	// 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++) {
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		currentN = (long long) ((long long)observations[i] * MAX_DATO) / 100;
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function
		casosFile << currentN << "\n";
		casosFile.close();

		for (int k = 0; k < REPETITIONS; k++) {
			// fork a child process to execute erasmus.exe	
			pid_t pid = fork();		
			if (pid == -1) {
				exit(EXIT_FAILURE);	//ERROR
			} else if (pid == 0) {
				const char* const argx[] = {"357.exe", nullptr};
				if (execvp("./357.exe", argx ) == -1)
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
					csvFile << currentN << "," << diff.count();
					if (i < OBSERVATIONS-1)
						csvFile << ",";
				}
			}	
		}	
		
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< LOGN;
	csvFile.close();
	return 0;
}

/*Resultados inservibles, dispares, sin relacion tamanio - tiempo
N = 10000000
i = 1 | N = 10000000 | seconds = 0.001295900
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001989600
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001543900
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001686700
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001123200
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.000865000
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001070000
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.002087100
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.000775700
--------------------------------------------
--------------------------------------------
i = 1 | N = 10000000 | seconds = 0.001157400
--------------------------------------------
--------------------------------------------
N = 500000000
i = 2 | N = 500000000 | seconds = 0.001458700
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.002414500
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.001523000
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.000903700
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.001172600
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.001703500
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.001153700
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.000958500
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.000884500
--------------------------------------------
--------------------------------------------
i = 2 | N = 500000000 | seconds = 0.000863200
--------------------------------------------
--------------------------------------------
N = 990000000
i = 3 | N = 990000000 | seconds = 0.002133600
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001235300
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001656500
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001151300
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.003090300
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001753900
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.002309400
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001637700
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001073700
--------------------------------------------
--------------------------------------------
i = 3 | N = 990000000 | seconds = 0.001248900
--------------------------------------------
--------------------------------------------

*/
