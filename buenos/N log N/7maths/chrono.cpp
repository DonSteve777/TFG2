/////////////////////////////////////////
// cases generator and time chrono for mergesort (not in aceptaelreto.com)
// Linux version
//	O (log N)
// Alvaro Abad de Donesteve

// formato entrada:
// num casos
// tam caso
// dato1 dato2 ... dato n
	// 2
	// 3
	// 1 2 3
	// 4
	// 1 2 3 4

////////////////////////////////////////////
#include "/mnt/c/Users/alvar/xXx/ML/repoTFG/utils.h"

#define MIN_CASOS 1
//#define MAX_CASE_SIZE 21474836	//int c++ range
#define MAX_CASE_SIZE 214748	//int c++ range
#define MAX_DATO 21474836
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
	int observaciones, status, currentN;
	std::ofstream csvFile, casosFile;
	currentN = MIN_CASOS;

//data sizes , (percents of max N)
	// int observations[OBSERVATIONS] = { 1, 30, 50, 70, 99};
	int observations[OBSERVATIONS] = { 10, 50, 99};

	try{
		csvFile.open("tiempos.csv", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		for(int i = 0; i < OBSERVATIONS-1; i++ )
			csvFile << "N,seconds,";
		if (argc > 1 && std::string(argv[1]) == "-t")
			csvFile << "N,seconds,tipo\n";
		else
			csvFile << "N,seconds\n";	// 1. g

	// 1. generar caso de tamanio n, y escribirlo en casos.txt
	}
	catch(std::ofstream::failure e){
		cout << " Error opening file";
	}

	for (int i = 0; i < OBSERVATIONS; i++) {
		casosFile.open("casos.txt", std::ofstream::trunc);	//If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
		currentN = (int) (observations[i] * MAX_CASE_SIZE) / 100;
		casosFile << REPETITIONS << "\n";
		cout << "N = " << currentN << "\n";
		srand(time(0)); //seeds the rand() function
		int num;
		
		// generating data of current case
		for (int k = 0; k < REPETITIONS; k++) {
			casosFile << currentN << "\n";
			for (int j = 0; j < currentN; j++){
				num = 1 + rand() % MAX_DATO;
				casosFile << num << " ";
			}
			casosFile << "\n";
		}
		casosFile.close();
		pid_t pid = fork();
		if (pid == -1) {
			exit(EXIT_FAILURE);	//ERROR
		} else if (pid == 0) {
			const char* const argx[] = {"mergesort.exe", nullptr};
			if (execvp("./mergesort.exe", argx ) == -1)
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
		}	
		
	}
	if (argc > 1 && std::string(argv[1]) == "-t")
		csvFile << ","<< NLOGN;
	csvFile.close();
	return 0;
}