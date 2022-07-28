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

#include "/mnt/c/Users/alvar/xXx/ML/repoTFG/utils.h"
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
	string palindromo = "MERODEADOR";
	double observations[OBSERVATIONS] = {0.1, 0.5, 0.99 };

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
		currentN = (int) (observations[i]*MAX_DATO);
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function

		string entrada = palindromo;

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
			const char* const argx[] = {"322.exe", nullptr};
			if (execvp("./322.exe", argx ) == -1)
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