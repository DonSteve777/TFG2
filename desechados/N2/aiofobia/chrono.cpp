/////////////////////////////////////////
// cases generator and time chrono for 357 problem in aceptaelreto.com (el problema pintando fractales)
// https://www.aceptaelreto.com/problem/statement.php?id=167
// Linux version
//	O (log N)
// Alvaro Abad de Donesteve

// 3 observaciones

// entrada tipo:
// 3
// 49
// 22
////////////////////////////////////////////

#include "../../utils.h"
#include <string.h>

#define MIN_CASOS 1
#define MAX_DATO 1000
#define OBSERVATIONS 3
#define REPETITIONS 10	//for decrease the process creation noise, each case is being repeated to stablish an average time measure


template <std::size_t N>
int execvp(const char* file, const char* const (&argv)[N])
{
  assert((N > 0) && (argv[N - 1] == nullptr));

  return execvp(file, const_cast<char* const*>(argv));
}


int main(int argc, char* argv[] )
{
	int observaciones, status;
	long long currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	string palindromo = "reconor";
	int observations[OBSERVATIONS] = {2, 50, 100 };

	try{
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile.open("tiemposT.csv", std::ofstream::trunc);
		else
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
		currentN = (observations[i] * MAX_DATO) / 100;
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function

		string entrada = i == 0 ? "ab" : palindromo;  // primer caso con tamanio 2 para que haya mas diferencia

		while (entrada.size() < currentN){
			entrada+= palindromo;
		}

		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << entrada << "\n";
		}
		cout << "entrada escrita\n";
		casosFile.close();
		// fork a child process to execute erasmus.exe
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"425.exe", nullptr};
			if (execvp("./425.exe", argx ) == -1)
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
				csvFile << currentN << "," << diff.count() / REPETITIONS;
				if (i < OBSERVATIONS-1)
					csvFile << ",";
			}
		}
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< N2;
	csvFile.close();
	return 0;
}

/*
Desde el hp: coherente
N = 2
entrada escrita
1
1
1
1
1
1
1
1
1
1
sh: 1: PAUSE: not found
i = 1 | N = 2 | seconds = 0.181704600
--------------------------------------------
--------------------------------------------
N = 50
entrada escrita
16
16
16
16
16
16
16
16
16
16
sh: 1: PAUSE: not found
i = 2 | N = 50 | seconds = 0.121306900
--------------------------------------------
--------------------------------------------
N = 100
entrada escrita
30
30
30
30
30
30
30
30
30
30
sh: 1: PAUSE: not found
i = 3 | N = 100 | seconds = 0.129080500
--------------------------------------------
--------------------------------------------

DESDE EL DELL

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000633245
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000628673
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.009334217
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.007910171
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000630193
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000613317
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000639607
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000621316
--------------------------------------------
--------------------------------------------

N = 50
entrada escrita
i = 1 | N = 50 | seconds = 0.000623045
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000713775
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000731011
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000766573
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000776778
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.004714110
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000728159
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000782394
--------------------------------------------
--------------------------------------------

N = 99
entrada escrita
i = 1 | N = 99 | seconds = 0.000720222
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.000665074
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.000706860
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.001828161
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.003057504
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.000685061
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.008275178
--------------------------------------------
--------------------------------------------

N = 10
entrada escrita
i = 1 | N = 10 | seconds = 0.000694190
--------------------------------------------
--------------------------------------------


N = 2
entrada escrita
i = 1 | N = 2 | seconds = 0.004666822
--------------------------------------------
--------------------------------------------

N = 2
entrada escrita
i = 1 | N = 2 | seconds = 0.000704842
--------------------------------------------
--------------------------------------------

N = 2
entrada escrita
i = 1 | N = 2 | seconds = 0.004667800
--------------------------------------------
--------------------------------------------

N = 2
entrada escrita
i = 1 | N = 2 | seconds = 0.000689678
--------------------------------------------
--------------------------------------------

N = 2
entrada escrita
i = 1 | N = 2 | seconds = 0.000732722
--------------------------------------------
--------------------------------------------

*/
