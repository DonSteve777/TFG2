/////////////////////////////////////////
// cases generator and time chrono for 242 problem in aceptaelreto.com (Erasmus)
// Linux version
//	O (N)
// Alvaro Abad de Donesteve
////////////////////////////////////////////



#include "../../../utils.h"


#define MIN_CASOS 1
#define MAX_CASOS 100000	// N [1, 100 000], segun enunciado del problema erasmus
#define MAX_DATO 1000000000
#define MAX_INT	 2147483647
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
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	// int observations[OBSERVATIONS] = { 1, 30, 50, 70, 99};
	int observations[OBSERVATIONS] = { 1, 50, 99};

	try{
		csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
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
		// currentN = (long long) (observations[i] * MAX_CASOS) / 100;
		currentN =  (observations[i] * MAX_CASOS) / 100;
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function

		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << currentN << "\n";
			long long num;
			for (int j = 0; j < currentN; j++) {
				num = 1 + rand() % MAX_DATO;
				casosFile << num << " ";
			}
			casosFile << "\n";
		}	
		casosFile << "\n0";
		casosFile.close();
		// fork a child process to execute erasmus.exe	
		pid_t pid = fork();		
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"erasmus.exe", nullptr};
			if (execvp("./erasmus.exe", argx ) == -1)
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
				csvFile << currentN << "," << diff.count() / REPETITIONS ;
				if (i < OBSERVATIONS-1)
					csvFile << ",";
			}
		}	
		
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< N;
	csvFile.close();
	return 0;
}

/*Resultados bastante razonables, y con creacion de proceso diluida con 10 repeticiones

N = 1000
i = 1 | N = 1000 | seconds = 0.033652000
--------------------------------------------
--------------------------------------------
N = 30000
i = 2 | N = 30000 | seconds = 0.084338700
--------------------------------------------
--------------------------------------------
N = 50000
i = 3 | N = 50000 | seconds = 0.148847500
--------------------------------------------
--------------------------------------------
N = 70000
i = 4 | N = 70000 | seconds = 0.216207200
--------------------------------------------
--------------------------------------------
N = 99000
i = 5 | N = 99000 | seconds = 0.300448800
--------------------------------------------
--------------------------------------------
*/